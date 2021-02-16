package oop13;

import java.awt.Point;

public class Main {
	public static final String ANSI_GREEN_BACKGROUND = "\u001B[42m";
	public static final String ANSI_CYAN_BACKGROUND = "\u001B[46m";
	public static final String ANSI_LIGHT_CYAN_BACKGROUND = "\u001B[106m";
	public static final String ANSI_YELLOW_BACKGROUND = "\u001B[43m";
	public static final String ANSI_LIGHT_YELLOW_BACKGROUND = "\u001B[103m";
	public static final String ANSI_RESET = "\u001B[0m";
	
	public static void main(String[] args) {
		var matrix = new Matrix<Integer>(5, 10, 0);
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				matrix.set(i, j, i * matrix.width + j);
			}
		}
		
		var zero = new Point(0, 0);
		var indices = Solver.solve(matrix);
		
		var x = indices.x;
		var y = indices.y;

		print(matrix, indices, zero);
		System.out.println();
				
		Solver.swapRows(matrix, 0, x);
		Solver.swapColumns(matrix, 0, y);
		print(matrix, indices, zero);
	}

	public static <T> void print(Matrix<T> matrix, Point pMax, Point p) {
		var x = pMax.x;
		var y = pMax.y;

		var maxLen = String.valueOf(matrix.get(x, y)).length();

		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				var color = ((i == x || j == y) && (i == p.x || j == p.y)) ? ANSI_GREEN_BACKGROUND
				          :  (i == x && j == y)                            ? ANSI_CYAN_BACKGROUND
				          :  (i == x || j == y)                            ? ANSI_LIGHT_CYAN_BACKGROUND
				          :  (i == p.x && j == p.y)                        ? ANSI_YELLOW_BACKGROUND
				          :  (i == p.x || j == p.y)                        ? ANSI_LIGHT_YELLOW_BACKGROUND
				                                                           : ANSI_RESET;
				System.out.printf(color + "%" + maxLen + "d ", matrix.get(i, j));
			}
			System.out.println(ANSI_RESET);
		}
	}
}
