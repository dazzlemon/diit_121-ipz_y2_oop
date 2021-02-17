package oop13;

import java.awt.Point;
import java.util.Random;
import java.util.Scanner;

public class MatrixIO {
	public static final String ANSI_GREEN_BACKGROUND = "\u001B[42m";
	public static final String ANSI_CYAN_BACKGROUND = "\u001B[46m";
	public static final String ANSI_LIGHT_CYAN_BACKGROUND = "\u001B[106m";
	public static final String ANSI_YELLOW_BACKGROUND = "\u001B[43m";
	public static final String ANSI_LIGHT_YELLOW_BACKGROUND = "\u001B[103m";
	public static final String ANSI_RESET = "\u001B[0m";

	public static void read(Matrix<Integer> matrix) {
		var in = new Scanner(System.in);
		var maxLenI = digitsN(matrix.height - 1);
		var maxLenJ = digitsN(matrix.width - 1);
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				System.out.printf("matrix[%" + maxLenI +  "d][" + "%" + maxLenJ + "d] = ", i, j);
				matrix.set(i, j, in.nextInt());
			}
		}
	}

	public static void randFill(Matrix<Integer> matrix) {
		var r = new Random();
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				matrix.set(i, j, r.nextInt(100));
			}
		}
	}

	public static void print(Matrix<Integer> matrix, Point pMax, Point p) {
		var x = pMax.x;
		var y = pMax.y;

		var maxLen = digitsN(matrix.get(x, y));

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

	public static int digitsN(int x) {
		return String.valueOf(x).length();
	}
}
