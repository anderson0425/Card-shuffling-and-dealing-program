    //DeckOfCards
    vector< Card > deck; // represents deck of cards  //!DeckOfCards object一開始會有52個card objects
    unsigned currentCard; // index of next card to be dealt //FIXME:下一個被抽得牌的index，這裡有點看不懂意思

	//hand
    vector< Card > hand; // our hand  //!想像成一個array，只是dtype是Card object    目前手上的卡片
    vector< int > faceCount; // number of each face  //!想像成一個array，只是dtype是int

	//card
    int face;//這張卡的數字對應的index---用來從string Array中取出face string
    int suit;//這張卡的花色對應的index---用來從string Array中取出suit string //!這邊預設        0-spade 黑桃      1-heart 紅心      2-diamond 方塊      3-club 梅花

