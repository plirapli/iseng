/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package login;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.*;

import User.User;

/**
 *
 * @author rafli
 */
public class Tampilan extends JFrame implements ActionListener {
  private CardLayout card;
  private Container contentPane;
  private JPanel panelLogin, panelLogged, panelTengah, panelLoggedTengah, panelTombol, panelLoggedTombol;
  private JLabel labelTitle, labelNama, labelNim, labelkelas;
  private JLabel labelHasilNama, labelHasilNim, labelHasilkelas;
  private JTextField inputNama, inputNim;
  private JComboBox comboBoxKelas;
  private JButton btnSubmit, btnKembali;
  private String kelas[] = { "IF-A", "IF-B", "IF-C", "IF-D", "IF-E", "IF-F", "IF-H" };

  Tampilan() {
    super("Kalkulator Balok");

    // Bikin komponen buat layout utama
    card = new CardLayout();
    contentPane = getContentPane();

    // Bikin komponen buat halaman login
    panelLogin = new JPanel(new BorderLayout(0, 10));
    panelTengah = new JPanel(new GridLayout(3, 2, 0, 5));
    panelTombol = new JPanel(new GridLayout(1, 1));
    labelTitle = new JLabel("Menu Form");

    labelNama = new JLabel("Nama");
    inputNama = new JTextField(7);
    labelNim = new JLabel("NIM");
    inputNim = new JTextField(7);
    labelkelas = new JLabel("Kelas");
    comboBoxKelas = new JComboBox(kelas);
    comboBoxKelas.setSelectedIndex(0);

    btnSubmit = new JButton("Sumbit");

    // Bikin komponen buat halaman logged in
    panelLogged = new JPanel(new BorderLayout(0, 10));
    panelLoggedTengah = new JPanel(new GridLayout(3, 1, 0, 5));
    panelLoggedTombol = new JPanel(new GridLayout(1, 1));

    labelHasilNama = new JLabel();
    labelHasilNim = new JLabel();
    labelHasilkelas = new JLabel();

    btnKembali = new JButton("Kembali");

    // Bikin layout
    contentPane.setLayout(card);
    contentPane.add(panelLogin, "1");
    contentPane.add(panelLogged, "2");
    setResizable(true);

    // Ngatur layout buat hal. login
    panelLogin.setBorder(BorderFactory.createEmptyBorder(5, 10, 10, 10));
    panelLogin.add(labelTitle);
    labelTitle.setHorizontalAlignment(SwingConstants.CENTER);
    panelLogin.add(labelTitle, "North");
    panelLogin.add(panelTengah, "Center");
    panelLogin.add(panelTombol, "South");

    panelTengah.add(labelNama);
    panelTengah.add(inputNama);
    panelTengah.add(labelNim);
    panelTengah.add(inputNim);
    panelTengah.add(labelkelas);
    panelTengah.add(comboBoxKelas);

    panelTombol.add(btnSubmit);

    // Ngatur layout buat hal. logged in
    panelLogged.setBorder(BorderFactory.createEmptyBorder(5, 10, 10, 10));
    panelLogged.add(panelLoggedTengah, "Center");
    panelLogged.add(panelLoggedTombol, "South");

    panelLoggedTengah.add(labelHasilNama);
    panelLoggedTengah.add(labelHasilNim);
    panelLoggedTengah.add(labelHasilkelas);
    panelLoggedTombol.add(btnKembali);

    pack();
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setLocationRelativeTo(null);

    // Bikin event listener
    btnSubmit.addActionListener(this);
    btnKembali.addActionListener(this);
  }

  // Event handler
  @Override
  public void actionPerformed(ActionEvent event) {

    if (event.getSource() == btnSubmit) {
      int indexKelas = comboBoxKelas.getSelectedIndex();
      String textNama = inputNama.getText();
      String textNim = inputNim.getText();
      String textKelas = kelas[indexKelas];

      try {

        // Bikin objek balok based on the input
        User user = new User(textNama, textNim, textKelas);

        // Namoilin hasil hitungan
        labelHasilNama.setText("Nama: " + user.getNama());
        labelHasilNim.setText("NIM: " + user.getNim());
        labelHasilkelas.setText("Kelas: " + user.getKelas());

        card.next(contentPane);
      } catch (Exception error) {
        JOptionPane.showMessageDialog(this, error.getMessage());
      }

      // if (event.getSource() == btnReset) {
      // // Reset jawaban
      // labelKeliling.setText(" ");
      // labelLuas.setText(" ");
      // labelLuasPermukaan.setText(" ");
      // labelVolume.setText(" ");

      // // Reset input
      // inputPanjang.setText("0");
      // inputLebar.setText("0");
      // inputTinggi.setText("0");
    }

    if (event.getSource() == btnKembali) {
      card.next(contentPane);
    }
  }
}
