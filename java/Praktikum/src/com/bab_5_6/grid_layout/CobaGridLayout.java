package com.bab_5_6.grid_layout;

import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class CobaGridLayout {
  public static void main(String[] args) {
    new GLayout();
  }
}

class GLayout extends JFrame {
  JButton tombolSave, tombolEdit, tombolDelete, tombolOpen;

  public GLayout() {
    setTitle("GRID LAYOUT");
    tombolOpen = new JButton("Open");
    tombolSave = new JButton("Save");
    tombolEdit = new JButton("Edit");
    tombolDelete = new JButton("Delete");

    // Set layout to type grid
    setLayout(new GridLayout(2, 2));
    add(tombolOpen);
    add(tombolSave);
    add(tombolEdit);
    add(tombolDelete);

    pack();
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }
}
