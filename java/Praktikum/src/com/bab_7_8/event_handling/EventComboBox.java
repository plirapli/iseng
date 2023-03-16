package com.bab_7_8.event_handling;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EventComboBox {
  public static void main(String[] args) {
    new ComboBoxHandling();
  }
}

class ComboBoxHandling extends JFrame implements ItemListener {
  // Inisiasi komponen GUI
  private String status[] = { "Setuju", "Batal" };
  private JLabel labelTeks;
  private JComboBox comboBoxStatus;

  public ComboBoxHandling() {
    super("Coba ComboBox Handling");

    // Bikin komponen
    labelTeks = new JLabel("Status: None");
    labelTeks.setHorizontalAlignment(SwingConstants.CENTER);

    // Bikin combobox terus dikasih event listener
    comboBoxStatus = new JComboBox(status);
    comboBoxStatus.setSelectedIndex(0);
    comboBoxStatus.addItemListener(this);

    // Bikin layout
    setLayout(new BorderLayout());
    add(labelTeks, "North");
    add(comboBoxStatus, "South");
    pack();
    setDefaultCloseOperation(3);
    setVisible(true);
  }

  public void itemStateChanged(ItemEvent event) {
    if (event.getStateChange() == ItemEvent.SELECTED) {
      if (comboBoxStatus.getSelectedIndex() == 0)
        labelTeks.setText("Setuju");
      else if (comboBoxStatus.getSelectedIndex() == 1)
        labelTeks.setText("Batal");
    }
  }
}
