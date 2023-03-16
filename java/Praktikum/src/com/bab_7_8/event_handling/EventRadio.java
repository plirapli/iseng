package com.bab_7_8.event_handling;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EventRadio {
  public static void main(String[] args) {
    new RadioHandling();
  }
}

class RadioHandling extends JFrame implements ItemListener {
  // Inisiasi komponen GUI
  private JTextField teks;
  private JPanel panel;
  private JRadioButton radioBtnPria;
  private JRadioButton radioBtnWanita;
  private JRadioButton radioBtnKomang;

  public RadioHandling() {
    super("Coba RadioButton Handling");

    teks = new JTextField("Jenis Kelamin : PILIHAN ");
    teks.setHorizontalAlignment(SwingConstants.CENTER);
    panel = new JPanel(new FlowLayout());
    radioBtnPria = new JRadioButton("Pria");
    radioBtnWanita = new JRadioButton("Wanita");
    radioBtnKomang = new JRadioButton("Komang");

    // Membuat group radioButton supaya salah satu aja yang terpilih
    ButtonGroup group = new ButtonGroup();
    group.add(radioBtnPria);
    group.add(radioBtnWanita);
    group.add(radioBtnKomang);

    // Membuat event listener
    radioBtnPria.addItemListener(this);
    radioBtnWanita.addItemListener(this);
    radioBtnKomang.addItemListener(this);

    // Membuat layout
    setLayout(new BorderLayout());
    add(teks, "North");
    add(panel, "West");
    panel.add(radioBtnPria);
    panel.add(radioBtnWanita);
    panel.add(radioBtnKomang);
    pack();
    setVisible(true);
    setLocation(200, 200);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

  // Bikin event handler
  @Override
  public void itemStateChanged(ItemEvent event) {
    if (event.getSource() == radioBtnPria) {
      if (event.getStateChange() == ItemEvent.SELECTED)
        teks.setText("Jenis Kelamin : Pria");
    }
    if (event.getSource() == radioBtnWanita) {
      if (event.getStateChange() == ItemEvent.SELECTED)
        teks.setText("Jenis Kelamin : Wanita");
    }
    if (event.getSource() == radioBtnKomang) {
      if (event.getStateChange() == ItemEvent.SELECTED)
        teks.setText("Jenis Kelamin : Komang");
    }
  }
}
