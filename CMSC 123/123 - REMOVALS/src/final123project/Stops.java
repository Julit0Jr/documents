package final123project;
import java.util.ArrayList;
import java.util.Collections;

public class Stops {
    public ArrayList<String> PUJ;
    public boolean adj;
    
    public Stops() {
        PUJ = new ArrayList<>();
        adj = false;
    }

    public void addJEEP(String jeep) {
        if(!isJEEPEXISTS(jeep))
            PUJ.add(jeep);
    }

    public boolean isJEEPEXISTS(String jeep) {
        Collections.sort(PUJ);
        int i = Collections.binarySearch(PUJ, jeep);
        return i >= 0;
    }
}
