#ifndef LANTERN_FISH_H
#define LANTERN_FISH_H

/**
 * The lanternfish has a timer for when it should spawn a new lanternfish along with methods for manipulating this timer.
 * 
 * @author Sugaku
 */
class Lanternfish {

    private:
        int timer;
    public:
        Lanternfish ();
        Lanternfish (int timer) : timer(timer) {}
        void passDay ();
        int getTimer ();
};

#endif /* LANTERN_FISH_H */
