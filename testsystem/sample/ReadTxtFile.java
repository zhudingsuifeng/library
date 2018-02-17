package sample;

import java.io.*;
import java.util.ArrayList;

public class ReadTxtFile {
    /**
     * 功能：Java读取txt文件的内容
     * 步骤：1：先获得文件句柄
     * 2：获得文件句柄当做是输入一个字节码流，需要对这个输入流进行读取
     * 3：读取到输入流后，需要读取生成字节流
     * 4：一行一行的输出。readline()。
     * 备注：需要考虑的是异常情况
     * @param filePath
     */
    public ArrayList<String> readTxtFile(String filePath,int numline){//d读取txt文件，存储到一个数组中
        RandomNumber randomNumber = new RandomNumber();
        int[] numberArray = randomNumber.getArray(numline);//产生随机数
        try {
            String encoding="GBK";
            File file=new File(filePath);
//          File file=this.getClass().getResource(filePath);
            if(file.isFile() && file.exists()){ //判断文件是否存在
                // InputStream read = this.getClass().getResourceAsStream(filePath);
                InputStreamReader read = new InputStreamReader( new FileInputStream(file),encoding);//考虑到编码格式
                String lineTxt = null;
                ArrayList<String> readList = new ArrayList<String>();
                BufferedReader reader=new BufferedReader(read);
                //BufferedReader reader=new BufferedReader(read);
                //BufferedReader bufferedReader=new BufferedReader(new InputStreamReader(new FileInputStream()))
                while((lineTxt=reader.readLine())!=null &&!"".equals(lineTxt)){
                    String[] sourceStrArray = lineTxt.split("；");
                    int linenumber=Integer.parseInt(sourceStrArray[0]);//Integer.parseInt(sourceStrArray[0])把String类型的数字转换成int类型
                        for(int order : numberArray) {
                            if (order == linenumber) {
                                readList.add(lineTxt);
                            }
                        }
                    }
                    reader.close();
                    return readList;
            }else{
                System.out.println("找不到指定的文件");
                return null;
            }
        } catch (Exception e) {
            System.out.println("读取文件内容出错");
            e.printStackTrace();
            return null;
        }
    }
}
