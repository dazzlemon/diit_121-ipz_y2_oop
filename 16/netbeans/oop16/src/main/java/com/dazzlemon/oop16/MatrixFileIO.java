package com.dazzlemon.oop16;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MatrixFileIO {
    public static void matrixSave(Matrix<Integer> matrix, File file)
            throws IOException {
        var fw = new FileWriter(file);
        //write size (rows cols)
        var buffer = "%d %d\n"
                      . formatted(matrix.height, matrix.width);
        fw.write(buffer);
        //write elements
        for (int i = 0; i < matrix.height; i++) {
            for (int j = 0; j < matrix.width; j++) {
                buffer = "%d "
                       . formatted(matrix.get(i, j));
                fw.write(buffer);
            }
            fw.append('\n');
        }
        fw.flush();
    }
    
    
    public static Matrix<Integer> matrixLoad(File file)
            throws IOException, Exception {
        var br = new BufferedReader(new FileReader(file));
        var line = br.readLine();
        var words = line.split("\\s");
        if (words.length != 2) {
            throw new Exception("incorrect amount tokens on size line");
        }
        var h = Integer.parseInt(words[0]);
        var w = Integer.parseInt(words[1]);
        var matrix = new Matrix<Integer>(h, w, 0);
        for (int i = 0; i < h; i++) {
            line = br.readLine();
            if (line == null) {
                throw new Exception(
                    "incorrect amount of lines: %d instead of %d"
                        .formatted(i, h)
                );
            }
            words = line.split("\\s");
            if (words.length != w) {
                throw new Exception(
                    "incorrect amount of elements on line " + (i + 1)
                );
            }
            for (int j = 0; j < w; j++) {
                var mij = Integer.parseInt(words[j]);
                matrix.set(i, j, mij);
            }
        }
        if (br.ready()) {
            throw new Exception("too many lines");
        }
        return matrix;
    }
}
