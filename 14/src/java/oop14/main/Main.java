import javax.swing.*;
import java.awt.*;


public class Main {
  public static void main(String[] args) {
    var frame = new MyFrame();

    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);
  }
}


class MyFrame extends JFrame {
  public MyFrame() {
    setSize(WIDTH, HEIGHT);
    var panel = new PaintPanel();
    add(panel);
  }

  public static final int WIDTH = 800;
  public static final int HEIGHT = 600;
}


class PaintPanel extends JPanel {
  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.drawString("test", 10, 20);
    g.drawRect(10, 40, 300, 100);
  }
}
