package sample;

import javafx.scene.control.RadioButton;
import javafx.scene.control.TextArea;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.GridPane;
import java.util.ArrayList;
import java.util.Arrays;

public class MouseEvent {
    int testnumber;
    ReadTxtFile txtFile=new ReadTxtFile();//读取文件

    //String filePath =  System.getProperty("user.dir")+"\\src\\test.txt";//文件路径
    String filePath="E:\\test.txt";
    //String filePath="/test.txt";

    ArrayList<String> readList;//d读取txt文件，存储到一个数组中
    ArrayList<String> mychoose=new ArrayList <String>(Arrays.asList("E","E","E","E","E",
            "E","E","E","E","E","E","E","E","E","E","E","E","E","E","E"));//初始化一个ArrayList

    //开始考试
    public void startTest( GridPane testGrid, TextArea textContext,
                          RadioButton radioButtonA,RadioButton radioButtonB,RadioButton radioButtonC,
                          RadioButton radioButtonD) throws Exception {
        testnumber=0;
        readList=txtFile.readTxtFile(filePath,20);

        String[]context = readList.get(testnumber).split("；");//选取第testnumber个值，并且用；分割字符
        textContext.setText(context[1]);
        radioButtonA.setText(context[2]);
        radioButtonB.setText(context[3]);
        radioButtonC.setText(context[4]);
        radioButtonD.setText(context[5]);
        testGrid.setVisible(true);

    }

    //上一题
    public void testPre(GridPane testGrid, TextArea textContext,
                        RadioButton radioButtonA,RadioButton radioButtonB,RadioButton radioButtonC,
                        RadioButton radioButtonD,ToggleGroup radioButtonGroup) {
        String[] context;
        if (testnumber>0){
            testnumber--;
            context = readList.get(testnumber).split("；");//选取第testnumber个值，并且用；分割字符
        }else{
            context = readList.get(0).split("；");//选取第testnumber个值，并且用；分割字符
        }
        textContext.setText(context[1]);
        radioButtonA.setText(context[2]);
        radioButtonA.setSelected(false);
        radioButtonB.setText(context[3]);
        radioButtonB.setSelected(false);
        radioButtonC.setText(context[4]);
        radioButtonC.setSelected(false);
        radioButtonD.setText(context[5]);
        radioButtonD.setSelected(false);
        testGrid.setVisible(true);
    }

    //下一题
    public void testNext(GridPane testGrid, TextArea textContext,
                         RadioButton radioButtonA,RadioButton radioButtonB,RadioButton radioButtonC,
                         RadioButton radioButtonD,ToggleGroup radioButtonGroup) throws Exception {
        String[] context;
        if (testnumber<19){
            testnumber++;
            context = readList.get(testnumber).split("；");//选取第testnumber个值，并且用；分割字符
        }else context = readList.get(19).split("；");//选取第testnumber个值，并且用；分割字符
        textContext.setText(context[1]);
        radioButtonA.setText(context[2]);
        radioButtonA.setSelected(false);
        radioButtonB.setText(context[3]);
        radioButtonB.setSelected(false);
        radioButtonC.setText(context[4]);
        radioButtonC.setSelected(false);
        radioButtonD.setText(context[5]);
        radioButtonD.setSelected(false);
        testGrid.setVisible(true);
    }

    //选择A
    public void testchooseA() throws Exception {
        mychoose.set(testnumber, "A");//获取选择的答案
        //System.out.println(mychoose.size());
    }

    //选择B
    public void testchooseB() throws Exception {
        mychoose.set(testnumber, "B");
    }

    //选择C
    public void testchooseC() throws Exception {
        mychoose.set(testnumber, "C");
    }

    //选择D
    public void testchooseD() throws Exception {
        mychoose.set(testnumber, "D");
    }

    //打分
    public void startCheck() {
        int grades=0;
        for (int  order=0;order<19;order++){
            if (mychoose.get(order).equals(readList.get(order).split("；")[6]))
                grades+=5;
        }
        Windows childenWindow=new Windows();
        childenWindow.display(Integer.toString(grades));
    }
}
