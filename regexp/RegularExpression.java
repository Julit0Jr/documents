import java.io.*;
import java.util.*;

public class RegularExpression {
	public static ArrayList  <String> input = new ArrayList();
	public static String expression = "";
	public static File file = new File("umacob.out");
	public static int cases = 0, operation = 0;
	public static void fileRead(File file){
        try{
            BufferedReader br = new BufferedReader(new FileReader(file));
         	String line;
            int i = 0;

         	while ((line = br.readLine()) != null) {
                    //concat  = concat + line + " ";
                    input.add(line);
                    i++;
            }
      	}
        catch(Exception e){
         	e.printStackTrace();
      	}

        cases = Integer.parseInt(input.get(0));
        input.remove(0);
    }
    public static ArrayList extract(){
        ArrayList<String> list = new ArrayList();

        operation = Integer.parseInt(input.get(1));

        expression = input.get(0).toString(); //store the regular expression in the expression variable

        for(int i = 2; i < 2 + operation; i++){ //extraction 
            list.add(input.get(i));

        }

        for(int i = 0; i < 2 + operation; i++){ // deletion of extracted parts from the main inputs
            input.remove(0);

        }

        return list;
    }
    public static void fileWriter(String s){
        PrintWriter out = null;

        try{
            out = new PrintWriter(new BufferedWriter(new FileWriter(file, true)));
            out.println(s);
        }
        catch (IOException e){
            System.err.println(e);

        }
        finally{
            if(out != null){
                out.close();
            }

        } 
    }

    public static void main(String[] args) {
    	File file = new File("mp3.in");
        int count = 0;

        fileRead(file);

        for(int x = 0; x <input.size(); x++){
            ArrayList extr = extract();

            for(int i = 0; i < extr.size(); i++){

                if(!(expression.contains("U") || expression.contains("(") || expression.contains(")"))){
                    State beginstate = NFA.post2nfa(Postfix.in2post(expression));
                    Boolean element = NFAsimulation.simulateNFA(beginstate, extr.get(i).toString());

                    if(element){
                        fileWriter("yes");
                        System.out.println("yes");

                    }
                    else{
                        fileWriter("no");
                        System.out.println("no");

                    }
                }
                else{
                    fileWriter("wa mahuman huhu");
                    System.out.println("wa mahuman huhu");

                }
            }
        }
    }
}

class Fragment {
    private State start;
    private ArrayList <State> oArrows;
    public Fragment(State start, State out){
        this.oArrows = new ArrayList<State>();
        oArrows.add(out);
        this.start = start;
    }
    public Fragment(State start, ArrayList oArrows){
        this.oArrows = oArrows;
        this.start = start;
    }
    public Fragment(){
        start = null;
        oArrows = null;
    }
    public State getStart(){
        return start;
    }
    public ArrayList getoArrows(){
        return oArrows;
    }
}
class NFA {
    public static State post2nfa(String postfix){
        Stack <Fragment> fragmentStack = new Stack <Fragment> ();
        Fragment completeNfa = new Fragment();
        State matchstate = new State();
        for (int i = 0; i < postfix.length(); i++){
            char c = postfix.charAt(i);
            if(isLiteral(c)){
                State literalState = new State(c);
                fragmentStack.push(new Fragment(literalState, literalState));
            }
            else if (isConcatenation(c)){
                Fragment prev2 = fragmentStack.pop();
                Fragment prev1 = fragmentStack.pop();
                patchFragmentToAState(prev1, prev2.getStart());
                fragmentStack.push(new Fragment(prev1.getStart(), prev2.getoArrows() ) );
            }
            else if (isAlternation(c)){
                Fragment prev2 = fragmentStack.pop();
                Fragment prev1 = fragmentStack.pop();
                State newState = new State(prev1.getStart(), prev2.getStart());
                fragmentStack.push(new Fragment(newState, appendoArrows(prev1.getoArrows(), prev2.getoArrows())));
            }
            else if (isStar(c)){
                Fragment prev = fragmentStack.pop();
                State newState = new State(prev.getStart(), null);
                patchFragmentToAState(prev, newState);
                fragmentStack.push(new Fragment(newState, newState));

            }
        }
        completeNfa = fragmentStack.pop();
        patchFragmentToAState(completeNfa, matchstate);
        return completeNfa.getStart();
    }

    private static boolean isLiteral(char c) {
        return !isConcatenation(c) && !isAlternation(c) && !isStar(c);
    }

    private static boolean isStar(char c) {
        return c == '*';
    }

    private static boolean isAlternation(char c) {
        return c == 'U';
    }

    private static boolean isConcatenation(char c) {
        return c == '.';
    }
    private static ArrayList<State> appendoArrows(ArrayList<State> a, ArrayList<State> b){
        ArrayList <State> appended = new ArrayList <State> ();
        for (int i = 0; i < a.size(); i++){
            appended.add(a.get(i));
        }
        for (int i = 0; i < b.size(); i++){
            appended.add(b.get(i));
        }
        return appended;
    }
    private static void patchFragmentToAState(Fragment a, State s){
        ArrayList<State> toBePatched = a.getoArrows();
        for (int i = 0; i < toBePatched.size(); i++){
            State openarrows = toBePatched.get(i);
            openarrows.patch(s);
        }
    }
}

class NFAsimulation {
    public static boolean simulateNFA(State startstate, String input){
        ArrayList <State> currentList = new ArrayList<State> ();
        ArrayList <State> nextList = new ArrayList<State> ();
        int listID = 0;
        addState(currentList, startstate, listID);
        for (int i = 0; i < input.length(); i++){
            char c = input.charAt(i);
            listID = step(currentList, c, nextList, listID);
            currentList = nextList;
            nextList = new ArrayList<State>();
        }
        return containsMatchState(currentList);
    }
    private static boolean containsMatchState(ArrayList<State> finalList){
        for (int i = 0; i < finalList.size(); i++){
            State s = finalList.get(i);
            if (s.isMatch()){
                return true;
            }
        }
        return false;
    }
    private static int step(ArrayList<State> currentList, char c, ArrayList<State> nextList, int listID){
        listID++;
        for (int i = 0; i < currentList.size(); i++){
            State s = currentList.get(i);
            if(c == s.getChar()){
                addState(nextList, s.getOut1(), listID);
            }
        }
        return listID;
    }
    private static void addState(ArrayList<State> list, State s, int listID){
        if (s == null || s.getLastlist() == listID)
            return;
        s.setLastlist(listID);
        if(s.isSplit()){
            addState(list, s.getOut1(), listID);
            addState(list, s.getOut2(), listID);
            return;
        }
        list.add(s);
    }
}

class Postfix {
    public static String in2post(String input){
        input = addConcatenations(input);
        Stack <Character> operatorStack = new Stack<Character>();
        StringBuffer outputString = new StringBuffer();
        for(int i = 0; i < input.length(); i++){
            char c = input.charAt(i);
            if(isAnOperator(c)){
                if(operatorStack.isEmpty()){
                     operatorStack.push(c);
                }
                else{
                    char topOfStack = operatorStack.peek();
                    if(isAnOperator(topOfStack)){
                        int presedenceValue = precedence(c, topOfStack);
                        if (presedenceValue <= 0){
                            topOfStack = operatorStack.pop();
                            outputString.append(topOfStack);
                        }
                    }
                    operatorStack.push(c);
                }
            }


           else if(isOpenParenthesis(c)){
               operatorStack.push(c);

            }


           else if(isCloseParenthesis(c)){
               char topOfStack = operatorStack.pop();
               while(!isOpenParenthesis(topOfStack)){
                   outputString.append(topOfStack);
                   topOfStack = operatorStack.pop();
               }
            }
            else{
                outputString.append(c);
            }
        }
        while(!operatorStack.isEmpty()){
            outputString.append(operatorStack.pop());
        }
        return outputString.toString();
    }

    public static String addConcatenations(String original){
        StringBuffer withConcatenations = new StringBuffer();
        withConcatenations.append(original.charAt(0));

        for(int i = 1; i < original.length(); i++){
            char c = original.charAt(i);
            if(possibleConcatenation(withConcatenations))
                if(isCharacter(c) || isOpenParenthesis(c))
                    withConcatenations.append('.');
            withConcatenations.append(c);

        }
        return withConcatenations.toString();

    }



    private static int precedence(char a, char b){
        if(isMultiplication(a)){
            if(isMultiplication(b))
                return 0;
            else
                return 1;
        }

        else if(isConcatenation(a)){
            if(isMultiplication(b))
                return -1;
            else if (b == a)
                return 0;
            else
                return 1;
        }

        else if(isAlternation(a)){
            if(a == b)
                return 0;
            else return -1;
        }

        return -2;
    }
    private static boolean possibleConcatenation(StringBuffer withConcatenations) {
        return isCharacter(withConcatenations.charAt(withConcatenations.length() - 1))
                || isCloseParenthesis(withConcatenations.charAt(withConcatenations.length() - 1))
                || isMultiplication(withConcatenations.charAt(withConcatenations.length() - 1));
    }
    private static boolean isCharacter(char a){
        return !isAnOperator(a) && !isCloseParenthesis(a) && !isOpenParenthesis(a);
    }
    private static boolean isAlternation(char a) {
        return a == 'U';
    }

    private static boolean isConcatenation(char a) {
        return a == '.';
    }

    private static boolean isMultiplication(char a) {
        return a == '*' || a == '+' || a == '?';
    }
    private static boolean isAnOperator(char a){
        return a == '*' || a == '+' || a == '?' || a == 'U' ||a == '.';
    }

    private static boolean isCloseParenthesis(char c) {
        return c == ')';
    }

    private static boolean isOpenParenthesis(char c) {
        return c == '(';
    }
}
class State {
    private char c;
    private State out1;
    private State out2;
    private boolean split;
    private boolean match;
    private boolean hasChar;
    private int lastlist;
    /**
     * Initializes a new literal state with one outgoing transition labelled with the given character.
     * @param c the label for the outgoing transition
     */
    public State(char c){
        this.c = c;
        this.out1 = null;
        this.out2 = null;
        this.hasChar = true;
        this.split = false;
        this.match = false;
        this.lastlist = -1;
    }
    /**
     * Initializes a new split state with two outgoing free transitions to the given two states.
     * @param out1 The state in the end of the first free transition
     * @param out2 The state in the end of the second free transition
     */
    public State(State out1, State out2){
        this.hasChar = false;
        this.split = true;
        this.match = false;
        this.out1 = out1;
        this.out2 = out2;
        this.lastlist = -1;
    }
    /**
     * Initializes a new match state with no outgoing transitions.
     */
    public State(){
        this.hasChar = false;
        this.split = false;
        this.match = true;
        this.out1 = null;
        this.out2 = null;
        this.lastlist = -1;
    }
    /**
     *
     * @return true, if the state is a literal state, otherwise false
     */
    public boolean isLiteralState(){
        return hasChar;
    }
    /**
     * Returns the character associated with a literal state. No error checking, so check if the state
     * is a literal state before using.
     * @return the character associated with a literal state.
     */
    public char getChar(){
        return c;
    }
    /**
     *
     * @return true, if the state is a split state, otherwise false.
     */
    public boolean isSplit(){
        return split;
    }
    /**
     *
     * @return true, if the state is a match state.
     */
    public boolean isMatch(){
        return match;
    }
    /**
     *
     * @return the state in the end of the first transition
     */
    public State getOut1(){
        return out1;
    }
    /**
     *
     * @return the state in the end of the second transition.
     */
    public State getOut2(){
        return out2;
    }
    public void patch(State s){
        if(out1 == null)
            out1 = s;
        if(out2 == null && split)
            out2 = s;
    }
    public int getLastlist(){
        return lastlist;
    }
    /**
     * Sets the lastlist variable to the specified parameter
     * @param listindex the generation number of a list of current states
     */
    public void setLastlist(int listindex){
        lastlist = listindex;
    }
    // public void testPrint(){
    //     if(split)
    //         System.out.println("Split");
    //     else if (match)
    //         System.out.println("Match");
    //     else
    //         System.out.println(c);
    // }
}