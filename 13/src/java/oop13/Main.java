package oop13;

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
		
		var indices = Solver.solve(matrix);
		var x = indices.x;
		var y = indices.y;

		var maxLen = String.valueOf(matrix.get(x, y)).length();

		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				var color = ((i == x || j == y) && (i == 0 || j == 0)) ? ANSI_GREEN_BACKGROUND
				          :  (i == x && j == y)                        ? ANSI_CYAN_BACKGROUND
				          :  (i == x || j == y)                        ? ANSI_LIGHT_CYAN_BACKGROUND
				          :  (i == 0 && j == 0)                        ? ANSI_YELLOW_BACKGROUND
				          :  (i == 0 || j == 0)                        ? ANSI_LIGHT_YELLOW_BACKGROUND
				                                                       : ANSI_RESET;
				System.out.printf(color + "%" + maxLen + "d ", matrix.get(i, j));
			}
			System.out.println(ANSI_RESET);
		}
	}
}
