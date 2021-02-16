package oop13;

import java.awt.Point;

public class Solver {
		public static <T extends Comparable<T>> Point solve(Matrix<T> matrix) {
		int imax = 0;
		int jmax = 0;
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				if (matrix.get(i, j).compareTo(matrix.get(imax, jmax)) > 0) {
					imax = i;
					jmax = j;
				}
			}
		}
		return new Point(imax, jmax);
	}
}
