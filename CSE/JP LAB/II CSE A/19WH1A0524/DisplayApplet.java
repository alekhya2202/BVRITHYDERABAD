import java.applet.*;
import java.awt.*;
public class DisplayApplet extends Applet{
    public void paint(Graphics g){
			setForeground(Color.blue);
			setBackground(Color.pink);
			g.drawString("Welcome to applet", 50, 60);
		}
	}
/*
<applet code="DisplayApplet" width=500 height=500
></applet>
*/