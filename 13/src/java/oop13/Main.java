package oop13;

import java.awt.Point;

public class Main {
		public static void main(String[] args) {
		var matrix = new Matrix<Integer>(5, 10, 0);
		MatrixIO.randFill(matrix);

		var zero = new Point(0, 0);
		var indices = Solver.solve(matrix);
		
		var x = indices.x;
		var y = indices.y;

		MatrixIO.print(matrix, indices, zero);
		System.out.println();
				
		Solver.swapRows(matrix, 0, x);
		Solver.swapColumns(matrix, 0, y);
		MatrixIO.print(matrix, zero, indices);
	}	
}
