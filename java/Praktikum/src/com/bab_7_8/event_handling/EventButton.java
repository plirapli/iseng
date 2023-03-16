package com.bab_7_8.event_handling;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EventButton {
  public static void main(String[] args) {
    new ButtonHandling();
  }
}

class ButtonHandling extends JFrame implements ActionListener {
  private JLabel label;
  private JButton btnSetuju;
  private JButton btnBatal;

  public ButtonHandling() {
    super("Coba Button Handling");

    // Bikin label
    label = new JLabel("Status: None");

    // Ngatur label (text) biar bisa ditengah
    label.setHorizontalAlignment(SwingConstants.CENTER);

    // Bikin button
    btnSetuju = new JButton("Setuju");
    btnBatal = new JButton("Batal");

    // Nambah event listener
    btnSetuju.addActionListener(this);
    btnBatal.addActionListener(this);

    // Bikin layout
    setLayout(new BorderLayout());
    add(label, "North");
    add(btnSetuju, "West");
    add(btnBatal, "East");
    pack();
    setResizable(false);
    setLocation(100, 100);
    setDefaultCloseOperation(3);
    setVisible(true);
  }

  // Event handler
  @Override
  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == btnSetuju) {
      label.setText("Status : Setuju");
    } else if (e.getSource() == btnBatal) {
      label.setText("Status : Batal");
    }
  }
}
