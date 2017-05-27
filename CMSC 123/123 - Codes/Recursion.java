class Recursion {
	Object item;
  	SListNode next;

	static void printing(SListNode L) {
    while(L != null) {
      System.out.println(L.item);
      L = L.next;
    }
  }  
}