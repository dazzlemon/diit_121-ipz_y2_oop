package oop13;

import java.util.ArrayList;
import java.util.List;

public class Matrix <T> {
	public final int width;
	public final int height;
	private List<List<T>> matrix;

	public Matrix(int height, int width) {
		this.width  = width;
		this.height = height;
		
		this.matrix = new ArrayList<>(height);
		for (int i = 0; i < height; i++) {
			this.matrix.set(i, new ArrayList<>(width));
		}
	}

	public void set(int i, int j, T val) {
		this.matrix[i][j] = val;
	}

	public T get(int i, int j) {
		return this.matrix.get(i).get(j);
	}

	public void swapRows(int idx1, int idx2) {
		//
	}

	public void swapColumns(int idx1, int idx2) {
		//
	}
}
