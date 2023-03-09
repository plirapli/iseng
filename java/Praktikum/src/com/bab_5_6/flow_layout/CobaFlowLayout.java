package com.bab_5_6.flow_layout;

import java.awt.FlowLayout; // Import layout manager
import javax.swing.*; // Import swing for GUI

public class CobaFlowLayout {
  public static void main(String[] args) {
    new FLayout();
  }
}

class FLayout extends JFrame {
  JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;

  public FLayout() {
    setTitle("FLOW LAYOUT");
    b1 = new JButton("b1");
    b2 = new JButton("b2");
    b3 = new JButton("b3");
    b4 = new JButton("b4");
    b5 = new JButton("b5");
    b6 = new JButton("b6");
    b7 = new JButton("b7");
    b8 = new JButton("b8");
    b9 = new JButton("b9");
    b10 = new JButton("b10");

    // Set layout to type flow
    setLayout(new FlowLayout());
    add(b1);
    add(b2);
    add(b3);
    add(b4);
    add(b5);
    add(b6);
    add(b7);
    add(b8);
    add(b9);
    add(b10);

    pack();
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }
}
