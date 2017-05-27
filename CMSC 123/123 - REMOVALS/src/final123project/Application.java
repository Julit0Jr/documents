package final123project;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JOptionPane;

public class Application extends javax.swing.JFrame {
    Graph g;
    boolean leastStop;
    boolean leastTrans;
  
    public Application() {
        initComponents();
        try {
            g = new Graph();
        } catch (Exception ex) {
            Logger.getLogger(Application.class.getName()).log(Level.SEVERE, null, ex);
        }
        this.setLocationRelativeTo(null);
        ArrayList<String> ar = Generatefromfiles.LANDMARKS;
        System.out.println(ar.size());
        Collections.sort(ar);
        for(String s : ar){
            origList.addItem(s);
            destList.addItem(s);
            avoidList.addItem(s);
            stopList.addItem(s);
        }
    }
    
  @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        jPanel1 = new javax.swing.JPanel();
        origList = new javax.swing.JComboBox<String>();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        destList = new javax.swing.JComboBox<String>();
        jLabel3 = new javax.swing.JLabel();
        stopList = new javax.swing.JComboBox<String>();
        jLabel4 = new javax.swing.JLabel();
        avoidList = new javax.swing.JComboBox<String>();
        lStopBtn = new javax.swing.JRadioButton();
        lTransBtn = new javax.swing.JRadioButton();
        okBtn = new javax.swing.JButton();
        origText = new javax.swing.JTextField();
        destText = new javax.swing.JTextField();
        avoidText = new javax.swing.JTextField();
        stopText = new javax.swing.JTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        outputScreen = new javax.swing.JTextArea();
        jLabel5 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        jPanel1.setToolTipText("dfasfd");

        origList.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                origListActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Dialog", 1, 16)); // NOI18N
        jLabel1.setText("ORIGIN");

        jLabel2.setFont(new java.awt.Font("Dialog", 1, 16)); // NOI18N
        jLabel2.setText("DESTINATION");

        destList.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                destListActionPerformed(evt);
            }
        });

        jLabel3.setFont(new java.awt.Font("Dialog", 1, 16)); // NOI18N
        jLabel3.setText("STOP");

        stopList.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "NONE" }));

        jLabel4.setFont(new java.awt.Font("Dialog", 1, 16)); // NOI18N
        jLabel4.setText("AVOID");

        avoidList.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "NONE" }));
        avoidList.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                avoidListActionPerformed(evt);
            }
        });

        buttonGroup1.add(lStopBtn);
        lStopBtn.setText("Least Stop");
        lStopBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                lStopBtnActionPerformed(evt);
            }
        });

        buttonGroup1.add(lTransBtn);
        lTransBtn.setText("Least Transfer");
        lTransBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                lTransBtnActionPerformed(evt);
            }
        });

        okBtn.setText("SHOW ROUTES");
        okBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                okBtnActionPerformed(evt);
            }
        });

        origText.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                origTextActionPerformed(evt);
            }
        });

        destText.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                destTextActionPerformed(evt);
            }
        });

        avoidText.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                avoidTextActionPerformed(evt);
            }
        });

        stopText.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                stopTextActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(destList, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(destText)
                    .addComponent(okBtn, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(origList, javax.swing.GroupLayout.Alignment.LEADING, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(stopList, javax.swing.GroupLayout.Alignment.LEADING, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(avoidList, javax.swing.GroupLayout.Alignment.LEADING, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(origText, javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(avoidText, javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel1Layout.createSequentialGroup()
                        .addComponent(lStopBtn)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 46, Short.MAX_VALUE)
                        .addComponent(lTransBtn))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 118, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel3)
                            .addComponent(jLabel4))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(stopText, javax.swing.GroupLayout.Alignment.LEADING))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(16, 16, 16)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(origText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(7, 7, 7)
                .addComponent(origList, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel2)
                .addGap(12, 12, 12)
                .addComponent(destText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(8, 8, 8)
                .addComponent(destList, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(stopText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(stopList, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel4)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(avoidText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(avoidList, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lStopBtn)
                    .addComponent(lTransBtn))
                .addGap(51, 51, 51)
                .addComponent(okBtn)
                .addGap(25, 25, 25))
        );

        outputScreen.setEditable(false);
        outputScreen.setColumns(20);
        outputScreen.setRows(5);
        outputScreen.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        outputScreen.setSelectionColor(new java.awt.Color(255, 255, 255));
        jScrollPane1.setViewportView(outputScreen);

        jLabel5.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel5.setText("RESULTS");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(14, 14, 14)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 411, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(174, 174, 174)
                        .addComponent(jLabel5)))
                .addContainerGap(158, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(16, 16, 16)
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel5)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane1)))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

  private void destListActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_destListActionPerformed
    // TODO add your handling code here:
  }//GEN-LAST:event_destListActionPerformed

  private void lStopBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_lStopBtnActionPerformed
    leastStop = true;
    leastTrans = false;
  }//GEN-LAST:event_lStopBtnActionPerformed

  private void lTransBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_lTransBtnActionPerformed
    leastTrans = true;
    leastStop = false;
  }//GEN-LAST:event_lTransBtnActionPerformed

  private void avoidListActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_avoidListActionPerformed
    // TODO add your handling code here:
  }//GEN-LAST:event_avoidListActionPerformed

  private void okBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_okBtnActionPerformed
    
    String orig = origList.getSelectedItem().toString();
    String dest = destList.getSelectedItem().toString();
    String stop = stopList.getSelectedItem().toString();
    String avoid = avoidList.getSelectedItem().toString();
    
    if(avoid.trim().equalsIgnoreCase(orig.trim()) && !avoid.trim().equals(dest.trim())){
        JOptionPane.showMessageDialog(this,"Place To Be Avoided Must Not Be The Origin!","Error", JOptionPane.ERROR_MESSAGE);
    } else if(avoid.trim().equalsIgnoreCase(dest.trim()) && !avoid.trim().equalsIgnoreCase(orig.trim())){
        JOptionPane.showMessageDialog(this,"Place To Be Avoided Must Not Be The Destination!","Error", JOptionPane.ERROR_MESSAGE);
    } else if(orig.equals(dest) && orig.equals(stop) && orig.equals(avoid)){
        JOptionPane.showMessageDialog(this,"Destination , Origin, Stop And Avoid Must Not Be The Same!","Error", JOptionPane.ERROR_MESSAGE);
    } else if(orig.trim().equalsIgnoreCase(dest.trim()) && stop.equalsIgnoreCase("NONE")){
        JOptionPane.showMessageDialog(this,"Destination Must Not Be The Origin!","Error", JOptionPane.ERROR_MESSAGE);
    } else if(orig.trim().equals(dest.trim()) && orig.trim().equals(stop.trim())){
        JOptionPane.showMessageDialog(this,"Destination , Origin And Stop Must Not Be The Same!","Error", JOptionPane.ERROR_MESSAGE);
    } else {
        origText.setText("");
        destText.setText("");
        avoidText.setText("");
        stopText.setText("");
        
        ArrayList<String> ar = Generatefromfiles.LANDMARKS;
        System.out.println(ar.size());
        Collections.sort(ar);
        for(String s : ar){
            origList.addItem(s);
            destList.addItem(s);
            avoidList.addItem(s);
            stopList.addItem(s);
        }

        if(stop.trim().equalsIgnoreCase("NONE")){
            outputScreen.setText("");
            if(leastStop){
                outputScreen.setText(g.leastStop(orig, dest, avoid));
            } else {
                outputScreen.setText(g.leastTransfer(orig, dest, avoid));
            }
            JOptionPane.showMessageDialog(this,"Operation Done Successfully!","Prompt", JOptionPane.INFORMATION_MESSAGE);
        } else {
          outputScreen.setText("");
        if(leastStop){
            outputScreen.setText(g.leastStop(orig, stop, avoid) + "\n");
            outputScreen.append(g.leastStop(stop, dest, avoid) + "\n");
        } else {
            outputScreen.setText(g.leastTransfer(orig, stop, avoid) + "\n");
            outputScreen.append(g.leastTransfer(stop, dest, avoid) + "\n");
        }
        JOptionPane.showMessageDialog(this,"Operation Done Successfully!","Prompt", JOptionPane.INFORMATION_MESSAGE);
      }
    }
  }//GEN-LAST:event_okBtnActionPerformed

  private void avoidTextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_avoidTextActionPerformed
    ArrayList<String> a = Generatefromfiles.LANDMARKS;
    ArrayList<String> filtered = new ArrayList<String>();
    for(String b : a){
        if(b.toLowerCase().replaceAll(" ", "").startsWith(avoidText.getText().toLowerCase().replaceAll(" ", "")))
            filtered.add(b); 
    }
    if(filtered.isEmpty())
          filtered.add("NONE");
    String[] ar = new String[filtered.size()];
    ar = filtered.toArray(ar);
    DefaultComboBoxModel model = new DefaultComboBoxModel(ar);
    avoidList.setModel(model);
  }//GEN-LAST:event_avoidTextActionPerformed

  private void destTextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_destTextActionPerformed
    ArrayList<String> a = Generatefromfiles.LANDMARKS;
    ArrayList<String> filtered = new ArrayList<String>();
    for(String b : a){
        if(b.toLowerCase().replaceAll(" ", "").startsWith(destText.getText().toLowerCase().replaceAll(" ", "")))
            filtered.add(b);
    } 
  
        String[] ar = new String[filtered.size()];
        ar = filtered.toArray(ar);
        DefaultComboBoxModel model = new DefaultComboBoxModel(ar);
        destList.setModel(model);
  }//GEN-LAST:event_destTextActionPerformed

  private void origTextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_origTextActionPerformed
    ArrayList<String> a = Generatefromfiles.LANDMARKS;
    ArrayList<String> filtered = new ArrayList<String>();
    for(String b : a){
        if(b.toLowerCase().replaceAll(" ", "").startsWith(origText.getText().toLowerCase().replaceAll(" ", "")))
            filtered.add(b);
    }
    String[] ar = new String[filtered.size()];
    ar = filtered.toArray(ar);
    DefaultComboBoxModel model = new DefaultComboBoxModel(ar);
    origList.setModel(model);
  }//GEN-LAST:event_origTextActionPerformed

  private void stopTextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_stopTextActionPerformed
    ArrayList<String> a = Generatefromfiles.LANDMARKS;
    ArrayList<String> filtered = new ArrayList<String>();
    for(String b : a){
        if(b.toLowerCase().replaceAll(" ", "").startsWith(stopText.getText().toLowerCase().replaceAll(" ", "")))
            filtered.add(b);
    }
    if(filtered.isEmpty()){
        filtered.add("NONE");
    }
    String[] ar = new String[filtered.size()];
    ar = filtered.toArray(ar);
    DefaultComboBoxModel model = new DefaultComboBoxModel(ar);
    stopList.setModel(model); 
  }//GEN-LAST:event_stopTextActionPerformed

    private void origListActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_origListActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_origListActionPerformed

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
      java.util.logging.Logger.getLogger(Application.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    } catch (InstantiationException ex) {
      java.util.logging.Logger.getLogger(Application.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    } catch (IllegalAccessException ex) {
      java.util.logging.Logger.getLogger(Application.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    } catch (javax.swing.UnsupportedLookAndFeelException ex) {
      java.util.logging.Logger.getLogger(Application.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
    }
    //</editor-fold>

    /* Create and display the form */
    java.awt.EventQueue.invokeLater(new Runnable() {
      public void run() {
        new Application().setVisible(true);
      }
    });
  }
  public void run(){
    setList();
  }
  public void setList(){

  }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox<String> avoidList;
    private javax.swing.JTextField avoidText;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JComboBox<String> destList;
    private javax.swing.JTextField destText;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JRadioButton lStopBtn;
    private javax.swing.JRadioButton lTransBtn;
    private javax.swing.JButton okBtn;
    private javax.swing.JComboBox<String> origList;
    private javax.swing.JTextField origText;
    private javax.swing.JTextArea outputScreen;
    private javax.swing.JComboBox<String> stopList;
    private javax.swing.JTextField stopText;
    // End of variables declaration//GEN-END:variables
}
