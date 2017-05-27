/* BadTransactionException.java */

/**
 *  Implements an exception that should be thrown for nonexistent accounts.
 **/
public class BadTransactionException extends Exception {

  public int accountValue;  // The invalid account number.
  /**
   *  Creates an exception object for nonexistent account "invalidNumber".
   **/
  public BadTransactionException(int invalidNumber) {
    super("Invalid amount: " + invalidNumber);
    accountValue = invalidNumber;
  }
}