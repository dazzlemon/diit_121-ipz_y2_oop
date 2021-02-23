package com.dazzlemon.oop14;

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
	
    public static <T> void swapRows(Matrix<T> matrix, int i1, int i2) {
        for (int j = 0; j < matrix.width; j++) {
            var tmp = matrix.get(i1, j);
            matrix.set(i1, j, matrix.get(i2, j));
            matrix.set(i2, j, tmp);
	}
    }
	
    public static <T> void swapColumns(Matrix<T> matrix, int j1, int j2) {
        for (int i = 0; i < matrix.height; i++) {
            var tmp = matrix.get(i, j1);
            matrix.set(i, j1, matrix.get(i, j2));
            matrix.set(i, j2, tmp);
	}
    }
}