package com.dazzlemon.oop14;

import javax.swing.event.TableModelListener;
import javax.swing.table.TableModel;

public class MatrixTableModel implements TableModel {
    public Matrix<Integer> matrix;
    
    
    public MatrixTableModel(int w, int h, int fill) {
        matrix = new Matrix<>(w, h, fill);
    }
    
    
    public void resize(int w, int h, int fill) {
        matrix = new Matrix<>(w, h, fill);
    }
    
            
    @Override
    public int getRowCount() {
        return matrix.height;
    }

    
    @Override
    public int getColumnCount() {
        return matrix.width;
    }

    
    @Override
    public String getColumnName(int i) {
        return "";
    }

    
    @Override
    public Class<?> getColumnClass(int i) {
        return matrix.getClass();
    }

    
    @Override
    public boolean isCellEditable(int i, int i1) {
        return true;
    }

    
    @Override
    public Object getValueAt(int i, int i1) {
        return matrix.get(i, i);
    }

    
    @Override
    public void setValueAt(Object o, int i, int i1) {
        matrix.set(i, i1, Integer.parseInt(o.toString()));
    }

    
    @Override
    public void addTableModelListener(TableModelListener tl) {
        
    }

    
    @Override
    public void removeTableModelListener(TableModelListener tl) {

    }
}
