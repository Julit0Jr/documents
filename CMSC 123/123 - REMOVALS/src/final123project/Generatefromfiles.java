package final123project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Generatefromfiles {
    public static ArrayList<String> LANDMARKS = new ArrayList<>();
    public static ArrayList<String> JEEPS = new ArrayList<>();
    public static BufferedReader SCAN;
    public int index = 0;
    
    public static void generateLandmarks() throws IOException {
        FileReader file = null;
        try {
            file = new FileReader("landmarks.txt");
            SCAN = new BufferedReader(file);
            String landmark = "";
            while((landmark = SCAN.readLine()) != null)
                LANDMARKS.add(landmark);
            Collections.sort(LANDMARKS);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Generatefromfiles.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                file.close();
            } catch (IOException ex) {
                Logger.getLogger(Generatefromfiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public static void generateListsofPUJ() throws IOException{
        FileReader file = null;
        try {
            file = new FileReader("ListOfJeepneys.txt");
            SCAN = new BufferedReader(file);
            String jeep = "";
            int i = 0;
            while((jeep = SCAN.readLine()) != null)
                JEEPS.add(jeep);
            Collections.sort(JEEPS);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Generatefromfiles.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                file.close();
            } catch (IOException ex) {
                Logger.getLogger(Generatefromfiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public static int getIndex(String s) {
        s = s.toUpperCase();
        Collections.sort(LANDMARKS);
        return Collections.binarySearch(LANDMARKS,s);
    }
    
     public static void generateRoute() throws IOException {
        for(int i = 0; i < Generatefromfiles.JEEPS.size(); i++){
            FileReader file =  null;
            try {
                String src =  Generatefromfiles.JEEPS.get(i) + ".txt";
                file = new FileReader(src);
                Generatefromfiles.SCAN = new BufferedReader(file);
                Route.jRoute[i] = new Route();
                Route.jRoute[i].jeepney = Generatefromfiles.SCAN.readLine();
                String s = "";
                while((s = Generatefromfiles.SCAN.readLine()) != null)
                    Route.jRoute[i].route.add(s);
                Graph.addEdge(Route.jRoute[i].jeepney, Route.jRoute[i].route); //calling the other the edge with 2 params
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Generatefromfiles.class.getName()).log(Level.SEVERE, null, ex);
            } finally {
                try {
                    file.close();
                } catch (IOException ex) {
                    Logger.getLogger(Generatefromfiles.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
    }
}
