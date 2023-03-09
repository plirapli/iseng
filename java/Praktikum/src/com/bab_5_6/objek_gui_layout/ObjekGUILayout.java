package com.bab_5_6.objek_gui_layout;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class ObjekGUILayout {
  public static void main(String[] args) {
    new GUI();
  }
}

class GUI extends JFrame {
  // Label
  JLabel namaLabel = new JLabel("Nama Lengkap");
  JLabel genderLabel = new JLabel("Jenis Kelamin");
  JLabel agamaLabel = new JLabel("Agama");
  JLabel hobbyLabel = new JLabel("Hobby");

  // Text field
  final JTextField namaTextField = new JTextField(10);

  // Radio button
  JRadioButton priaRadio = new JRadioButton("Laki-laki");
  JRadioButton wanitaRadio = new JRadioButton("Perempuan");

  // Combo box
  String[] namaAgama = { "Islam", "Kristen", "Katolik", "Hindu", "Budha" };
  JComboBox agamaComboBox = new JComboBox<>(namaAgama);

  // Checkbox
  JCheckBox sepakBolaComboBox = new JCheckBox("Sepak bola");
  JCheckBox basketComboBox = new JCheckBox("Basket");
  JCheckBox babiComboBox = new JCheckBox("Makan Babi");

  // Button
  JButton saveBtn = new JButton("OK");

  public GUI() {
    // Inisiasi windows/frame
    setTitle("Login GUI");
    setDefaultCloseOperation(3);
    setSize(350, 225);
    setLocationRelativeTo(null);

    // Bikin radio group
    ButtonGroup genderGButtonGroup = new ButtonGroup();
    genderGButtonGroup.add(priaRadio);
    genderGButtonGroup.add(wanitaRadio);

    // Bikin form
    setLayout(null);
    add(namaLabel);
    add(namaTextField);

    add(genderLabel);
    add(priaRadio);
    add(wanitaRadio);

    add(agamaLabel);
    add(agamaComboBox);

    add(hobbyLabel);
    add(sepakBolaComboBox);
    add(basketComboBox);
    add(babiComboBox);

    add(saveBtn);
    // End Bikin form

    // Positioning, Scalling
    // Ket: setBounds(x, y, height, width)
    namaLabel.setBounds(10, 10, 120, 20);
    namaTextField.setBounds(130, 10, 150, 20);

    genderLabel.setBounds(10, 35, 120, 20);
    priaRadio.setBounds(130, 35, 100, 20);
    wanitaRadio.setBounds(230, 35, 100, 20);

    agamaLabel.setBounds(10, 60, 120, 20);
    agamaComboBox.setBounds(130, 60, 150, 20);

    hobbyLabel.setBounds(10, 85, 120, 20);
    sepakBolaComboBox.setBounds(130, 85, 100, 20);
    basketComboBox.setBounds(230, 85, 150, 20);
    babiComboBox.setBounds(130, 110, 150, 20);

    saveBtn.setBounds(100, 150, 120, 20);
    setVisible(true);
  }
}
