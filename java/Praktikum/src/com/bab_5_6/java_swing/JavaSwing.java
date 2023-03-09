package com.bab_5_6.java_swing;

import java.awt.FlowLayout;
import javax.swing.JFrame;

public class JavaSwing {
  public static void main(String[] args) {
    JFrame frame = new JFrame();
    frame.setTitle("Ini adalah judul");
    frame.setSize(300, 100);
    frame.setLayout(new FlowLayout());
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
}
