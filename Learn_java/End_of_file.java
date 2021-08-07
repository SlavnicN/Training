import java.io.*;
import java.util.*;

public class End_of_file{

    public static void main(String[] args) {
    int i = 0;    
    Scanner sc = new Scanner(System.in);
    while(sc.hasNext()){
        i++;
        System.out.println(i + " " + sc.nextLine());
    }
    sc.close();
 }
}