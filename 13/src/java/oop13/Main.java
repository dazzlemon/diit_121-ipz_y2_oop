package oop13;

import java.awt.Point;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		var in = new Scanner(System.in);

		System.out.print("Input matrix' height: ");
		var h = in.nextInt();

		System.out.print("Input matrix' width: ");
		var w = in.nextInt();

		var in2 = new Scanner(System.in);
		System.out.print("Would you like to fill matrix yourself(Y - yourself, any other input - random): ");
		var choice = in2.next();

		var matrix = new Matrix<Integer>(h, w, 0);
		
		if (choice.compareTo("Y") == 0) {
			MatrixIO.read(matrix);
		} else {
			MatrixIO.randFill(matrix);
		}

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
