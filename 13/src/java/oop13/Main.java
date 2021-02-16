package oop13;

public class Main {
	public static final String ANSI_CYAN_BACKGROUND = "\u001B[46m";
	public static final String ANSI_BLUE_BACKGROUND = "\u001B[44m";
	public static final String ANSI_BLACK_BACKGROUND = "\u001B[40m";
	
	public static void main(String[] args) {
		var matrix = new Matrix<Integer>(5, 10, 0);
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				matrix.set(i, j, i * matrix.width + j);
			}
		}
		
		var indices = Solver.solve(matrix);
		var x = indices.x;
		var y = indices.y;

		var maxLen = String.valueOf(matrix.get(x, y)).length();

		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				if (i == x && j == y) {
					System.out.printf(ANSI_BLUE_BACKGROUND + "%" + maxLen + "d ", matrix.get(i, j));
				} else if (i == x || j == y) {
					System.out.printf(ANSI_CYAN_BACKGROUND + "%" + maxLen + "d ", matrix.get(i, j));
				} else {
					System.out.printf(ANSI_BLACK_BACKGROUND + "%" + maxLen + "d ", matrix.get(i, j));
				}
			}
			System.out.println(ANSI_BLACK_BACKGROUND);
		}
	}
}
