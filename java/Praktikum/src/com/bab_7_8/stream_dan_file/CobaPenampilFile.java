package com.bab_7_8.stream_dan_file;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class PenampilFile extends JFrame {
  JTextArea textArea;
  JButton btnSave;
  ActionListener Aksi;

  public PenampilFile() {
    super("Data.txt");
    setSize(340, 280);

    JPanel panel = new JPanel();
    add("North", panel);
    btnSave = new JButton("Save");
    btnSave.addActionListener(new Aksi());
    panel.add(btnSave);

    JPanel panelText = new JPanel();
    add("Center", panelText);
    ScrollPane scrollPane = new ScrollPane();
    scrollPane.setPreferredSize(new Dimension(300, 200));
    panelText.add(scrollPane);
    textArea = new JTextArea();
    scrollPane.add(textArea);

    setDefaultCloseOperation(3);
    setVisible(true);
    bacaFile();
  }

  class Aksi implements ActionListener {
    public void actionPerformed(ActionEvent ae) {
      try {
        // karakter
        textArea.write(new FileWriter("data.txt"));
        JOptionPane.showMessageDialog(null, "Data berhasil disimpan", "Hasil", JOptionPane.INFORMATION_MESSAGE);

        // byte :
        textArea.write(new OutputStreamWriter(new FileOutputStream("data.txt")));
      }

      catch (IOException e) {
      }
    }
  }

  public void bacaFile() {
    try {
      // karakter
      textArea.read(new FileReader("data.txt"), null);

      // byte :
      textArea.write(new OutputStreamWriter(new FileOutputStream("data.txt")));
    }

    catch (IOException e) {
    }
  }
}

public class CobaPenampilFile {
  public static void main(String[] args) {
    new PenampilFile();
  }
}
