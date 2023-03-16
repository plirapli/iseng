package com.bab_7_8.stream_dan_file;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CobaPenampilFileBerbuffer {
  public static void main(String[] args) {
    new PenampilFileBerbuffer();
  }
}

class PenampilFileBerbuffer extends JFrame {
  JTextArea ta;
  JButton bSave;
  ActionListener Aksi;
  BufferedReader br;
  BufferedWriter bw;

  public PenampilFileBerbuffer() {
    setTitle("Test Buffer");
    setSize(340, 280);
    JPanel pn = new JPanel();
    add("North", pn);
    bSave = new JButton("Save");
    bSave.addActionListener(new Aksi());
    pn.add(bSave);
    JPanel p = new JPanel();
    add("Center", p);
    ScrollPane sp = new ScrollPane();
    sp.setPreferredSize(new Dimension(300, 200));
    p.add(sp);
    ta = new JTextArea();
    sp.add(ta);
    setDefaultCloseOperation(3);
    setVisible(true);

    try {
      bw = new BufferedWriter(new FileWriter("buffer.txt"));
      br = new BufferedReader(new FileReader("data.txt"));
    }

    catch (IOException e) {
    }

    bacaFile();
  }

  class Aksi implements ActionListener {
    public void actionPerformed(ActionEvent ae) {
      try {
        ta.write(bw);
        JOptionPane.showMessageDialog(null, "Data berhasil disimpan", "Hasil", JOptionPane.INFORMATION_MESSAGE);
      }

      catch (IOException e) {
      }
      ;
    }
  }

  public void bacaFile() {
    try {
      ta.read(br, null);
    }

    catch (IOException e) {
    }
  }
}
