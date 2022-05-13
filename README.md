# Card-shuffling-and-dealing-program
- 老師當初給的只有header file和friver program，其他都是自己加的
- header file成員函式及字串裡面的參數是空的，也是自己加的


1. **ex10_11.cpp、test_Card.cpp、test_DeckOfCards.cpp是driver program**
2. Card.cpp 、 Card.h、test_Card
    1. test_Card是用來測試Card object生成及功能是否正常
    2. 經由test_Card測試，目前Card object有照預想中生成了。

3. **DeckOfCards.cpp、DeckOfCards.h**
    1. test_DeckOfCards.cpp是用來測試DeckOfCards object生成及功能是否正常
    2. 經由test_DeckOfCards測試，目前DeckOfCards object有照預想中生成了。
        - 只是因為是vector且是private，
        - 所以取值要多寫2個member function getSuit() 和 getFace()
        - 賦值也是，要多寫2個member function setSuit() 和 setFace()
4. **Hand.cpp、Hand.h**
    1. 最後會測試Hand object的生成，若是正常，則開始寫member function **pair()、twoPair()、threeOfAKind()、fourOfAKind()、flush()、straight()**
