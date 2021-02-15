package oop13;

import java.util.ArrayList;
import java.util.List;

public class Matrix <T> {
	public final int width;
	public final int height;
	private List<List<T>> matrix;

	public Matrix(int height, int width, T filler) {
		this.height = height;
		this.width  = width;
		
		this.matrix = new ArrayList<>(height);
		for (int i = 0; i < height; i++) {
			this.matrix.add(i, new ArrayList<>(width));
			for (int j = 0; j < width; j++) {
				this.matrix.get(i).add(filler);
			}
		}
	}

	public void set(int i, int j, T val) {
		this.matrix.get(i).set(j, val);
	}

	public T get(int i, int j) {
		return this.matrix.get(i).get(j);
	}
}
