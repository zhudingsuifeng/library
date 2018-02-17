package sample;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class RandomNumber {
    //产生不重复的随机数
    public int[] getArray(int len){  //len为需要产生的不重复随机数个数
        Set<Integer> set = new HashSet<Integer>();//set不包含重复的元素
        //这是一个泛型的写法，表示这个集合中只能保存integer类型的对象，其他对象无法保存，取出时也是直接是这个integer对象，不需要强转，方便写入写出。
        Random random = new Random();
        int[] array = new int[len];
        int num = 0;
        for(;true;){
            num = random.nextInt(100);//random.nextInt(100);产生一个0~99的随机数
            set.add(num);
            if(set.size()>=20){
                break;
            }
        }
        int i=0;
        for(int a : set){
            array[i] = a;
            i++;
        }
        return array;
    }
}
