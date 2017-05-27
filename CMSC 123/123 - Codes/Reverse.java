class SListNode {
	Object item;
  SListNode next;

  SListNode(Object item) {
    this.item = item;
  }

  static void printing(SListNode L) {
    while(L != null) {
      System.out.println(L.item);
      L = L.next;
    }
  }

  static SListNode reverseRec(SListNode L) {
    SListNode temp = L;
    
    if(temp == null || temp.next == null) { 
      return L;
    } else {
      L = reverseRec(temp.next);
      temp.next.next = temp;
      temp.next = null;
      return L;
    }
  }

  static SListNode reverse(SListNode L) {
  	SListNode a = null;
  	SListNode prev = null;
    SListNode temp = L;

  	while(temp !=  null) {
  		prev = a; 
      a = new SListNode(temp.item);
  		a.next = prev; 
  		temp = temp.next;
  	}
  	return a;
  }

 	public static void main(String[] args){
 		SListNode a = new SListNode(1);
 		SListNode b = new SListNode(2);
 		SListNode c = new SListNode(3);
    SListNode d = new SListNode(4);

 		a.next = b;
 		b.next = c;
    c.next = d;
    
    SListNode recrev = SListNode.reverseRec(a);
    SListNode.printing(recrev);
 	}
}