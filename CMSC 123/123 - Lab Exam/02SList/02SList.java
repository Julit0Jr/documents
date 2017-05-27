public class SList {

  private SListNode head;
  private int size;

  /**
   *  SList() constructs an empty list.
   **/

  public SList() {
    size = 0;
    head = null;
  }

  /**
   *  isEmpty() indicates whether the list is empty.
   *  @return true if the list is empty, false otherwise.
   **/

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

  public void insertFront(Object obj) {
    head = new SListNode(obj, head);
    size++;
  }

  public SListNode getHead(){
    return head;
  }

  
  /**
   *  toString() converts the list to a String.
   *  @return a String representation of the list.
   **/

  public String toString() {
    int i;
    Object obj;
    String result = "[  ";

    SListNode cur = head;

    while (cur != null) {
      obj = cur.item;
      result = result + obj.toString() + "  ";
      cur = cur.next;
    }
    result = result + "]";
    return result;
  }

  
  /** return the reverse of L (destructively).
* (ie. mutate the old list and return the new
* head of the list)
*/
 static SListNode reverse (SListNode L) {
  //Fill in your code here.
}



  /**
   *  main() runs test cases on the SList class.  Prints summary
   *  information on basic operations and halts with an error (and a stack
   *  trace) if any of the tests fail.
   **/

  public static void main (String[] args) {
      SList L = new SList();
      L.insertFront("1");
      L.insertFront("2");
      L.insertFront("3");
      L.insertFront("4");
      System.out.println(L);
      SListNode node = SList.reverse(L.getHead());
      if(node != null){
        while(node.next!=null){
          System.out.print(node.item+" ");
          node = node.next;
        }
        System.out.print(node.item+" ");  
      }
      System.out.println(" should be 1 2 3 4");

      L = new SList();
      L.insertFront("1");
      System.out.println(L);
      node = SList.reverse(L.getHead());
      if(node != null){
        while(node.next!=null){
          System.out.print(node.item+" ");
          node = node.next;
        }
        System.out.print(node.item+" ");  
      }
      System.out.println(" should be 1");

      L = new SList();
      System.out.println(L);
      node = SList.reverse(L.getHead());
      if(node != null){
        while(node.next!=null){
          System.out.print(node.item+" ");
          node = node.next;
        }
        System.out.print(node.item+" ");  
      }
      System.out.println(" should be ");
  }

    
}
