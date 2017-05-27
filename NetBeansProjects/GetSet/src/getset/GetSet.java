// Julius Morgan A. Umacob
// MP2 - Ready, Get Set

package getset;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class GetSet {
    public static ArrayList <String> input = new ArrayList();
    public static File file = new File("umacob2.out");
    public static LinkedList list1;
    public static LinkedList list2;
    public static LinkedList unite, inter;
    public static int type = 0, testcase = 0, cases = 0;
    
    public static ArrayList fileRead(File file){
        try{
            BufferedReader br = new BufferedReader(new FileReader(file));
         	String line;
                int i = 0;
         	while ((line = br.readLine()) != null) {
                    //concat  = concat + line + " ";
                     input.add(line);
                    i++;
                }
      	}catch(Exception e){
         	e.printStackTrace();
      	}
//        for(int i=0; i<input.size(); i++){
//            System.out.println(input.get(i).toString());
//        }
        cases = Integer.parseInt(input.get(0));
        input.remove(0);
        return input;
    }
    public static ArrayList extract(){
        ArrayList<String> list = new ArrayList();
        type = Integer.parseInt(input.get(0));
        testcase = Integer.parseInt(input.get(3));
        for(int i = 0; i < 4 + testcase; i++){ //extraction 
            list.add(input.get(i));
        }
        for(int i = 0; i < 4 + testcase; i++){ // deletion of extracted parts from the main inputs
            input.remove(0);
        }
//        System.out.println("Extracted: ");
//        for(int i=0; i<list.size(); i++){
//            System.out.println(list.get(i).toString());
//        }
        
//        System.out.println("\nInputs Left: ");
//        for(int i=0; i<input.size(); i++){
//            System.out.println(input.get(i).toString());
//        }
        return list;
    }
    public static void identifyInput(ArrayList l){
        String[] l1 = l.get(1).toString().split("\\s+");
        String[] l2 = l.get(2).toString().split("\\s+");
        String[] test = {};
        switch(type){
            case 1: //int
            {   
                list1 = new LinkedList <Integer>();
                list2 = new LinkedList <Integer>();
                unite = new LinkedList <Integer>();
                inter = new LinkedList <Integer>();
                for(int i = 0; i<l1.length; i++){
                    list1.add(Integer.parseInt(l1[i]));
//                    System.out.println("Node inserted: " + Integer.parseInt(l1[i]));
                }
                for(int i = 0; i<l2.length; i++){
                    list2.add(Integer.parseInt(l2[i]));
//                    System.out.println("Node inserted: " + Integer.parseInt(l2[i]));
                }
                break;
            }
            case 2: //double
            {   
                list1 = new LinkedList <Double>();
                list2 = new LinkedList <Double>();
                unite = new LinkedList <Double>();
                inter = new LinkedList <Double>();
                for(int i = 0; i<l1.length; i++){
                    list1.add(Double.parseDouble(l1[i]));
//                    System.out.println("Node inserted: " + Integer.parseInt(l1[i]));
                }
                for(int i = 0; i<l2.length; i++){
                    list2.add(Double.parseDouble(l2[i]));
//                    System.out.println("Node inserted: " + Integer.parseInt(l2[i]));
                }
                break;
            }
            case 3: //char
            {   
                list1 = new LinkedList <Character>();
                list2 = new LinkedList <Character>();
                unite = new LinkedList <Character>();
                inter = new LinkedList <Character>();
                for(int i = 0; i<l1.length; i++){
                    list1.add(l1[i]);
//                    System.out.println("Node inserted: " + Integer.parseInt(l1[i]));
                }
                for(int i = 0; i<l2.length; i++){
                    list2.add(l2[i]);
//                    System.out.println("Node inserted: " + Integer.parseInt(l2[i]));
                }
                break;
            }
            case 4: //string
            {   
                list1 = new LinkedList <String>();
                list2 = new LinkedList <String>();
                unite = new LinkedList <String>();
                inter = new LinkedList <String>();
                for(int i = 0; i<l1.length; i++){
                    list1.add(l1[i].toString());
//                    System.out.println("Node inserted: " + Integer.parseInt(l1[i]));
                }
                for(int i = 0; i<l2.length; i++){
                    list2.add(l2[i].toString());
//                    System.out.println("Node inserted: " + Integer.parseInt(l2[i]));
                }
                break;
            }
            case 5: //set
                break;
            case 6: //object
            {   
                list1 = new LinkedList <Object>();
                list2 = new LinkedList <Object>();
                unite = new LinkedList <Object>();
                inter = new LinkedList <Object>();
                for(int i = 0; i<l1.length; i++){
                    list1.add(l1[i]);
//                    System.out.println("Node inserted: " + Integer.parseInt(l1[i]));
                }
                for(int i = 0; i<l2.length; i++){
                    list2.add(l2[i]);
//                    System.out.println("Node inserted: " + Integer.parseInt(l2[i]));
                }
                break;
            }
            default:
                System.out.println("Invalid type!");
        }
        
        for(int i = 4; i < l.size(); i++){ // Test Cases
            test = l.get(i).toString().split("\\s+");
            switch(Integer.parseInt(test[0])){
                case 1:{ //insert
                    insertElement(test);
                    break;
                }
                case 2:{ //remove
                    removeElement(test);
                    break;
                }
                case 3:{ //subset
                    subset();
                    break;
                }
                case 4:{ //union
                    union();
                    break;
                }
                case 5:{ //intersection
                    intersection();
                    break;
                }
                case 6:{ //set difference
                    setDifference();
                    break;
                }
                case 7:{ //power set
                    powerSet(test);
                    break;
                }
                default:
                    System.out.println("Invalid Test Case!");
            }
        }
    }
    public static void insertElement(String[] s){
        boolean flag = false;
        switch(Integer.parseInt(s[1].toString())){
            case 1:{ //insert in list1
                Node list = list1.head;
                for(int i = 2; i<s.length; i++){
                    while(list != null){
                        if(list.item.toString().equals(s[i])){
                            flag = true;
                        }
                        list = list.next;
                    }
                    if(!(flag)){
                        list1.add(s[i]);
                    }
                }
                list = list1.head;
                String w = "{";
                System.out.print("{");
                while(list != null){
                    if(list.next != null){
                        w = w + list.item.toString() + ",";
                        System.out.print(list.item + ",");
                    } else{
                        w = w + list.item.toString();
                        System.out.print(list.item);
                    }
                    list = list.next;
                }
                w = w + "}";
                System.out.print("}\n");
                FileWriter(w);
                break;
            }
            case 2:{ //insert in list2
                Node list = list2.head;
                for(int i = 2; i<s.length; i++){
                    while(list != null){
                        if(list.item.toString().equals(s[i])){
                            flag = true;
                        }
                        list = list.next;
                    }
                    if(!(flag)){
                        list2.add(s[i]);
                    }
                }
                list = list2.head;
                String w = "{";
                System.out.print("{");
                while(list != null){
                    if(list.next != null){
                        w = w + list.item.toString() + ",";
                        System.out.print(list.item + ",");
                    } else{
                        w = w + list.item.toString();
                        System.out.print(list.item);
                    }
                    list = list.next;
                }
                w = w + "}";
                System.out.print("}\n");
                FileWriter(w);
                break;
            }
            default:{
                System.out.println("Invalid Set Number!");
            }
        }
    }
    public static void removeElement(String[] s){
        switch(Integer.parseInt(s[1].toString())){
            case 1:{ //remove in list1
                Node list = list1.head, prev = null;
                if(list1.head != null){
                    for(int i = 2, c = 1; i<s.length; i++, c++){
                        while(list != null){
                            if(list.item.toString().equals(s[i])){
                                //if remove first                        
                                if(c == 1 && list.item.toString().equals(s[i])){
                                    list1.head = list1.head.next;
                                }else{
                                    prev.next = list.next;
                                }
                            } else{
                                prev = list;
                            }
                            list = list.next;
                        }
                    }
                }
                list = list1.head;
                String w = "{";
                System.out.print("{");
                while(list != null){
                    if(list.next != null){
                        w = w + list.item.toString() + ",";
                        System.out.print(list.item + ",");
                    } else{
                        w = w + list.item.toString();
                        System.out.print(list.item);
                    }
                    list = list.next;
                }
                w = w + "}";
                System.out.print("}\n");
                FileWriter(w);
                break;
            }
            case 2:{ //remove in list2
                Node list = list2.head, prev = null;
                if(list2.head != null){
                    for(int i = 2, c = 1; i<s.length; i++, c++){
                        while(list != null){
                            if(list.item.toString().equals(s[i])){
                                //if remove first                        
                                if(c == 1 && list.item.toString().equals(s[i])){
                                    list2.head = list2.head.next;
                                }else{
                                    prev.next = list.next;
                                }
                            } else{
                                prev = list;
                            }
                            list = list.next;
                        }
                    }
                }
                list = list2.head;
                String w = "{";
                System.out.print("{");
                while(list != null){
                    if(list.next != null){
                        w = w + list.item.toString() + ",";
                        System.out.print(list.item + ",");
                    } else{
                        w = w + list.item.toString();
                        System.out.print(list.item);
                    }
                    list = list.next;
                }
                w = w + "}";
                System.out.print("}\n");
                FileWriter(w);
                break;
            }
            default:{
                System.out.println("Invalid Set Number!");
            }
        }
    }
    public static void union(){
        Node n = unite.head, temp = list1.head;
        boolean flag = false;
        while(temp != null){
            while(n != null){
                if(temp.item.equals(n.item)){
                    flag = true;
                }
                n = n.next;
            }
            if(!(flag)){
                unite.add(temp.item);
            }
            temp = temp.next;
            n = unite.head;
            flag = false;
        }
        temp = list2.head;
        n = unite.head;
        while(temp != null){
            while(n != null){
                if(temp.item.equals(n.item)){
                    flag = true;
                }
                n = n.next;
            }
            if(!(flag)){
                unite.add(temp.item);
            }
            n = unite.head;
            temp = temp.next;
            flag = false;
        }
        n = unite.head;
        String w = "{";
        System.out.print("{");
        while(n != null){
            if(n.next != null){
                w = w + n.item.toString() + ",";
                System.out.print(n.item + ",");
            } else{
                w = w + n.item.toString();
                System.out.print(n.item);
            }
            n = n.next;
        }
        w = w + "}";
        System.out.print("}\n");
        FileWriter(w);
    }
    public static void subset(){
        Node n = list2.head, temp = list1.head;
        int flag = 0;
        
        while(temp != null){
            while(n != null){
                if(temp.item.equals(n.item)){
                    flag++;
                }
                n = n.next;
            }
            n = list2.head;
            temp = temp.next;
        }
        if(flag == list2.length()){
            FileWriter("true");
            System.out.println("true");
        }else{
            FileWriter("false");
            System.out.println("false");
        }
    }
    public static void intersection(){
        Node n = list2.head, temp = list1.head;
        int flag = 0;
        
        while(temp != null){
            while(n != null){
                if(temp.item.equals(n.item)){
                    inter.add(n.item);
                }
                n = n.next;
            }
            n = list2.head;
            temp = temp.next;
        }
        n = inter.head;
        String w = "{";
        System.out.print("{");
        while(n != null){
            if(n.next != null){
                w = w + n.item.toString()  + ",";
                System.out.print(n.item + ",");
            } else{
                w = w + n.item.toString();
                System.out.print(n.item);
            }
            n = n.next;
        }
        w = w + "}";
        System.out.print("}\n");
        FileWriter(w);
    }
    public static void setDifference(){
        Node n = list1.head, temp = list2.head, prev = null;
        int flag = 0;
        
        while(temp != null){
            while(n != null){
                if(temp.item.equals(n.item)){
                    prev.next = n.next;
                } else{
                    prev = n;
                }
                n = n.next;
            }
            n = list1.head;
            temp = temp.next;
        }
        String w = "{";
        System.out.print("{");
        n = list1.head;
        while(n != null){
            if(n.next != null){
                w = w + n.item.toString() + ",";
                System.out.print(n.item + ",");
            } else{
                w = w + n.item.toString();
                System.out.print(n.item);
            }
            n = n.next;
        }
        w = w + "}";
        System.out.print("}\n");
        FileWriter(w);
    }
    public static void powerSet(String[] s){
//        ArrayList<String> set = new ArrayList();
//        System.out.print("{empty"); //outer start-brace
//        int c = list1.size;
//        Node n = list1.head, m = list2.head;
//        n = list1.head;
//        if(n != null){
//            n = list1.head;
//            while(n != null){
//                set.add(n.item.toString());
//                n = n.next;
//            }
//            for(int i = 2; i< c; i++){
//            
//            }
//            
//        }
////        if(m != null){
////            System.out.print(",{");
////            while(m != null){
////                if(m.next != null){
////                    System.out.print(m.item + ",");
////                } else{
////                    System.out.print(m.item);
////                }
////                m = m.next;
////            }
////            System.out.print("}");
////        }
//        System.out.print("}\n"); //outer end-brace
    }
    public static void FileWriter(String s){
    	PrintWriter out = null;
		try 
		{
		    out = new PrintWriter(new BufferedWriter(new FileWriter(file, true)));
		    out.println(s);
		}
		catch (IOException e) 
		{
		    System.err.println(e);
		}
		finally
		{
		    if(out != null)
		    {
		        out.close();
		    }
		} 
    }
    
    public static void main(String[] args) {
        File file = new File("mpa2.in");
        int count = 0;
        ArrayList input = fileRead(file), l;
//        ArrayList extr = extract();
//        identifyInput(extract());
//        while(input.size() != 0){
//            l = extract();
//        }
        while(count < cases-1){
            identifyInput(extract());
            count++;
        }
    }

    private static class LinkedList<T>{
        Node head, tail;
        int size;

       public LinkedList(){
            size = 0;
            head = null;
            tail = null;
       } 


       public boolean isEmpty() {
        return size == 0;
      }

      /**
       *  length() returns the length of this list.
       *  @return the length of this list.
       **/

      public int length() {
        return size;
      }

      /**
       *  insertFront() inserts item "obj" at the beginning of this list.
       *  @param obj the item to be inserted.
       **/

      public void insertFront(T obj) {

          if(head == null){
              head = new Node(obj);
              tail = head;
          }
          else{
              head = new Node(obj, head);
          }
        size++;
      }

      /**
       *  insertEnd() inserts item "obj" at the end of this list.
       *  @param obj the item to be inserted.
       **/

      /*public void insertEnd(Object obj) {
        if (head == null) {
          head = new Node(obj);
        } else {
          Node node = head;
          while (node.next != null) {
            node = node.next;
          }
          node.next = new Node(obj);
        }
        size++;
      }*/

       public void add(T obj) {
            if (head == null){
                head = new Node(obj);
                tail = head;
            }
            else{
                Node node = tail;
                tail.next = new Node(obj);
                tail = tail.next;
            }
            size++;
        }
       public void removeFirst() {
                if (head == null)
                      return;
                else {
                      if (head == tail) {
                            head = null;
                            tail = null;
                      } else {
                            head = head.next;
                      }
                }
          }
       public void removeLast() {
                if (tail == null)
                      return;
                else {
                      if (head == tail) {
                            head = null;
                            tail = null;
                      } else {
                            Node previousToTail = head;
                            while (previousToTail.next != tail)
                                 previousToTail = previousToTail.next;
                            tail = previousToTail;
                            tail.next = null;
                      }
                }
          }

      /**
       *  nth() returns the item at the specified position.  If position < 1 or
       *  position > this.length(), null is returned.  Otherwise, the item at
       *  position "position" is returned.  The list does not change.
       *  @param position the desired position, from 1 to length(), in the list.
       *  @return the item at the given position in the list.
       **/

      public Object nth(int position) {
        Node currentNode;

        if ((position < 1) || (head == null)) {
          return null;
        } else {
          currentNode = head;
          while (position > 1) {
            currentNode = currentNode.next;
            if (currentNode == null) {
              return null;
            }
            position--;
          }
          return currentNode.item;
        }
      } 

      /**
       *  toString() converts the list to a String.
       *  @return a String representation of the list.
       **/

      public String toString() {
        int i;
        Object obj;
        String result = "[  ";

        Node cur = head;

        while (cur != null) {
          obj = cur.item;
          result = result + obj.toString() + "  ";
          cur = cur.next;
        }
        result = result + "]";
        return result;
      }
    }

    private static class Node<T>{
        // reference to the next node in the chain,
        // or null if there isn't one.
        T item;
        // data carried by this node.
        // could be of any type you need.
        Node next;

        // Node constructor
        Node(){
        item = null;
        this.next = null;
        }
        Node(T obj, Node next) {
        item = obj;
        this.next = next;
        }

            // another Node constructor if we want to
            // specify the node to point to.
        Node(T obj) {
        this(obj, null);
        }
    }
    
}
