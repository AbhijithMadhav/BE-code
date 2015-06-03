import java.awt.Point;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.KeyEvent;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.Font;
import java.awt.Cursor;
import java.awt.Toolkit;
import javax.swing.ImageIcon;
import javax.swing.BorderFactory;
import javax.swing.JOptionPane;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JCheckBoxMenuItem;
import java.util.Timer;
import java.util.TimerTask;
import java.applet.Applet;
import java.applet.AudioClip;
import java.net.URL;
public class Zonix extends JComponent implements MouseListener,ActionListener,Runnable{
    static final int xmin=40,ymin=40,gridSize=15,maxLevel=20,rows=18,columns=30;
    static final int PAUSE=1,NEW=2,GAMEOVER=3,CONTINUE=4,UP=3,DOWN=4,VALID=5,INVALID=6,TRANSITION=7,HEADER=8,EXIT=9,HORIZONTAL=10,VERTICAL=11,START=12,NEXTLEVEL=13;
    static int level=0,lives=level+1,time=level*30,areaCovered=0,score=0,ballIndex=0;


    static ImageIcon ball[]=new ImageIcon[25];
    static ImageIcon valid = new ImageIcon("valid.jpg");
    static ImageIcon invalid = new ImageIcon("invalid.jpg");

    private Cursor hr,vr;
    Toolkit tk;

    /*AudioClip death;
    try{
        URL urlDeath=new URL("D:/AM/7THSEM/JAVA/ZONIX/sounds");
    }
    catch(Exception e){;}*/

    int r,c,slicerOffset=1,counter=0,direction=HORIZONTAL,slicerSpeed=15,headerLength=1,topRow,bottemRow,leftColumn,rightColumn;//horizontal
    Point p=new Point();
    boolean wandererPresent=false,moving=false,right=true,left=true,up=true,down=true,pause=false,start=false,crashed=false;
    static int state=START;

    Wanderer wanderer[]=new Wanderer[maxLevel+1];
    int[][] grid=new int[rows+2][columns+2];
    int temp[][]=new int[rows+2][columns+2];
    java.util.Timer timer;
    static Thread thread;

    JCheckBoxMenuItem p_pause;
    static JFrame f_frame;

    Font f;

    JMenuBar createMenu(){
        JMenuBar menu=new JMenuBar();

        JMenu game=new JMenu("Game     ");
        game.setMnemonic(KeyEvent.VK_G);
        menu.add(game);
            JMenuItem newGame=new JMenuItem("New       F1",KeyEvent.VK_F2);
            game.add(newGame);
            newGame.addActionListener(this);

            JCheckBoxMenuItem pause=new JCheckBoxMenuItem("Pause     F3");
            game.add(pause);
            pause.setSelected(false);
            p_pause=pause;
            pause.addActionListener(this);
            JMenuItem exit=new JMenuItem("Exit      F4",KeyEvent.VK_F4);
            game.add(exit);
            exit.addActionListener(this);

        JMenu view=new JMenu("View     ");
        view.setMnemonic(KeyEvent.VK_V);
        menu.add(view);
            JMenuItem highScores=new JMenuItem("High Scores   F5",KeyEvent.VK_F5);
            view.add(highScores);
            highScores.addActionListener(this);

        JMenu help=new JMenu("Help     ");
        help.setMnemonic(KeyEvent.VK_H);
        menu.add(help);
            JMenuItem about=new JMenuItem("About    F1",KeyEvent.VK_F1);
            help.add(about);
            about.addActionListener(this);

        return(menu);
    }

    Zonix(JFrame myFrame){
        ballIndex=0;
        ball[0]=new ImageIcon("pics/ball0000.png");
        ball[1]=new ImageIcon("pics/ball0001.png");
        ball[2]=new ImageIcon("pics/ball0002.png");
        ball[3]=new ImageIcon("pics/ball0003.png");
        ball[4]=new ImageIcon("pics/ball0004.png");
        ball[5]=new ImageIcon("pics/ball0005.png");
        ball[6]=new ImageIcon("pics/ball0006.png");
        ball[7]=new ImageIcon("pics/ball0007.png");
        ball[8]=new ImageIcon("pics/ball0008.png");
        ball[9]=new ImageIcon("pics/ball0009.png");
        ball[10]=new ImageIcon("pics/ball0010.png");
        ball[11]=new ImageIcon("pics/ball0011.png");
        ball[12]=new ImageIcon("pics/ball0012.png");
        ball[13]=new ImageIcon("pics/ball0013.png");
        ball[14]=new ImageIcon("pics/ball0014.png");
        ball[15]=new ImageIcon("pics/ball0015.png");
        ball[16]=new ImageIcon("pics/ball0016.png");
        ball[17]=new ImageIcon("pics/ball0017.png");
        ball[18]=new ImageIcon("pics/ball0018.png");
        ball[19]=new ImageIcon("pics/ball0019.png");
        ball[20]=new ImageIcon("pics/ball0020.png");
        ball[21]=new ImageIcon("pics/ball0021.png");
        ball[22]=new ImageIcon("pics/ball0022.png");
        ball[23]=new ImageIcon("pics/ball0023.png");
        ball[24]=new ImageIcon("pics/ball0024.png");

        Toolkit tk = Toolkit.getDefaultToolkit();
        //hr = tk.createCustomCursor(tk.getImage("hr.gif"), new Point (0,31), "hr");
        //vr = tk.createCustomCursor(tk.getImage("vr.gif"), new Point (0,31), "vr");

        f=new Font("Fixedsys",Font.BOLD,12);

        //death=Applet.newAudioClip(urlDeath);

        addMouseListener(this);

        intialiseGrid();

        for(int k=1;k<=maxLevel;k++)
            wanderer[k]=new Wanderer();

        myFrame.setJMenuBar(createMenu());

        thread=new Thread(this);
    }

    void intialiseGrid(){
        for(int i=1;i<=rows;i++)
            for(int j=1;j<=columns;j++)
                grid[i][j]=VALID;
        for(int i=0;i<=rows+1;i++){
            grid[i][0]=INVALID;
            grid[i][columns+1]=INVALID;
        }
        for(int i=0;i<=columns+1;i++){
            grid[0][i]=INVALID;
            grid[rows+1][i]=INVALID;
        }
    }
    public static void main(String[] args){
        JFrame.setDefaultLookAndFeelDecorated(false);
        JFrame myframe=new JFrame("KBounce");

        Zonix z=new Zonix(myframe);
        z.setFocusable(true);
        z.setBorder(BorderFactory.createLoweredBevelBorder());
        z.setDoubleBuffered(true);

        myframe.setBounds(150,125,540,420);
        myframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myframe.getContentPane().add(z);
        myframe.getContentPane().setBackground(Color.lightGray);
        myframe.setVisible(true);
        f_frame=myframe;

        thread.start();
    }

    public void actionPerformed(ActionEvent e){
        JMenuItem source = (JMenuItem)(e.getSource());
        String s=new String();
        s=source.getText();
        if(s=="New       F1"){
            int a=1;
            if(state==NEW||state==PAUSE||state==CONTINUE){
                timer.cancel();
                state=PAUSE;
                Object options[]={"Yes","No"};
                a=JOptionPane.showOptionDialog(null,"Do you want to quit?","Confirm",JOptionPane.YES_NO_OPTION,JOptionPane.QUESTION_MESSAGE,null,options,options[0]);
                if(a==0){
                    state=NEW;
                    reset();

                }
                else
                    state=CONTINUE;
                Remainder t=new Zonix.Remainder();
            }
            if(state==START){
                 state=NEW;
                 reset();
                 Remainder t=new Zonix.Remainder();
            }
        }
        if(s=="Pause     F3"){
            if(p_pause.isSelected()){
                state=PAUSE;
                timer.cancel();
            }
            else{
                Remainder t=new Zonix.Remainder();
                state=CONTINUE;
            }
        }
        if(s=="Exit      F4"){
            if(state==START)
                System.exit(1);
            else{
                state=PAUSE;
                timer.cancel();
                Object options[]={"Yes","No"};
                int a=JOptionPane.showOptionDialog(null,"Do you want to quit?","Confirm",JOptionPane.YES_NO_OPTION,JOptionPane.QUESTION_MESSAGE,null,options,options[0]);
                if(a==0)
                    System.exit(1);
                state=CONTINUE;
                Remainder t=new Zonix.Remainder();
            }
        }
        if(s=="High Scores   F5"){
        }
        if(s=="About    F1"){
            state=PAUSE;
            timer.cancel();
            JOptionPane.showMessageDialog(null,"Implemented by \n Abhijith Madhav \n and \n Lokesha K.S.","About",JOptionPane.INFORMATION_MESSAGE);
            state=CONTINUE;
            Remainder t=new Zonix.Remainder();
        }
    }

    public void run(){
        while(true){
            while(state==NEW||state==CONTINUE||state==NEXTLEVEL){
                try{Thread.sleep(2);}
                catch(InterruptedException e){}
                for(int k=1;k<=level;k++)
                    wanderer[k].move();
                if(moving&&counter%slicerSpeed==0){
                    counter=0;
                    slicerMove();
                }
                repaint();
                counter++;
                if(state==GAMEOVER||state==NEXTLEVEL)
                    break;
            }
            if(state==EXIT){
                System.exit(1);
            }
            if(state==GAMEOVER){
                state=START;
                JOptionPane.showMessageDialog(null,"Game Over\n Score: "+String.valueOf(score),"Game Over",JOptionPane.INFORMATION_MESSAGE);
                intialiseGrid();
                score=0;
                time=0;
                repaint();
            }
            if(state==NEXTLEVEL)
            {
                state=CONTINUE;
                intialiseGrid();
                score=score+time+15*lives;
                JOptionPane.showMessageDialog(null,"Congrat's.You go to the next level\n Score:\n Remaining Lives * 15 = "+String.valueOf(lives*15)+"\n One point for every second remaining = "+String.valueOf(time)+"\n Total = "+String.valueOf(time+15*lives),"Game Over",JOptionPane.INFORMATION_MESSAGE);
                reset();
            }
        }
    }

    public void update(Graphics g){
         for(int i=0;i<=rows+1;i++)
            for(int j=0;j<=columns+1;j++){
                if(grid[i][j]==VALID)
                     valid.paintIcon(this,g,xmin+(j-1)*gridSize,ymin+(i-1)*gridSize);
                else if(grid[i][j]==INVALID)
                    invalid.paintIcon(this,g,xmin+(j-1)*gridSize,ymin+(i-1)*gridSize);
                else if(grid[i][j]==HEADER){
                    g.setColor(Color.BLUE);
                    g.fillRect(xmin+(j-1)*gridSize,ymin+(i-1)*gridSize,gridSize,gridSize);
                }
                else{
                    g.setColor(Color.white);
                    g.fillRect(xmin+(j-1)*gridSize,ymin+(i-1)*gridSize,gridSize,gridSize);
                }
            }
        g.setColor(Color.black);
        g.setFont(f);
        g.drawString("Area Filled: "+String.valueOf(areaCovered),27,350);
        g.drawString("Level: "+String.valueOf(level),160,350);
        g.drawString("Lives: "+String.valueOf(lives),250,350);
        g.drawString("Score: "+String.valueOf(score),340,350);
        g.drawString("Time: "+String.valueOf(time),450,350);
        if(state==NEW||state==CONTINUE){
            for(int k=1;k<=level;k++)
                           ball[ballIndex].paintIcon(this,g,(int)wanderer[k].x,(int)wanderer[k].y);
             ballIndex++;
             if(ballIndex==23)
                    ballIndex=0;

        }
    }

    protected void  paintComponent(Graphics g){
        update(g);
    }

    void reset(){
         if(state==NEW){
            level=1;
            score=0;
            }
        else
            level=level+1;
        lives=level+1;
        if(state==START)
            score=0;
        time=level*30;
        areaCovered=0;
        int a=346/level;
        for(int k=1;k<=level;k++){
        wanderer[k].x=250;
        wanderer[k].y=200;
        wanderer[k].angle=a*k;
        wanderer[k].intercept=(int)(wanderer[k].y-wanderer[k].x*Math.tan((wanderer[k].angle*3.14)/(double)180));
        }

        for(int i=1;i<=rows;i++)
            for(int j=1;j<=columns;j++)
                grid[i][j]=VALID;
        for(int i=0;i<=rows+1;i++){
            grid[i][0]=INVALID;
            grid[i][columns+1]=INVALID;
        }
        for(int i=0;i<=columns+1;i++){
            grid[0][i]=INVALID;
            grid[rows+1][i]=INVALID;
        }
    }

    int getRow(int y){
        double r=(y-ymin)/gridSize+1;
        return((int)r);
    }

    int getColumn(int x){
        double c=(x-xmin)/gridSize+1;
        return((int)c);
    }

    void sweep(int state){
        for(int i=1;i<=rows;i++)
            for(int j=1;j<=columns;j++)
                if(grid[i][j]==TRANSITION||grid[i][j]==HEADER)
                    grid[i][j]=state;
    }

    public void mouseEntered(MouseEvent e){
/*        if(direction == HORIZONTAL)
            setCursor(hr);
        else
            setCursor(vr);*/
    }

    public void mousePressed(MouseEvent e){

    }

    public void mouseReleased(MouseEvent e){

    }

    public void mouseExited(MouseEvent e){
/*    if(direction == HORIZONTAL)
            setCursor(hr);
        else
            setCursor(vr);*/
    }

    public void mouseClicked(MouseEvent e){
        if(!moving){
            if(javax.swing.SwingUtilities.isRightMouseButton(e))
                if(direction==HORIZONTAL){
                    direction=VERTICAL;
//                    setCursor(vr);
                }
                else{
                    direction=HORIZONTAL;
//                    setCursor(hr);
                }
            else{

                p=e.getPoint();
/*                if(direction==VERTICAL){
                    System.out.println("verticle");
                    p.x=p.x+15;
                    p.y=p.y+7;
                }
                else{
                    System.out.println("horizontal");
                     p.x=p.x+7;
                     p.y=p.y-14;
                }*/
                r=getRow(p.y);
                c=getColumn(p.x);
                if(r>=1 && r<=rows && c>=1 && c<=columns){
                    if(grid[r][c]==VALID){
                        grid[r][c]=TRANSITION;
                        moving=true;
                    }
                }
            }
        }
    }

    void fill(int r,int c){
        grid[r][c]=INVALID;
        if(grid[r][c+1]==VALID)
            fill(r,c+1);
        if(grid[r][c-1]==VALID)
            fill(r,c-1);
        if(grid[r+1][c]==VALID)
            fill(r+1,c);
        if(grid[r-1][c]==VALID)
            fill(r-1,c);
    }

    void checkForWanderer(int r,int c,int wandererRow,int wandererColumn){
        temp[r][c]=INVALID;
        if(r==wandererRow && c==wandererColumn){
            wandererPresent=true;
            return;
        }
        else{
            if(temp[r][c+1]==VALID)
                checkForWanderer(r,c+1,wandererRow,wandererColumn);
            if(temp[r][c-1]==VALID)
                checkForWanderer(r,c-1,wandererRow,wandererColumn);
            if(temp[r+1][c]==VALID)
                checkForWanderer(r+1,c,wandererRow,wandererColumn);
            if(temp[r-1][c]==VALID)
                checkForWanderer(r-1,c,wandererRow,wandererColumn);

        }
    }

    void cutAreaVertical(){
        int i;

        int wandererRow[]=new int[level+1];
        int wandererColumn[]=new int[level+1];

        for(int k=1;k<=level;k++){
            wandererRow[k]=getRow((int)wanderer[k].y);
            wandererColumn[k]=getColumn((int)wanderer[k].x);
        }
        boolean edge=true;
        for(i=topRow+1;i<=bottemRow-1;i++)
            if(grid[i][c+1]==VALID){
                edge=false;
                break;
            }
        wandererPresent=false;
        for(int k=1;k<=level;k++){
                for(int m=0;m<=rows+1;m++)
                    for(int n=0;n<=columns+1;n++)
                        temp[m][n]=grid[m][n];
                if(edge==false){
                                checkForWanderer(i,c+1,wandererRow[k],wandererColumn[k]);
                }
                if(wandererPresent==true)
                    break;
        }
        if(wandererPresent==false&&edge==false)
            for(int s=i;s<=bottemRow-1;s++)
                fill(s,c+1);

        edge=true;
        for(i=topRow+1;i<=bottemRow-1;i++)
            if(grid[i][c-1]==VALID){
                edge=false;
                break;
            }
        wandererPresent=false;
        for(int k=1;k<=level;k++){
            for(int m=0;m<=rows+1;m++)
                for(int n=0;n<=columns+1;n++)
                    temp[m][n]=grid[m][n];
            if(edge==false){
                            checkForWanderer(i,c-1,wandererRow[k],wandererColumn[k]);
            }
            if(wandererPresent==true)
                break;
        }
        if(wandererPresent==false&&edge==false)
            for(int s=i;s<=bottemRow-1;s++)
                    fill(s,c-1);
    }

    void cutAreaHorizontal(){
        int i;

        int wandererRow[]=new int[level+1];
        int wandererColumn[]=new int[level+1];
        for(int k=1;k<=level;k++){
        wandererRow[k]=getRow((int)wanderer[k].y);
        wandererColumn[k]=getColumn((int)wanderer[k].x);
        }

        boolean edge=true;
        for(i=leftColumn+1;i<=rightColumn-1;i++)
            if(grid[r+1][i]==VALID){
                edge=false;
                break;
            }
        wandererPresent=false;
        for(int k=1;k<=level;k++){
            for(int m=0;m<=rows+1;m++)
                for(int n=0;n<=columns+1;n++)
                    temp[m][n]=grid[m][n];
            if(edge==false){
                            checkForWanderer(r+1,i,wandererRow[k],wandererColumn[k]);
            }
            if(wandererPresent==true)
                break;
        }
        if(wandererPresent==false&&edge==false)
            for(int s=i;s<=rightColumn-1;s++)
                fill(r+1,s);

        edge=true;
        for(i=leftColumn+1;i<=rightColumn-1;i++)
            if(grid[r-1][i]==VALID){
                edge=false;
                break;
            }
        wandererPresent=false;
        for(int k=1;k<=level;k++){
            for(int m=0;m<=rows+1;m++)
                for(int n=0;n<=columns+1;n++)
                    temp[m][n]=grid[m][n];
            if(edge==false){
                            checkForWanderer(r-1,i,wandererRow[k],wandererColumn[k]);
            }
            if(wandererPresent==true)
                break;
        }
        if(wandererPresent==false&&edge==false)
            for(int s=i;s<=rightColumn-1;s++)
                fill(r-1,s);
    }

    void calculateArea(){
        int count=0;
        for(int i=1;i<=rows;i++)
            for(int j=1;j<=columns;j++)
                if(grid[i][j]==INVALID)
                    count++;
        areaCovered=(int)((count/(double)(rows*columns))*100);
        if(areaCovered>=75){
            state=NEXTLEVEL;
        }
    }

    public void slicerMove(){
        if(direction==HORIZONTAL){
            if(right||left){
                if(right){
                    if(grid[r][c+slicerOffset]==INVALID){
                        rightColumn=c+slicerOffset;
                        right=false;
                    }
                    else{
                        grid[r][c+slicerOffset]=HEADER;
                        grid[r][c+slicerOffset-headerLength]=TRANSITION;
                    }
                }
                if(left){
                    if(grid[r][c-slicerOffset]==INVALID){
                        leftColumn=c-slicerOffset;
                        left=false;
                    }
                    else{
                        grid[r][c-slicerOffset]=HEADER;
                        grid[r][c-slicerOffset+headerLength]=TRANSITION;
                    }
                }
                slicerOffset++;
            }
            else{
                moving=false;
                slicerOffset=1;
                right=true;
                left=true;
                sweep(INVALID);
                if(!crashed)
                   cutAreaHorizontal();
                if(crashed==true)
                    crashed=false;
                calculateArea();
            }
        }
        else{
            if(up||down){
                if(down)
                    if(grid[r+slicerOffset][c]==INVALID){
                        bottemRow=r+slicerOffset;
                        down=false;
                    }
                    else{
                        grid[r+slicerOffset][c]=HEADER;
                        grid[r+slicerOffset-headerLength][c]=TRANSITION;
                    }
                if(up)
                    if(grid[r-slicerOffset][c]==INVALID){
                        topRow=r-slicerOffset;
                        up=false;
                    }
                    else{
                        grid[r-slicerOffset][c]=HEADER;
                        grid[r-slicerOffset+headerLength][c]=TRANSITION;
                    }
                    slicerOffset++;
            }
            else{
                moving=false;
                slicerOffset=1;
                up=down=true;
                sweep(INVALID);
                if(!crashed)
                    cutAreaVertical();
                if(crashed==true)
                    crashed=false;
                calculateArea();
            }
        }
    }

    public class Remainder {


        public Remainder() {
            timer = new java.util.Timer();
            timer.schedule(new clock(),0,1000);
            }

        public class clock extends TimerTask{
            public void run(){
                time--;
                if(time==0){
                    timer.cancel();
                    state=GAMEOVER;
                }
            }
        }
    }
public class Wanderer{
    double x,y,intercept,prevx,prevy,angle;

    int getGrid(double x,double y){
        double r=(y-ymin)/gridSize+1;//row
        double c=(x-xmin)/gridSize+1;//column
        return ((int)c+((int)r-1)*columns);
    }

    int inGrid(double x,double y){
        double r=(y-ymin)/gridSize+1;
        double c=(x-xmin)/gridSize+1;

        if(grid[(int)r][(int)c]==VALID)
            return VALID;
        else if(grid[(int)r][(int)c]==TRANSITION)
            return TRANSITION;
        else
            return INVALID;
    }

    void bounceToLeft(){
        if(angle>0 && angle<90)//travelling up
            angle=180-angle;
        else
            angle=540-angle;
    }

    void bounceToRight(){
        if(angle>=180 && angle<270)//travelling down
            angle=540-angle;
        else
            angle=180-angle;
    }

    void bounceTopOrDown(){
        angle=360-angle;
    }

    void bounce(){
        int gridNo=getGrid(x,y);
        int prevGrid=getGrid(prevx,prevy);
        double r=(y-ymin)/gridSize+1;
        double c=(x-xmin)/gridSize+1;
        if(gridNo==prevGrid+1)
            bounceToLeft();
        else if(gridNo==prevGrid-1)
            bounceToRight();
        else if(gridNo==prevGrid+columns||gridNo==prevGrid-columns)
            bounceTopOrDown();

        else if(gridNo==prevGrid+columns+1){//d and r
            double xr=prevx+(gridSize-(prevx%gridSize));
            double y_xr=Math.tan(angle*Math.PI/180)*xr+intercept;
            double yd=(prevy+(gridSize-(prevy%gridSize))-intercept)/Math.tan(angle*Math.PI/180);
            double x_yd=(yd-intercept)/Math.tan(angle*Math.PI/180);

            if((int)x_yd<(int)xr){
                if(grid[(int)r][(int)c-1]==VALID){
                    //x=xr;
                    //y=y_xr;
                    bounceToLeft();
                }
                else{
                    //x=x_yd;
                    //y=yd;
                    bounceTopOrDown();
                }
            }
            else if((int)x_yd>(int)xr){
                if(grid[(int)r-1][(int)c]==VALID){
                    //x=x_yd;
                    //y=yd;
                    bounceTopOrDown();
                }
                else{
                    //x=xr;
                    //y=y_xr;
                    bounceToLeft();
                }
            }
            else{
                //x=xr;
                //y=yd;
                if(grid[(int)r][(int)c-1]==INVALID&&grid[(int)r-1][(int)c]==INVALID)
                    angle=angle-180;
                else if(grid[(int)r][(int)c-1]==INVALID)
                    bounceTopOrDown();
                else
                    bounceToLeft();
            }
        }
        else if(gridNo==prevGrid-columns+1){//u and r
            double xr=prevx+(gridSize-(prevx%gridSize));
            double y_xr=Math.tan(angle*Math.PI/180)*xr+intercept;
            double yu=((prevy-(prevy%gridSize))-intercept)/Math.tan(angle*Math.PI/180);
            double x_yu=(yu-intercept)/Math.tan(angle*Math.PI/180);

            if((int)x_yu<(int)xr){
                if(grid[(int)r][(int)c-1]==VALID){
                    //x=xr;
                    //y=y_xr;
                    bounceToLeft();
                }
                else{
                    //x=x_yu;
                    //y=yu;
                    bounceTopOrDown();
                }
            }
            else if((int)x_yu>(int)xr){
                if(grid[(int)r+1][(int)c]==VALID){
                    //x=x_yu;
                    //y=yu;
                    bounceTopOrDown();
                }
                else{
                    //x=xr;
                    //y=y_xr;
                    bounceToLeft();
                }
            }
            else{
                //x=xr;
                //y=yu;
                if(grid[(int)r][(int)c-1]==INVALID&&grid[(int)r+1][(int)c]==INVALID)
                    angle=angle+180;
                else if(grid[(int)r][(int)c-1]==INVALID)
                    bounceTopOrDown();
                else
                    bounceToLeft();
            }
        }
        else if(gridNo==prevGrid-columns-1){//u and l
            double xl=prevx-(prevx%gridSize);
            double y_xl=xl*Math.tan(angle*Math.PI/180)+intercept;
            double yu=((prevy-(prevy%gridSize))-intercept)/Math.tan(angle*Math.PI/180);
            double x_yu=(yu-intercept)/Math.tan(angle*Math.PI/180);
            if((int)x_yu>(int)xl){
                if(grid[(int)r][(int)c+1]==VALID){
                    //x=xl;
                    //y=y_xl;
                    bounceToRight();
                }
                else{
                    //x=x_yu;
                    //y=yu;
                    bounceTopOrDown();
                }
            }
            else if((int)x_yu<(int)xl){
                if(grid[(int)r+1][(int)c]==VALID){
                    //x=x_yu;
                    //y=yu;
                    bounceTopOrDown();
                }
                else{
                    //x=xl;
                    //y=y_xl;
                    bounceToRight();
                }
            }
            else{
                //x=xl;
                //y=yu;
                if(grid[(int)r][(int)c+1]==INVALID&&grid[(int)r+1][(int)c]==INVALID)
                    angle=angle+180;
                else if(grid[(int)r][(int)c+1]==INVALID)
                    bounceTopOrDown();
                else
                    bounceToRight();
            }
        }
        else if(gridNo==prevGrid+columns-1){//d and l
            double xl=prevx-(prevx%gridSize);
            double y_xl=xl*Math.tan(angle*Math.PI/180)+intercept;
            double yd=(prevy+(gridSize-(prevy%gridSize))-intercept)/Math.tan(angle*Math.PI/180);
            double x_yd=(yd-intercept)/Math.tan(angle*Math.PI/180);
            if((int)x_yd>(int)xl){
                if(grid[(int)r][(int)c+1]==VALID){
                    //x=xl;
                    //y=y_xl;
                    bounceToRight();
                }
                else{
                    //x=x_yd;
                    //y=yd;
                    bounceTopOrDown();
                }
            }
            else if((int)x_yd<(int)xl){
                if(grid[(int)r-1][(int)c]==VALID){
                    //x=x_yd;
                    //y=yd;
                    bounceTopOrDown();
                }
                else{
                  //  x=xl;
                   // y=y_xl;
                    bounceToRight();
                }
            }
            else{
                 //x=xl;
                // y=yd;
                if(grid[(int)r][(int)c+1]==INVALID&&grid[(int)r-1][(int)c]==INVALID)
                    angle=angle-180;
                else if(grid[(int)r][(int)c+1]==INVALID)
                    bounceTopOrDown();
                else
                    bounceToRight();
            }
        }
        x=prevx;
        y=prevy;
        intercept=(y-x*Math.tan((angle*Math.PI)/180));

    }

    void calculateNextPoint(){
        prevx=x;
        prevy=y;
        if(angle==90)
			y++;
		else if(angle==270)
            y--;
        else if(angle==135){
            x--;
            y++;
        }
        else if((angle>=0&&angle<=45)){
			x++;
            y=(x*Math.tan((angle*Math.PI)/180)+intercept);
        }
		else if((angle>45&&angle<90)){
			y++;
            x=((y-intercept)/Math.tan((angle*Math.PI)/180));
        }
        else if((angle>90&&angle<135)){
            y++;
            x=((y-intercept)/Math.tan((angle*Math.PI)/180));
        }
        else if((angle>135&&angle<=180))
        {
             x--;
            y=(x*Math.tan((angle*Math.PI)/180)+intercept);
        }
        else if((angle>180&&angle<225)){
            x--;
            y=(x*Math.tan((angle*Math.PI)/180)+intercept);
        }
        else if((angle>=225&&angle<=270)){
            y--;
            x=((y-intercept)/Math.tan((angle*Math.PI)/180));
        }
        else if((angle>270&&angle<=315)){
            y--;
            x=((y-intercept)/Math.tan((angle*Math.PI)/180));
        }
        else if((angle>315&&angle<=360)){
            x++;
            y=(x*Math.tan((angle*Math.PI)/180)+intercept);
        }

    }

    void move(){
        calculateNextPoint();
        int state;
        if((state=inGrid(x,y))==VALID)
            if((state=inGrid(x+10,y))==VALID)
                if((state=inGrid(x+10,y+10))==VALID)
                    if((state=inGrid(x,y+10))==VALID);
                    else{
                         x=x;
                         y=y+10;
                    }
                else{
                     x=x+10;
                     y=y+10;
                }
            else{
                 x=x+10;
                 y=y;
            }
        else{
            x=x;
            y=y;
        }
         if(state==INVALID){
            bounce();
        }
        else if(state==TRANSITION||state==HEADER){
            crashed=true;
            //death.play();
            if(direction==VERTICAL){
                if(getRow((int)y)<r){
                    up=false;
                    for(int i=r;grid[i][c]!=INVALID;i--)
                        grid[i][c]=VALID;
                }
                else{
                    down=false;
                    for(int i=r;grid[i][c]!=INVALID;i++)
                        grid[i][c]=VALID;
                }
            }
            else{
                if(getColumn((int)x)<c){
                    left=false;
                for(int i=c;grid[r][i]!=INVALID;i--)
                    grid[r][i]=VALID;
                }
                else{
                    right=false;
                    for(int i=c;grid[r][i]!=INVALID;i++)
                        grid[r][i]=VALID;
                }
            }
            lives--;
            if(lives==0){
                Zonix.state=GAMEOVER ;

                Zonix.areaCovered=0;
                Zonix.time=0;
            }
        }
    }
}
}