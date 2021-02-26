
import java.io.File;
import java.io.IOException;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author dazzlemon
 */
public class MatrixGui extends javax.swing.JFrame {

    /**
     * Creates new form MatrixGui
     */
    public MatrixGui() {
        initComponents();
        //
        updateTable();
        //
    }
    
    private void updateTable() {
        var m = new Integer[matrix.height][matrix.width];
        for (int i = 0; i < matrix.height; i++) {
            m[i] = new Integer[matrix.width];
            for (int j = 0; j < matrix.width; j++) {
                m[i][j] = matrix.get(i, j);
            }
        }
       
        var names = new String[matrix.width];
        for (int j = 0; j < matrix.width; j++) {
            names[j] = String.valueOf(j);
        }
        table.setModel(new javax.swing.table.DefaultTableModel(m, names));
        table.setShowGrid(true);
        table.setTableHeader(null);
        jScrollPane1.setViewportView(table);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        sortButton = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        table = new javax.swing.JTable();
        resizeButton = new javax.swing.JButton();
        rowsText = new javax.swing.JTextField();
        columnsText = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        saveButton = new javax.swing.JButton();
        loadButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        sortButton.setText("sort");
        sortButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sortButtonActionPerformed(evt);
            }
        });

        table.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {

            }
        ));
        table.setShowGrid(true);
        table.getTableHeader().setReorderingAllowed(false);
        jScrollPane1.setViewportView(table);

        resizeButton.setText("resize");
        resizeButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                resizeButtonActionPerformed(evt);
            }
        });

        rowsText.setText("4");

        columnsText.setText("4");
        columnsText.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                columnsTextActionPerformed(evt);
            }
        });

        jLabel1.setText("rows");

        jLabel2.setText("columns");

        saveButton.setText("save");
        saveButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveButtonActionPerformed(evt);
            }
        });

        loadButton.setText("load");
        loadButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                loadButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 192, Short.MAX_VALUE)
                .addGap(6, 6, 6)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(saveButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(loadButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(resizeButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(jLabel2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(columnsText, javax.swing.GroupLayout.DEFAULT_SIZE, 43, Short.MAX_VALUE)
                            .addComponent(rowsText)))
                    .addComponent(sortButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(0, 107, Short.MAX_VALUE)
                        .addComponent(loadButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(saveButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel1)
                            .addComponent(rowsText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(columnsText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(resizeButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(sortButton)))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void sortButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sortButtonActionPerformed
        for (int i = 0; i < matrix.height; i++) {
            for (int j = 0; j < matrix.width; j++) {
                var mij = Integer.parseInt(table
                                          .getModel()
                                          .getValueAt(i, j)
                                          .toString());
                matrix.set(i, j, mij);
            }
        }
        
        var indices = com.dazzlemon.oop15.Solver.solve(matrix);
	var x = indices.x;
	var y = indices.y;			
        
        com.dazzlemon.oop15.Solver.swapRows(matrix, 0, x);
	com.dazzlemon.oop15.Solver.swapColumns(matrix, 0, y);
        
        updateTable();
    }//GEN-LAST:event_sortButtonActionPerformed

    private void columnsTextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_columnsTextActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_columnsTextActionPerformed

    private void resizeButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_resizeButtonActionPerformed
        int w = Integer.parseInt(columnsText.getText());
        int h = Integer.parseInt(rowsText.getText());
        var newMatrix = new com.dazzlemon.oop15.Matrix<>(h, w, 0);
        for (int i = 0; i < h && i < matrix.height; i++) {
            for (int j = 0; j < w && j < matrix.width; j++) {
                var mij = Integer.parseInt(table
                                          .getModel()
                                          .getValueAt(i, j)
                                          .toString());
                newMatrix.set(i, j, mij);
            }
        }
        matrix = newMatrix;
        updateTable();
    }//GEN-LAST:event_resizeButtonActionPerformed

    private void saveButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveButtonActionPerformed
        System.out.println("save clicked");
        var file = getFile("save");
        if (file == null) {
            return;
        }
        if (!file.getName().endsWith(".txt")) {
            JOptionPane.showMessageDialog(new JFrame(), "INCORRECT FILE EXTENSION!", "Dialog", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if (!file.exists()) {
            try {
                file.createNewFile();
            } catch (IOException e) {
                JOptionPane.showMessageDialog(new JFrame(), "ERROR OCCURED WHILE CREATING FILE!", "Dialog", JOptionPane.ERROR_MESSAGE);
                return;
            }
        }
        if (!file.canWrite()) {
            JOptionPane.showMessageDialog(new JFrame(), "CAN\'T WRITE TO THAT FILE!", "Dialog", JOptionPane.ERROR_MESSAGE);
            return;
        }
        System.out.println("saved to: " + file.getAbsolutePath());
    }//GEN-LAST:event_saveButtonActionPerformed

    private void loadButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_loadButtonActionPerformed
        System.out.println("load clicked");
        var file = getFile("load");
        /*if (!) {
            JOptionPane.showMessageDialog(new JFrame(), "FILE DOESN'T EXIST!", "Dialog", JOptionPane.ERROR_MESSAGE);
        }*/
    }//GEN-LAST:event_loadButtonActionPerformed

    
    private File getFile(String text) {
        var j = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
        var f = new FileNameExtensionFilter("txt", "txt");
        j.setFileFilter(f);
        j.setAcceptAllFileFilterUsed(false);
        var r = j.showDialog(null, text);
        if (r == JFileChooser.APPROVE_OPTION) {
            return j.getSelectedFile();
        }
        return null;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(MatrixGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MatrixGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MatrixGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MatrixGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        
        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MatrixGui().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField columnsText;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton loadButton;
    private javax.swing.JButton resizeButton;
    private javax.swing.JTextField rowsText;
    private javax.swing.JButton saveButton;
    private javax.swing.JButton sortButton;
    public javax.swing.JTable table;
    // End of variables declaration//GEN-END:variables
    // My Variables
    private com.dazzlemon.oop15.Matrix<Integer> matrix = new com.dazzlemon.oop15.Matrix<Integer>(4, 4, 0);
    // End of my variables
}
