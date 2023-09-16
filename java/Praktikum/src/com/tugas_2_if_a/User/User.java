package User;

public class User {
  private String nama, nim, kelas;

  public User(String nama, String nim, String kelas) {
    this.nama = nama;
    this.nim = nim;
    this.kelas = kelas;
  }

  public String getNama() {
    return nama;
  }

  public void setNama(String nama) {
    this.nama = nama;
  }

  public String getNim() {
    return nim;
  }

  public void setNim(String nim) {
    this.nim = nim;
  }

  public String getKelas() {
    return kelas;
  }

  public void setKelas(String kelas) {
    this.kelas = kelas;
  }
}
