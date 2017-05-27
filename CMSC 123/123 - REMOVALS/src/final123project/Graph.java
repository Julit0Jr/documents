package final123project;
import java.io.*;
import java.util.*;

public class Graph {
    public static Stops[][] PATH;
    public static int nop;
    
    public Graph() throws Exception{
        Generatefromfiles.generateLandmarks();
        Generatefromfiles.generateListsofPUJ();
        nop = Generatefromfiles.LANDMARKS.size();
        initialize();
        Generatefromfiles.generateRoute();        
        recheckEdges();
        recheckJeep();
    }
    
    public static void initialize() {
        PATH = new Stops[nop][nop];
        for(int i = 0; i < nop; i++) {
            for(int j = 0; j < nop; j++) {
                PATH[i][j] = new Stops();
            } 
        }
    }
    
    public static void addEdge(String jeepname, ArrayList<String> jr) {
        String place01 = "", place02 = "";
        for(int i = 0; i < jr.size(); i++) {
            place01 = jr.get(i);
            int idx01 = Generatefromfiles.getIndex(place01);
            if(i+1 < jr.size()) {
                place02 = jr.get(i+1);
                int idx02 = Generatefromfiles.getIndex(place02);
                addEdge(jeepname, idx01, idx02);
            }
        }
    }
    
    public static void addEdge(String je, int or, int de){
        if(validVertex(or) && validVertex(de)){
            if(!PATH[or][de].adj)
                PATH[or][de].adj = true;
           PATH[or][de].addJEEP(je); //para mag add jeep ra siya
        }
    }
    
    public static boolean validVertex(int v){
        return (v >= 0) && (v < Generatefromfiles.LANDMARKS.size());
    }
    
    
    //returns the list of adjacent places of a specific place
    public static ArrayList<String> getAdjacentPlaces(String place) {
        ArrayList<String> places = new ArrayList<>();
        int pidx = Generatefromfiles.getIndex(place);
        for(int i = 0; i < Generatefromfiles.LANDMARKS.size(); i++) {
            if(PATH[pidx][i].adj) {
                    places.add(Generatefromfiles.LANDMARKS.get(i));
            }
        }
        return places;
    }
    
    //check the PATH if the LANDMARKS are already connected to one another
    public static void recheckEdges(){
        for(int i=0; i<nop; i++){
           ArrayList<String> adA = getAdjacentPlaces(Generatefromfiles.LANDMARKS.get(i));
            for(int j=0; j < nop; j++){
                ArrayList<String> adB = getAdjacentPlaces(Generatefromfiles.LANDMARKS.get(j));
                if(adA.contains(Generatefromfiles.LANDMARKS.get(j)) && !adB.contains(Generatefromfiles.LANDMARKS.get(i))){
                    PATH[j][i].adj = true; //if di ma adjacent kay di ma true ang adjacency
                } if(adB.contains(Generatefromfiles.LANDMARKS.get(i)) && !adA.contains(Generatefromfiles.LANDMARKS.get(j))){
                    PATH[i][j].adj = true;
                }
            }
        }
    }
    
    public static void recheckJeep() throws Exception{
        for(int k = 0; k < nop; k++){
            for(int j = 0; j < nop; j++){
                if(PATH[k][j].adj){
                    String place01 = Generatefromfiles.LANDMARKS.get(k);
                    String place02 = Generatefromfiles.LANDMARKS.get(j);
                    
                    for(int i = 0; i < Generatefromfiles.JEEPS.size(); i++){
                        String src = Generatefromfiles.JEEPS.get(i) + ".txt";
                        FileReader file = new FileReader(src);
                        Generatefromfiles.SCAN = new BufferedReader(file);
                        String s = "";
                        ArrayList<String> place = new ArrayList<>();
                         
                        while((s = Generatefromfiles.SCAN.readLine()) != null && place.size() < 2){
                            if(s.trim().equalsIgnoreCase(place01) || s.trim().equalsIgnoreCase(place02)){ //if the same
                                if(!place.contains(s))
                                    place.add(s); //add the place if found
                            }
                        }
                        if(place.size() == 2) //why 2? since the place A may be adj to C
                                              //and C is adjacent to A also there's an instance that
                                              //A is adj to C but C is not [directed graph]
                            PATH[k][j].addJEEP(Generatefromfiles.JEEPS.get(i)); //this part is needed PATH FOUND hehe  
                    }
                }
            }
        }
    }
    
    public String leastStop(String origin, String dest, String avoid){
        /*NOTE: It's not an ArrayList<ArrayList<Node>> for leastStop sir
        But only arrayList of NOde, i was so nervous during the board discussion
        and my mind was set on least transfer instead*/

        ArrayList<Node> fin = eachRoute(origin, dest, avoid);
        fin = trim(trim(trim(fin)));
        
        /*
        trimmed thrice since the places to check is by pair, like 
         if Place A and Place B then C. A jeepneys [1, 2, 3] then B [2, 3]
         jeepneys left is [2, 3] but it needs to be retrimmed since B has
         adjacent place C [3] so whats left is [3], third trim is just to make
         that it's trimmed properly
        */

        String x = "";
        x += "Minimum Stops: " + Integer.toString(fin.size()) +"\n\n";
        x += "Origin: " + origin + "\n";
        x += "Destination: " + dest + "\n\n";
        
        Node curr;
        ArrayList<String> j =  new ArrayList<>();
        
        for(int i = 0; i < fin.size(); i++){
            curr = fin.get(i);
            x += "\n" + curr.placeA + " -> " + curr.placeB;
            x += "\n";
            x += "      JEEPNEYS: [ ";
            for(String d : curr.jeep){ 
                j.add(d);
                x += d + " ";
            }
            x += " ]\n";
        }
        x += "\n";
        return x; 
    }
    
   
    public static ArrayList<Node> trim(ArrayList<Node> dir){
        for(int i = 1; i < dir.size(); i++){
        int sizeA = dir.get(i - 1).jeep.size();
        int sizeB = dir.get(i).jeep.size();
        if(sizeB < sizeA){
            ArrayList<String> base = dir.get(i - 1).jeep;
            ArrayList<String> retain = dir.get(i).jeep;
            ArrayList<String> copy = new ArrayList<>();
            for(String b : base)
              copy.add(b);
            copy.retainAll(retain);
            if(copy.size() > 0)
              dir.get(i - 1).jeep = copy;
        } else {
            ArrayList<String> retain = dir.get(i - 1).jeep;
            ArrayList<String> base = dir.get(i).jeep;
            ArrayList<String> copy = new ArrayList<>();
            for(String b : base)
              copy.add(b); 
            copy.retainAll(retain);
            if(copy.size() > 0)
              dir.get(i).jeep = copy; 
        } 
    }
        return dir;
    }
    
    public static ArrayList<Node> detailsOfDir(ArrayList<String> path){
  	ArrayList<Node> ar = new ArrayList<>();
  	String curr = path.get(0);
  	String next = "";

  	for(int i = 1; i < path.size(); i++){
  		next = path.get(i);
  		Node n = new Node(curr, next);
  		for(String j : jeepneys(curr, next))
                    n.addJeep(j);
            curr = next;
            ar.add(n);
  	}
  	return ar;
    }
  
    public static ArrayList<String> jeepneys(String curr, String next){
        ArrayList<String> jeep = new ArrayList<>();
        int idx1 = Generatefromfiles.getIndex(curr);
        int idx2 = Generatefromfiles.getIndex(next);
        for(String j : PATH[idx1][idx2].PUJ)
            jeep.add(j);
        return jeep;
    }
    
    public Place getPlace(ArrayList<Place> places, String place){
        if(place != null){
            for(Place p : places){
                if(p.place.equalsIgnoreCase(place))
                    return p;
            }
        }
        return null;
    }
    
    /*Finds all the possible routes from origin to destination before
    looking for the least transfer*/   
    public String leastTransfer(String origin, String dest, String avoid){
  	ArrayList<ArrayList<Node>> routes = allRoute(origin, dest, avoid);
    if(routes != null){
      for(ArrayList<Node> route : routes){
        route = trim(trim(trim(route)));
      }
      int min = 0;
      if(!routes.isEmpty()){
        min = numTransfer(routes.get(0));
      }
      
      for(ArrayList<Node> node : routes){
       int curr = numTransfer(node);
        if(curr < min){
          min = curr;
        }
      }

     String output = "";
     if(routes.isEmpty()){
       output = "Destination Can't Be Reached!";
     } else {
      output = "Minimum Transfer : " + min + "\n\n";
      output += "ORIGIN : " + origin;
      output += "\nDESTINATION : " + dest + "\n\n";
      ArrayList<ArrayList<Node>> lTransfer = new ArrayList<>();
      for(ArrayList<Node> node : routes){
       int curr = numTransfer(node);
        if(curr <= min){
          lTransfer.add(node);
        }
       }
      output += convertToString(lTransfer);
     }
     
     return output;
    } 
    return null;
  }
    
     public ArrayList<Node> eachRoute(String origin, String dest, String avoid){
    Map<String, Boolean> vis = new HashMap<String, Boolean>();
    ArrayList<Place> places = new ArrayList<>();
    ArrayList<String> directions = new ArrayList<>();
    Queue<String> q = new LinkedList<>();

    String current = origin;
    q.add(origin);
    vis.put(current, true);
    places.add(new Place(current, null));
    while(!q.isEmpty()){
   	  current = q.remove(); //caller for
   	  if(current.equalsIgnoreCase(dest)){
   		  break;
   	  } else {
   		  for(String n : getAdjacentPlaces(current)){ //String n (current)
   		   	if(!vis.containsKey(n) && !n.equalsIgnoreCase(avoid)){
   		   		  q.add(n);	
   		 		  vis.put(n, true);
            places.add(new Place(n, current));
   		 	  }
   		  }
   	  }
    }
   
   if(!current.equals(dest)){
     return null;
   }

	 for(Place start = getPlace(places, dest) ; start != null; start = getPlace(places, start.caller)){
	    directions.add(start.place);
	 }
   Collections.reverse(directions);
   return detailsOfDir(directions);
  }
    
     //kapila mu tranfer and node
     public int numTransfer(ArrayList<Node> node){
  	int trans = 0;
    for(int j = 1; j < node.size(); j++){
      if(!jeepEqual(node.get(j).jeep, node.get(j - 1).jeep)){
      	trans++;
      }
    }
    return trans;
  }
     
     //if the same jud ug jeep tanan
      public boolean jeepEqual(ArrayList<String> jeepA, ArrayList<String> jeepB){
  	if(jeepA.size() != jeepB.size()){
  		return false;
  	} else {
  		for(int i = 0 ; i < jeepA.size(); i++){
  			if(!(jeepA.get(i).replaceAll(" ", "").equalsIgnoreCase(jeepB.get(i).replaceAll(" ", "")))){
  				return false;
  			}
  		}
  		return true;
  	}
  }
      
   

  //traverse each Lists of an ArrayList of Node
  public boolean exist(ArrayList<ArrayList<Node>> routes, ArrayList<Node> nodes){
    for(ArrayList<Node> route : routes){
    	boolean exist = existEach(route, nodes);
    	if(exist){
    		return exist;
    	}
    }
    return false;
  }


  //if the the places are found in the routes
  //Up-Lahug-It & Up-Lahug-It
  private boolean existEach(ArrayList<Node> routeA, ArrayList<Node> routeB){
  	if(routeA.size() != routeB.size()){
  		return false;
  	} else {
  		for(int i = 0; i < routeA.size(); i++){
  			if(!(routeA.get(i).placeA.equals(routeB.get(i).placeA))
  				|| !(routeA.get(i).placeB.equals(routeB.get(i).placeB))){
  					return false;
  				}
  		}
  		return true;
  	}
  }
  
   public String convertToString(ArrayList<ArrayList<Node>> nodes){
    String output = "";
    for(ArrayList<Node> n : nodes){
      output += print(n) + "\n";
    }
    return output;                                                                                          
  }
   
    public static String print(ArrayList<Node> s){
  	String x = "";
    Node curr;
    ArrayList<String> j =  new ArrayList<>();
    for(int i = 0; i < s.size(); i++){
  		curr = s.get(i);
      x += "\n" + curr.placeA + " -> " + curr.placeB;
      x += "\n";
      x += "[ ";
  		 for(String d : curr.jeep){ 
        j.add(d);
        x += d + " ";
      }
      x += " ]";
  	}
  	x += "\n";
  	return x;
  }

  //finds all the possible routes
      public ArrayList<ArrayList<Node>> allRoute(String origin, String dest, String avoid){
  		ArrayList<ArrayList<Node>> routes = new ArrayList<>();
  	ArrayList<ArrayList<Node>> prev = new ArrayList<>();
  	Map<String, Boolean> vis = new HashMap<String, Boolean>();
  	Queue<String> s = new LinkedList<>();
  	
    s.add(origin);
  	vis.put(origin, true);
  	while(!s.isEmpty()){
  		String p = s.remove();
  		for(String st : getAdjacentPlaces(p)){
  			if(!vis.containsKey(st)){
  				ArrayList<Node> n = eachRoute(st, dest, avoid);
  				ArrayList<Node> m = eachRoute(origin, st, avoid);
  				if(n != null && m != null) {
  					m.addAll(n);
  					if(!exist(routes, m)){
  						routes.add(trim(m));
  					}
  				}

  				s.add(st);
  				vis.put(st, true);
  			}
  		}
  	}
  	return routes;
  }
           
    
}

//NODE NODE NODE
class Node {
    ArrayList<String> jeep; 
    String placeA;
    String placeB;    
    
    Node(String placeA, String placeB){
        this.placeA = placeA;
        this.placeB = placeB;
        jeep = new ArrayList<String>();
       
    }

    public void addJeep(String s){
        s = s.replaceAll(" ", "");
        if(!jeep.contains(s))
            jeep.add(s);
    }
}

//PLACES SOMETHING CALLER
class Place {
    public String place;
    public String caller;
    
    public Place(String p, String c){
        place = p;
        caller = c;
    }
}