import java.util.ArrayList;
import java.util.List;

/**
 * A SimFile is a simulate file which can contain sub files and have
 * its own size. Is both a directory and file.
 * 
 * @author Sugaku
 */
public class SimFile {

    /**
     * Files which are contained in a directory that this SimFile may
     * be.
     */
    private final List<SimFile> subfiles = new ArrayList<>();

    /**
     * The name of this file.
     */
    private final String name;

    /**
     * The size of this file, not including sub-files.
     */
    private final long size;

    /**
     * The directory or file that contains this file.
     */
    private final SimFile parent;

    /**
     * Creates a new SimFile.
     * 
     * @param name The name of this file.
     * @param size The size of this file, can be zero to signify a 
     * directory.
     * @param parent The parent file of this SimFile.
     */
    public SimFile (String name, long size, SimFile parent) {
        this.name = name;
        this.size = size;
        this.parent = parent;
    }

    /**
     * Returns the actual size of this SimFile including sub-files.
     * 
     * @return The actual size of the file including sub-files.
     */
    public long getSize () {
        long sum = this.size;
        for (SimFile f : subfiles) sum += f.getSize();
        return sum;
    }

    /**
     * Returns the name of this SimFile.
     * 
     * @return The name of this file.
     */
    public String getName () {
        return name;
    }

    /**
     * Adds a sub-file to this SimFile.
     * 
     * @param file The file to add as a SubFile to this one.
     */
    public void addSubFile (SimFile f) {
        subfiles.add(f);
    }

    /**
     * Returns a full list of the SubFiles of this file.
     * 
     * @return A list of SubFiles on this file.
     */
    public List<SimFile> getSubfiles () {
        return subfiles;
    }

    /**
     * Accessor method for the parent file of this file.
     * 
     * @return The parent file of this file.
     */
    public SimFile getParent () {
        return parent;
    }

    public boolean isDir () {
        return this.size == 0;
    }
}
