package oop13;

public class Main {
	public static void main(String[] args) {
		var matrix = new Matrix<Integer>(4, 3, 0);
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				matrix.set(i, j, i + j);
			}
		}

		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				System.out.print(matrix.get(i, j) + " ");
			}
			System.out.println();
		}
	}
}
