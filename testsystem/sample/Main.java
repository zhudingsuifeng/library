package sample;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class Main extends Application {
    //一个java文件中就只能有一个public类，并且需要类名和文件名相同
    @Override
    public void start(Stage primaryStage) throws Exception{
        BorderPane root = new BorderPane();//采用BorderPane布局格式
        GridPane testGrid=new GridPane();//网格布局
        testGrid.setHgap(20);
        testGrid.setVgap(20);
        MouseEvent clickEvent=new MouseEvent();
        final ToggleGroup radioButtonGroup=new ToggleGroup();//创建按钮组

        primaryStage.setTitle("Test System");//窗口标题
        Scene scene = new Scene(root, 500, 600);//窗口大小
        MenuBar menuBar = new MenuBar();//创建菜单
        menuBar.prefWidthProperty().bind(primaryStage.widthProperty());
        root.setTop(menuBar);//向顶部窗格中添加元素

        TextArea textContext=new TextArea();
        textContext.setPrefRowCount(8);//设置文本域大小
        textContext.setPrefColumnCount(24);
        textContext.setWrapText(true);
        //textContext.setText();
        testGrid.add(textContext,4,3,6,8);

        RadioButton radioButtonA=new RadioButton();
        radioButtonA.setToggleGroup(radioButtonGroup);//把按钮添加到组中
        testGrid.add(radioButtonA,5,11,1,3);
        radioButtonA.setOnAction(actionEvent -> {
            try {
                clickEvent.testchooseA();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        RadioButton radioButtonB=new RadioButton();
        radioButtonB.setToggleGroup(radioButtonGroup);
        testGrid.add(radioButtonB,5,12,1,3);
        radioButtonB.setOnAction(actionEvent -> {
            try {
                clickEvent.testchooseB();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        RadioButton radioButtonC=new RadioButton();
        radioButtonC.setToggleGroup(radioButtonGroup);
        testGrid.add(radioButtonC,5,13,1,3);
        radioButtonC.setOnAction(actionEvent -> {
            try {
                clickEvent.testchooseC();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        RadioButton radioButtonD=new RadioButton();
        radioButtonD.setToggleGroup(radioButtonGroup);
        testGrid.add(radioButtonD,5,14,1,3);
        radioButtonD.setOnAction(actionEvent -> {
            try {
                clickEvent.testchooseD();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        Button btn = new Button();
        btn.setText("上一题");
        btn.setOnAction(actionEvent -> {
            try {
                clickEvent.testPre(testGrid,textContext,radioButtonA,radioButtonB,
                        radioButtonC,radioButtonD,radioButtonGroup);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        Button btnNext = new Button();
        btnNext.setText("下一题");
        btnNext.setOnAction(actionEvent -> {
            try {
                clickEvent.testNext(testGrid,textContext,radioButtonA,radioButtonB,
                        radioButtonC,radioButtonD,radioButtonGroup);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
        testGrid.add(btn,5,18,1,1);
        testGrid.add(btnNext,9,18,1,1);

        // Test menu - startTest, exit
        Menu testMenu = new Menu("考试");//考试菜单

        MenuItem startTestMenuItem = new MenuItem("开始考试");
        startTestMenuItem.setOnAction(actionEvent -> {
            try {
                clickEvent.startTest(testGrid,textContext,radioButtonA,radioButtonB,
                        radioButtonC,radioButtonD);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });//给按钮设置点击事件

        MenuItem exitMenuItem = new MenuItem("退出");
        exitMenuItem.setOnAction(actionEvent -> Platform.exit());

        testMenu.getItems().addAll(startTestMenuItem,
                new SeparatorMenuItem(), exitMenuItem);

        Menu checkMenu = new Menu("阅卷");//阅卷菜单
        MenuItem startCheckMenuItem = new MenuItem("开始打分");
        startCheckMenuItem.setOnAction(actionEvent -> clickEvent.startCheck());

        root.setCenter(testGrid);//向center窗格中添加元素
        checkMenu.getItems().add(startCheckMenuItem);
        menuBar.getMenus().addAll(testMenu, checkMenu);
        testGrid.setVisible(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
