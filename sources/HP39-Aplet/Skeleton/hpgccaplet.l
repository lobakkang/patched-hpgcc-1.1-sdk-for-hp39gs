Saturn Assembler    HPGCC Aplet Template               Mon Jun 27 16:00:01 2022
V3.0.8 (12/06/2002)                                      hpgccaplet.c   Page    1

    1             * File  hpgccaplet.s    1
    2                     TITLE   HPGCC Aplet Template
    3             ************************************************************
    4             *
    5             * File: HPGCC Aplet Template
    6             * By: HPGCC Team
    7             * Based on original work: October/12/2000 by J.Y Avenard
    8             ************************************************************
    9             * File  hpgccaplet.s    8
   10
   11             * File  hpgccaplet.s    9
   12             *|| Reading from =Entry39.h
   13             * ASSEMBLE
   14             =!!append$      EQU     #0DF4B
   15             =!*triand       EQU     #0C558
   16             =!>ARRAY        EQU     #13AF2
   17             =!MATTRNnc      EQU     #3F7E7
   18             =!REDIMTEMP     EQU     #3F80B
   19             =!REDIMUSER     EQU     #3F80C
   20             =!append$       EQU     #0DF21
   21             =!append$SWAP   EQU     #0F809
   22             =#*             EQU     #03F12
   23             =#*OVF          EQU     #13A13
   24             =#+             EQU     #03DBC
   25             =#+#2-          EQU     #3F804
   26             =#+DUP          EQU     #0E350
   27             =#+OVER         EQU     #0F932
   28             =#+PICK         EQU     #0CF70
   29             =#+ROLL         EQU     #0D036
   30             =#+SWAP         EQU     #0F6D8
   31             =#+UNROLL       EQU     #0D096
   32             =#-             EQU     #03DE0
   33             =#-#2/          EQU     #0E0A6
   34             =#-OVER         EQU     #0F946
   35             =#-PICK         EQU     #0CF5E
   36             =#-ROLL         EQU     #0D024
   37             =#-SWAP         EQU     #0F6EC
   38             =#-UNROLL       EQU     #0D084
   39             =#/             EQU     #03F47
   40             =#0<>           EQU     #03CC7
   41             =#0=            EQU     #03CA6
   42             =#0=?SEMI       EQU     #0D5E1
   43             =#0=?SKIP       EQU     #0FC22
   44             =#0=ITE         EQU     #10704
   45             =#0=UNTIL       EQU     #0F4B2
   46             =#0=case        EQU     #0D45F
   47             =#1+            EQU     #03DEF
   48             =#1+'           EQU     #1024A
   49             =#1+LAST$       EQU     #0FB69
   50             =#1+NDROP       EQU     #0F84F
   51             =#1+PICK        EQU     #0CF8F
   52             =#1+ROLL        EQU     #0D04B
   53             =#1+SWAP        EQU     #0F700
   54             =#1+UNROLL      EQU     #0D0AB
   55             =#1+_ONE_DO     EQU     #07BB4
   56             =#1-            EQU     #03E0E
   57             =#1-1SWAP       EQU     #0F728
   58             =#1-ROT         EQU     #0F8BA
   59             =#1-SUB$        EQU     #0FB2D
   60             =#1-{}N         EQU     #0FA8D
   61             =#1<>           EQU     #0DE61
   62             =#1=            EQU     #0DE52
   63             =#1=?SKIP       EQU     #0FC4B
   64             =#1=case        EQU     #105A1
   65             =#2*            EQU     #03E6F
   66             =#2+            EQU     #03E2D
   67             =#2+PICK        EQU     #0CFAA
   68             =#2+ROLL        EQU     #0D070
   69             =#2+UNROLL      EQU     #0D0BD
   70             =#2-            EQU     #03E4E
   71             =#2/            EQU     #03E8E
   72             =#2<>           EQU     #0FFA7
   73             =#2=            EQU     #0DE45
   74             =#3+            EQU     #0E151
   75             =#3+PICK        EQU     #0CFBE
   76             =#3-            EQU     #0E133
   77             =#3=            EQU     #0DE34
   78             =#4+            EQU     #0E156
   79             =#4+PICK        EQU     #0CFCD
   80             =#5+            EQU     #0E15B
   81             =#5=            EQU     #0FF93
   82             =#8+            EQU     #0E16A
   83             =#<             EQU     #03CE4
   84             =#<3            EQU     #0FF52
   85             =#<=            EQU     #37101
   86             =#<>            EQU     #03D4E
   87             =#<>case        EQU     #105B5
   88             =#<ITE          EQU     #10718
   89             =#<case         EQU     #1058D
   90             =#=             EQU     #03D19
   91             =#=?SKIP        EQU     #0FC64
   92             =#=ITE          EQU     #0F507
   93             =#=Lookup       EQU     #15B08
   94             =#=POSCOMP      EQU     #108C6
   95             =#=case         EQU     #0D435
   96             =#=casedrop     EQU     #0D49C
   97             =#=casedrpfls   EQU     #0FE3F
   98             =#>             EQU     #03D83
   99             =#>$            EQU     #21A2C
  100             =#>1            EQU     #0FFCF
  101             =#>2case        EQU     #105C9
  102             =#>=            EQU     #370E8
  103             =#>?SKIP        EQU     #0FC91
  104             =#>CHR          EQU     #0622E
  105             =#>HXS          EQU     #06185
  106             =#>ITE          EQU     #1072C
  107             =#>ROMPTR       EQU     #0876D
  108             =#>case         EQU     #105E2
  109             =#AND           EQU     #03EE1
  110             =#CAlarmErr     EQU     #11E83
  111             =#DIV           EQU     #3709C
  112             =#EXITERR       EQU     #11E97
  113             =#Error:        EQU     #11C67
  114             =#MAX           EQU     #0E071
  115             =#MIN           EQU     #0E065
  116             =#MOD           EQU     #370C3
  117             =#NEG           EQU     #37087
  118             =#NOT           EQU     #03EB1
  119             =#NoRoomForSt   EQU     #11C53
  120             =#ODD           EQU     #37116
  121             =#OR            EQU     #03ED0
  122             =#ObTypeBase    EQU     #11C21
  123             =#SyntaxErr     EQU     #11C17
  124             =#THREESEVEN    EQU     #0426F
  125             =#Warning:NL    EQU     #11C5D
  126             =#XOR           EQU     #03EF2
  127             =#_102          EQU     #11C0D
  128             =#_123          EQU     #11C3F
  129             =#_124          EQU     #11C49
  130             =#_205          EQU     #11CE9
  131             =#_258_d        EQU     #11C0D
  132             =#_291_d        EQU     #11C3F
  133             =#_292_d        EQU     #11C49
  134             =#_517_d        EQU     #11CE9
  135             =$>BIGGROB      EQU     #1DD7E
  136             =$>GROB         EQU     #1DD8B
  137             =$>ID           EQU     #062CE
  138             =$>grob         EQU     #1DFAC
  139             =$DER           EQU     #124D0
  140             =$_''           EQU     #10D71
  141             =$_2DQ          EQU     #10D9B
  142             =$_::           EQU     #10D7F
  143             =$_<<>>         EQU     #10D47
  144             =$_ECHO         EQU     #10DA9
  145             =$_EXIT         EQU     #10DBB
  146             =$_GRAD         EQU     #10DF9
  147             =$_LRParens     EQU     #10D8D
  148             =$_R<<          EQU     #10D17
  149             =$_R<Z          EQU     #10D27
  150             =$_RAD          EQU     #10DE9
  151             =$_Undefined    EQU     #10DCD
  152             =$_XYZ          EQU     #10D37
  153             =$_{}           EQU     #10D55
  154             =$jADJMEM       EQU     #0F280
  155             =$jAINRTN       EQU     #0F287
  156             =$jAllowIntr    EQU     #0F28E
  157             =$jBITMAP       EQU     #0F295
  158             =$jCINRTN       EQU     #0F2AA
  159             =$jCREATETEMP   EQU     #0F2B1
  160             =$jChkLowBat    EQU     #0F29C
  161             =$jD0=DSKTOP    EQU     #0F2B8
  162             =$jD1=DSKTOP    EQU     #0F2BF
  163             =$jDOGARBAGE    EQU     #0F2D4
  164             =$jDOMEMERR     EQU     #0F2DB
  165             =$jDebounce     EQU     #0F2C6
  166             =$jDupAndThen   EQU     #0F2E2
  167             =$jECUSER       EQU     #0F2F0
  168             =$jErrjmp       EQU     #0F2E9
  169             =$jGARBAGECOL   EQU     #0F2F7
  170             =$jGETPIX       EQU     #0F2FE
  171             =$jGETPIX3      EQU     #0F305
  172             =$jGETPTR       EQU     #0F30C
  173             =$jGETPTRLOOP   EQU     #0F313
  174             =$jGETTEMP      EQU     #0F31A
  175             =$jGPMEMERR     EQU     #0F321
  176             =$jGPOvrWrFLp   EQU     #0F328
  177             =$jGPOvrWrTLp   EQU     #0F336
  178             =$jMAKE$        EQU     #0F352
  179             =$jMAKE$N       EQU     #0F359
  180             =$jMOVEDOWN     EQU     #0F36E
  181             =$jMOVEDSD      EQU     #0F375
  182             =$jMOVEDSU      EQU     #0F37C
  183             =$jMOVERSD      EQU     #0F383
  184             =$jMOVERSU      EQU     #0F38A
  185             =$jMOVEUP       EQU     #0F391
  186             =$jMUL#         EQU     #0F398
  187             =$jOvrWrF/TLp   EQU     #0F39F
  188             =$jOvrWrFLoop   EQU     #0F3A6
  189             =$jOvrWrT/FLp   EQU     #0F3AD
  190             =$jOvrWrTLoop   EQU     #0F3B4
  191             =$jPOP#         EQU     #0F3C2
  192             =$jPOP1%        EQU     #0F3D0
  193             =$jPOP2#        EQU     #0F3C9
  194             =$jPOP2%        EQU     #0F3D7
  195             =$jPUSH#        EQU     #0F3DE
  196             =$jPUSH#ALOOP   EQU     #0F3EC
  197             =$jPUSH#LOOP    EQU     #0F3F3
  198             =$jPUSH%        EQU     #0F3FA
  199             =$jPUSH%LOOP    EQU     #0F401
  200             =$jPUSH2#       EQU     #0F3E5
  201             =$jPUSHA        EQU     #0F408
  202             =$jPshF/TLoop   EQU     #0F40F
  203             =$jPshT/FLoop   EQU     #0F416
  204             =$jPushFLoop    EQU     #0F424
  205             =$jPushTLoop    EQU     #0F41D
  206             =$jSAVPTR       EQU     #0F42B
  207             =$jSKIPBODY     EQU     #0F439
  208             =$jSKIPOB       EQU     #0F432
  209             =$jWIPEOUT      EQU     #0F440
  210             =$jWindowXY     EQU     #0F447
  211             =$jcorner       EQU     #0F2A3
  212             =$jmakebeep     EQU     #0F360
  213             =$jmakegrob     EQU     #0F367
  214             =$jpixon2       EQU     #0F3BB
  215             =%%-1           EQU     #1663B
  216             =%%.1           EQU     #12181
  217             =%%.5           EQU     #1219B
  218             =%%/>%          EQU     #103FD
  219             =%%0            EQU     #120E5
  220             =%%1            EQU     #120FF
  221             =%%10           EQU     #121B5
  222             =%%2            EQU     #12119
  223             =%%3            EQU     #12133
  224             =%%4            EQU     #1214D
  225             =%%5            EQU     #12167
  226             =%%>%           EQU     #1B3EB
  227             =%%PI           EQU     #12077
  228             =%*             EQU     #1B8DD
  229             =%+             EQU     #1B895
  230             =%-             EQU     #1B8A2
  231             =%-.5           EQU     #121F9
  232             =%-1            EQU     #11FA5
  233             =%-2            EQU     #11FBA
  234             =%-3            EQU     #11FCF
  235             =%-4            EQU     #11FE4
  236             =%-5            EQU     #11FF9
  237             =%-6            EQU     #1200E
  238             =%-7            EQU     #12023
  239             =%-8            EQU     #12038
  240             =%-9            EQU     #1204D
  241             =%-MAXREAL      EQU     #120A6
  242             =%-MINREAL      EQU     #120D0
  243             =%.5            EQU     #121E4
  244             =%/             EQU     #1B91F
  245             =%0             EQU     #11ED3
  246             =%0<            EQU     #1B659
  247             =%0<>           EQU     #1B6F0
  248             =%0=            EQU     #1B68C
  249             =%0>            EQU     #1B6BA
  250             =%0>=           EQU     #1B718
  251             =%0AllTOLVars   EQU     #128F0
  252             =%0AllTopicVs   EQU     #128B5
  253             =%0TOLVarSet    EQU     #129F8
  254             =%1             EQU     #11EE8
  255             =%10            EQU     #1220E
  256             =%15            EQU     #12277
  257             =%180           EQU     #12388
  258             =%2             EQU     #11EFD
  259             =%200           EQU     #1239D
  260             =%25            EQU     #12349
  261             =%3             EQU     #11F12
  262             =%360           EQU     #123B2
  263             =%4             EQU     #11F27
  264             =%400           EQU     #123C7
  265             =%5             EQU     #11F3C
  266             =%6             EQU     #11F51
  267             =%7             EQU     #11F66
  268             =%8             EQU     #11F7B
  269             =%9             EQU     #11F90
  270             =%<             EQU     #1B792
  271             =%<=            EQU     #1B7D7
  272             =%<>            EQU     #1B7ED
  273             =%=             EQU     #1B7E2
  274             =%>             EQU     #1B7AB
  275             =%>%%           EQU     #1B3FC
  276             =%>%%SWAP       EQU     #0F769
  277             =%>=            EQU     #1B7C1
  278             =%>C%           EQU     #0642E
  279             =%>HMS          EQU     #1B594
  280             =%ABS           EQU     #1B821
  281             =%ABSCOERCE     EQU     #13231
  282             =%ACOS          EQU     #1BC12
  283             =%ACOSH         EQU     #1BD34
  284             =%ALOG          EQU     #1BADB
  285             =%ANGLE         EQU     #1BC59
  286             =%ASIN          EQU     #1BBE2
  287             =%ASINH         EQU     #1BD21
  288             =%ATAN          EQU     #1BC42
  289             =%ATANH         EQU     #1BD47
  290             =%CEIL          EQU     #1BE94
  291             =%CH            EQU     #1B951
  292             =%CHS           EQU     #1B841
  293             =%COMB          EQU     #1BD83
  294             =%COS           EQU     #1BB61
  295             =%COSH          EQU     #1BCFB
  296             =%D>R           EQU     #1B543
  297             =%EXP           EQU     #1BA50
  298             =%EXPM1         EQU     #1BA63
  299             =%EXPONENT      EQU     #1BD5A
  300             =%FACT          EQU     #1BFE5
  301             =%FLOOR         EQU     #1BEA7
  302             =%FP            EQU     #1BE6E
  303             =%HMS+          EQU     #1B5C1
  304             =%HMS-          EQU     #1B5E9
  305             =%HMS>          EQU     #1B5AD
  306             =%IP            EQU     #1BE81
  307             =%LN            EQU     #1BA8F
  308             =%LNP1          EQU     #1BAC8
  309             =%LOG           EQU     #1BAA2
  310             =%MANTISSA      EQU     #1B851
  311             =%MAX           EQU     #1B616
  312             =%MAXREAL       EQU     #12091
  313             =%MAXorder      EQU     #0F65B
  314             =%MIN           EQU     #1B62F
  315             =%MINREAL       EQU     #120BB
  316             =%MOD           EQU     #1BAFD
  317             =%NFACT         EQU     #1BD6D
  318             =%NROOT         EQU     #1B9A2
  319             =%OF            EQU     #1B8EA
  320             =%PERM          EQU     #1BD96
  321             =%PI            EQU     #12062
  322             =%POL>%REC      EQU     #1C3DC
  323             =%R>D           EQU     #1B576
  324             =%RAN           EQU     #1BEE3
  325             =%RANDOMIZE     EQU     #1BF65
  326             =%REC>%POL      EQU     #1C3AF
  327             =%SGN           EQU     #1B7F8
  328             =%SIN           EQU     #1BB10
  329             =%SINH          EQU     #1BCCF
  330             =%SPH>%REC      EQU     #1C413
  331             =%SQRT          EQU     #1BA2A
  332             =%T             EQU     #1B92C
  333             =%TAN           EQU     #1BBB2
  334             =%TANH          EQU     #1BD0E
  335             =%^             EQU     #1B991
  336             =%e             EQU     #121CF
  337             =&$             EQU     #05947
  338             =&$SWAP         EQU     #107E5
  339             =&&             EQU     #3F07E
  340             =&COMP          EQU     #059D3
  341             ='              EQU     #07665
  342             ='DROPFALSE     EQU     #26E33
  343             ='DoBadKey      EQU     #23F4A
  344             ='DoBadKeyT     EQU     #23F5E
  345             ='ERRJMP        EQU     #0FA3D
  346             ='LAMLNAMESTO   EQU     #102BD
  347             ='NOP           EQU     #0FBA5
  348             ='R             EQU     #076B9
  349             ='R'R           EQU     #1025E
  350             ='REVAL         EQU     #07734
  351             ='RRDROP        EQU     #1027C
  352             ='RSWP1+        EQU     #14E94
  353             ='Rapndit       EQU     #14D89
  354             ='xDER          EQU     #103E9
  355             ='xDEREQ        EQU     #102D6
  356             =+LOOP          EQU     #07B7E
  357             =0LASTOWDOB!    EQU     #232A7
  358             =10GETLAM       EQU     #0D1C9
  359             =10PICK         EQU     #0D001
  360             =10PUTLAM       EQU     #0D1C4
  361             =10UNROLL       EQU     #0FA0E
  362             =11GETLAM       EQU     #0D1D3
  363             =11PUTLAM       EQU     #0D1CE
  364             =12GETLAM       EQU     #0D1DD
  365             =12PUTLAM       EQU     #0D1D8
  366             =13GETLAM       EQU     #0D1E7
  367             =13PUTLAM       EQU     #0D1E2
  368             =14GETLAM       EQU     #0D1F1
  369             =14PUTLAM       EQU     #0D1EC
  370             =14SPACES$      EQU     #1249E
  371             =15GETLAM       EQU     #0D1FB
  372             =15PUTLAM       EQU     #0D1F6
  373             =16GETLAM       EQU     #0D205
  374             =16PUTLAM       EQU     #0D200
  375             =17GETLAM       EQU     #0D20F
  376             =17PUTLAM       EQU     #0D20A
  377             =18GETLAM       EQU     #0D219
  378             =18PUTLAM       EQU     #0D214
  379             =19GETLAM       EQU     #0D223
  380             =19PUTLAM       EQU     #0D21E
  381             =1ABNDSWAP      EQU     #0F68D
  382             =1GETABND       EQU     #0FDAE
  383             =1GETLAM        EQU     #0D16F
  384             =1GETLAM#0=     EQU     #1089E
  385             =1GETSWAP       EQU     #0F7E1
  386             =1GETapndcpl    EQU     #3F28F
  387             =1LAMBIND       EQU     #0FDC7
  388             =1NULLLAM{}     EQU     #109F6
  389             =1PUTLAM        EQU     #0D16A
  390             =1_#1-SUB       EQU     #0FB41
  391             =1_#1-SUB$      EQU     #0FB41
  392             =1getcxt!       EQU     #12A48
  393             =2#0=OR         EQU     #0FF0C
  394             =2'RCOLARPITE   EQU     #0D6B2
  395             =20GETLAM       EQU     #0D22D
  396             =20PUTLAM       EQU     #0D228
  397             =21GETLAM       EQU     #0D237
  398             =21PUTLAM       EQU     #0D232
  399             =22GETLAM       EQU     #0D241
  400             =22PUTLAM       EQU     #0D23C
  401             =2ARRY          EQU     #042F1
  402             =2CDispList     EQU     #3F5F2
  403             =2CKeyOK        EQU     #3F5F3
  404             =2Col?Case2Col  EQU     #14F3E
  405             =2ColChoose     EQU     #3F5A9
  406             =2DROP          EQU     #03258
  407             =2DROP00        EQU     #0E0F9
  408             =2DROPFALSE     EQU     #0F44E
  409             =2DUP           EQU     #031AC
  410             =2DUP#+         EQU     #0FFE3
  411             =2DUP#<         EQU     #0E416
  412             =2DUP#=         EQU     #0E430
  413             =2DUP#>         EQU     #0E44C
  414             =2DUP5ROLL      EQU     #104BB
  415             =2DUPEQ         EQU     #0FED0
  416             =2EXT           EQU     #04995
  417             =2GETEVAL       EQU     #0FBCD
  418             =2GETLAM        EQU     #0D179
  419             =2GROB          EQU     #04841
  420             =2HXS           EQU     #04797
  421             =2LIST          EQU     #0439B
  422             =2OVER          EQU     #10835
  423             =2Ob>Seco       EQU     #10876
  424             =2PUTLAM        EQU     #0D174
  425             =2RDROP         EQU     #0CF3A
  426             =2STR           EQU     #04247
  427             =2SWAP          EQU     #0DB7B
  428             =3ARRY          EQU     #11D11
  429             =3DROP          EQU     #0CD2B
  430             =3GETLAM        EQU     #0D183
  431             =3PICK          EQU     #0CFDE
  432             =3PICK#+        EQU     #1001F
  433             =3PICK3PICK     EQU     #104E3
  434             =3PICKOVER      EQU     #0F996
  435             =3PICKSWAP      EQU     #0F7B9
  436             =3PUTLAM        EQU     #0D17E
  437             =3RDROP         EQU     #0CF4C
  438             =3REAL          EQU     #11C35
  439             =3SYM           EQU     #11E47
  440             =3UNROLL        EQU     #0CD84
  441             =4DROP          EQU     #0CD30
  442             =4GETLAM        EQU     #0D18D
  443             =4PICK          EQU     #0CFE3
  444             =4PICK#+        EQU     #10033
  445             =4PICK#+SWAP    EQU     #0F6BF
  446             =4PICK+SWAP     EQU     #0F6BF
  447             =4PICKOVER      EQU     #0F9AA
  448             =4PICKSWAP      EQU     #0F7CD
  449             =4PUTLAM        EQU     #0D188
  450             =4ROLL          EQU     #0CD93
  451             =4ROLLOVER      EQU     #0F982
  452             =4ROLLROT       EQU     #0F8E2
  453             =4ROLLSWAP      EQU     #0F7A5
  454             =4UNROLL        EQU     #0CE8A
  455             =4UNROLL3DROP   EQU     #0CF28
  456             =4UNROLLDUP     EQU     #0F5E3
  457             =4UNROLLROT     EQU     #0F8F6
  458             =5DROP          EQU     #0CD35
  459             =5GETLAM        EQU     #0D197
  460             =5PICK          EQU     #0CFE8
  461             =5PUTLAM        EQU     #0D192
  462             =5ROLL          EQU     #0CDB0
  463             =5UNROLL        EQU     #0CEB0
  464             =6DROP          EQU     #0CD41
  465             =6GETLAM        EQU     #0D1A1
  466             =6PICK          EQU     #0CFED
  467             =6PUTLAM        EQU     #0D19C
  468             =6ROLL          EQU     #0CDDA
  469             =6UNROLL        EQU     #0CEE6
  470             =7DROP          EQU     #0CD4D
  471             =7GETLAM        EQU     #0D1AB
  472             =7PICK          EQU     #0CFF2
  473             =7PUTLAM        EQU     #0D1A6
  474             =7ROLL          EQU     #0CE43
  475             =7UNROLL        EQU     #0F49E
  476             =8GETLAM        EQU     #0D1B5
  477             =8PICK          EQU     #0CFF7
  478             =8PUTLAM        EQU     #0D1B0
  479             =8ROLL          EQU     #0CE14
  480             =8UNROLL        EQU     #0F9FA
  481             =9GETLAM        EQU     #0D1BF
  482             =9PICK          EQU     #0CFFC
  483             =9PUTLAM        EQU     #0D1BA
  484             =9ROLL          EQU     #0CE71
  485             =::N            EQU     #05BFE
  486             =::NEVAL        EQU     #0FBB9
  487             =>H$            EQU     #05A0F
  488             =>HCOMP         EQU     #05A7A
  489             =>R             EQU     #07778
  490             =>T$            EQU     #05AA2
  491             =>TCOMP         EQU     #05AAE
  492             =?>ROMPTR       EQU     #0E5DC
  493             =?ATTNQUIT      EQU     #269B1
  494             =?AdjFocusPos   EQU     #3F5F4
  495             =?CARCOMP       EQU     #0FA65
  496             =?CaseKeyDef    EQU     #24008
  497             =?CaseRomptr@   EQU     #2403A
  498             =?DispMenu      EQU     #10E0B
  499             =?DispMoreU/D   EQU     #3F5F5
  500             =?ExitThisTop   EQU     #35E0F
  501             =?FixFieldKeys  EQU     #3F5F6
  502             =?GetFObTypes   EQU     #3F5F7
  503             =?GetMsg        EQU     #15BE9
  504             =?NoTaskSwDef   EQU     #24067
  505             =?Ob>Seco       EQU     #10849
  506             =?ROMPTR>       EQU     #0E5FF
  507             =?SEMI          EQU     #0D604
  508             =?SEMIDROP      EQU     #10164
  509             =?SKIP          EQU     #07903
  510             =?SKIPSWAP      EQU     #0F679
  511             =?SWAP          EQU     #0F7F5
  512             =?SWAPDROP      EQU     #0F836
  513             =@              EQU     #081D3
  514             =@LAM           EQU     #080E7
  515             =ABND           EQU     #07C70
  516             =ABORT          EQU     #056A2
  517             =ABSCOERCE      EQU     #13236
  518             =ABUFF          EQU     #1E96F
  519             =AGAIN          EQU     #07984
  520             =AND            EQU     #03B46
  521             =ANDITE         EQU     #106DC
  522             =ANDNOTcase     EQU     #1065A
  523             =ANDcase        EQU     #10565
  524             =APPEND_SPACE   EQU     #0F48A
  525             =ARRYCMP        EQU     #042DD
  526             =ARRYID         EQU     #04305
  527             =ARRYLIST       EQU     #042FB
  528             =ARRYLISTCMP    EQU     #11D25
  529             =ARRYLISTREAL   EQU     #11D1B
  530             =ARRYREAL       EQU     #042D3
  531             =ARRYREALCMP    EQU     #11D07
  532             =ARRYREALREAL   EQU     #11CFD
  533             =ARRYSYM        EQU     #0432D
  534             =ARSIZE         EQU     #171E2     sup
  535             =ATTN?          EQU     #26793
  536             =ATTNERR        EQU     #11DB1
  537             =ATTNFLGCLR     EQU     #05821
  538             =AddEq$         EQU     #3F5F8
  539             =AlDrawMenu     EQU     #2ECD8
  540             =AllowPRLCD     EQU     #3F290
  541             =AllowPrlcdCl   EQU     #3F291
  542             =Angle@         EQU     #27083
  543             =AngleField     EQU     #3F5F9
  544             =AngleLabel     EQU     #3F5FA
  545             =AnyDABad?      EQU     #363C9
  546             =ApName$>Id     EQU     #3F5FB
  547             =ApNameId>$     EQU     #3F5FC
  548             =ApNameId>Id    EQU     #3F5FD
  549             =AppDir+Offs    EQU     #28879
  550             =Area@          EQU     #2738F
  551             =AttnPOSCOMP    EQU     #0ED6E
  552             =BAK>HOME       EQU     #09FB0
  553             =BAK>OB         EQU     #09DA5
  554             =BAKNAME        EQU     #08AEC
  555             =BEGIN          EQU     #0797B
  556             =BIND           EQU     #07CA9
  557             =BINT0          EQU     #04049
  558             =BINT1          EQU     #04053
  559             =BINT10         EQU     #040AD
  560             =BINT100        EQU     #04431
  561             =BINT101        EQU     #0443B
  562             =BINT102        EQU     #04445
  563             =BINT103        EQU     #0444F
  564             =BINT104        EQU     #04459
  565             =BINT105        EQU     #04463
  566             =BINT106        EQU     #0446D
  567             =BINT107        EQU     #04477
  568             =BINT108        EQU     #04481
  569             =BINT109        EQU     #0448B
  570             =BINT11         EQU     #040B7
  571             =BINT110        EQU     #04495
  572             =BINT111        EQU     #0449F
  573             =BINT112        EQU     #044A9
  574             =BINT113        EQU     #044B3
  575             =BINT114        EQU     #044BD
  576             =BINT115        EQU     #044C7
  577             =BINT116        EQU     #044D1
  578             =BINT117        EQU     #044DB
  579             =BINT118        EQU     #044E5
  580             =BINT119        EQU     #044EF
  581             =BINT12         EQU     #040C1
  582             =BINT120        EQU     #044F9
  583             =BINT121        EQU     #04503
  584             =BINT122        EQU     #0450D
  585             =BINT123        EQU     #04517
  586             =BINT124        EQU     #04521
  587             =BINT125        EQU     #0452B
  588             =BINT126        EQU     #04535
  589             =BINT127        EQU     #0453F
  590             =BINT128        EQU     #04549
  591             =BINT129        EQU     #04553
  592             =BINT13         EQU     #040CB
  593             =BINT130        EQU     #0455D
  594             =BINT131        EQU     #04567
  595             =BINT132        EQU     #04571
  596             =BINT133        EQU     #0457B
  597             =BINT134        EQU     #04585
  598             =BINT135        EQU     #0458F
  599             =BINT136        EQU     #04599
  600             =BINT137        EQU     #045A3
  601             =BINT138        EQU     #045AD
  602             =BINT139        EQU     #045B7
  603             =BINT14         EQU     #040D5
  604             =BINT140        EQU     #045C1
  605             =BINT141        EQU     #045CB
  606             =BINT142        EQU     #045D5
  607             =BINT143        EQU     #045DF
  608             =BINT144        EQU     #045E9
  609             =BINT145        EQU     #045F3
  610             =BINT146        EQU     #045FD
  611             =BINT147        EQU     #04607
  612             =BINT148        EQU     #04611
  613             =BINT149        EQU     #0461B
  614             =BINT15         EQU     #040DF
  615             =BINT150        EQU     #04625
  616             =BINT151        EQU     #0462F
  617             =BINT152        EQU     #04639
  618             =BINT153        EQU     #04643
  619             =BINT154        EQU     #0464D
  620             =BINT155        EQU     #04657
  621             =BINT156        EQU     #04661
  622             =BINT157        EQU     #0466B
  623             =BINT158        EQU     #04675
  624             =BINT159        EQU     #0467F
  625             =BINT16         EQU     #040E9
  626             =BINT160        EQU     #04689
  627             =BINT161        EQU     #04693
  628             =BINT162        EQU     #0469D
  629             =BINT163        EQU     #046A7
  630             =BINT164        EQU     #046B1
  631             =BINT165        EQU     #046BB
  632             =BINT166        EQU     #046C5
  633             =BINT167        EQU     #046CF
  634             =BINT168        EQU     #046D9
  635             =BINT169        EQU     #046E3
  636             =BINT17         EQU     #040F3
  637             =BINT170        EQU     #046ED
  638             =BINT171        EQU     #046F7
  639             =BINT172        EQU     #04701
  640             =BINT173        EQU     #0470B
  641             =BINT174        EQU     #04715
  642             =BINT175        EQU     #0471F
  643             =BINT176        EQU     #04729
  644             =BINT177        EQU     #04733
  645             =BINT178        EQU     #0473D
  646             =BINT179        EQU     #04747
  647             =BINT18         EQU     #040FD
  648             =BINT180        EQU     #04751
  649             =BINT181        EQU     #0475B
  650             =BINT182        EQU     #04765
  651             =BINT183        EQU     #0476F
  652             =BINT184        EQU     #04779
  653             =BINT185        EQU     #04783
  654             =BINT186        EQU     #0478D
  655             =BINT187        EQU     #04797
  656             =BINT188        EQU     #047A1
  657             =BINT189        EQU     #047AB
  658             =BINT19         EQU     #04107
  659             =BINT190        EQU     #047B5
  660             =BINT191        EQU     #047BF
  661             =BINT192        EQU     #047C9
  662             =BINT193        EQU     #047D3
  663             =BINT194        EQU     #047DD
  664             =BINT195        EQU     #047E7
  665             =BINT196        EQU     #047F1
  666             =BINT197        EQU     #047FB
  667             =BINT198        EQU     #04805
  668             =BINT199        EQU     #0480F
  669             =BINT2          EQU     #0405D
  670             =BINT20         EQU     #04111
  671             =BINT200        EQU     #04819
  672             =BINT201        EQU     #04823
  673             =BINT202        EQU     #0482D
  674             =BINT203        EQU     #04837
  675             =BINT204        EQU     #04841
  676             =BINT205        EQU     #0484B
  677             =BINT206        EQU     #04855
  678             =BINT207        EQU     #0485F
  679             =BINT208        EQU     #04869
  680             =BINT209        EQU     #04873
  681             =BINT21         EQU     #0411B
  682             =BINT210        EQU     #0487D
  683             =BINT211        EQU     #04887
  684             =BINT212        EQU     #04891
  685             =BINT213        EQU     #0489B
  686             =BINT214        EQU     #048A5
  687             =BINT215        EQU     #048AF
  688             =BINT216        EQU     #048B9
  689             =BINT217        EQU     #048C3
  690             =BINT218        EQU     #048CD
  691             =BINT219        EQU     #048D7
  692             =BINT22         EQU     #04125
  693             =BINT220        EQU     #048E1
  694             =BINT221        EQU     #048EB
  695             =BINT222        EQU     #048F5
  696             =BINT223        EQU     #048FF
  697             =BINT224        EQU     #04909
  698             =BINT225        EQU     #04913
  699             =BINT226        EQU     #0491D
  700             =BINT227        EQU     #04927
  701             =BINT228        EQU     #04931
  702             =BINT229        EQU     #0493B
  703             =BINT23         EQU     #0412F
  704             =BINT230        EQU     #04945
  705             =BINT231        EQU     #0494F
  706             =BINT232        EQU     #04959
  707             =BINT233        EQU     #04963
  708             =BINT234        EQU     #0496D
  709             =BINT235        EQU     #04977
  710             =BINT236        EQU     #04981
  711             =BINT237        EQU     #0498B
  712             =BINT238        EQU     #04995
  713             =BINT239        EQU     #0499F
  714             =BINT24         EQU     #04139
  715             =BINT240        EQU     #049A9
  716             =BINT241        EQU     #049B3
  717             =BINT242        EQU     #049BD
  718             =BINT243        EQU     #049C7
  719             =BINT244        EQU     #049D1
  720             =BINT245        EQU     #049DB
  721             =BINT246        EQU     #049E5
  722             =BINT247        EQU     #049EF
  723             =BINT248        EQU     #049F9
  724             =BINT249        EQU     #04A03
  725             =BINT25         EQU     #04143
  726             =BINT250        EQU     #04A0D
  727             =BINT251        EQU     #04A17
  728             =BINT252        EQU     #04A21
  729             =BINT253        EQU     #04A2B
  730             =BINT254        EQU     #04A35
  731             =BINT255        EQU     #04A3F
  732             =BINT255d       EQU     #04A3F
  733             =BINT256        EQU     #04A49
  734             =BINT26         EQU     #0414D
  735             =BINT27         EQU     #04157
  736             =BINT28         EQU     #04161
  737             =BINT29         EQU     #0416B
  738             =BINT3          EQU     #04067
  739             =BINT30         EQU     #04175
  740             =BINT31         EQU     #0417F
  741             =BINT32         EQU     #04189
  742             =BINT33         EQU     #04193
  743             =BINT34         EQU     #0419D
  744             =BINT35         EQU     #041A7
  745             =BINT36         EQU     #041B1
  746             =BINT37         EQU     #041BB
  747             =BINT38         EQU     #041C5
  748             =BINT39         EQU     #041CF
  749             =BINT3Fh        EQU     #042BF
  750             =BINT4          EQU     #04071
  751             =BINT40         EQU     #041D9
  752             =BINT40h        EQU     #042C9
  753             =BINT41         EQU     #041E3
  754             =BINT42         EQU     #041ED
  755             =BINT43         EQU     #041F7
  756             =BINT44         EQU     #04201
  757             =BINT45         EQU     #0420B
  758             =BINT46         EQU     #04215
  759             =BINT47         EQU     #0421F
  760             =BINT48         EQU     #04229
  761             =BINT49         EQU     #04233
  762             =BINT5          EQU     #0407B
  763             =BINT50         EQU     #0423D
  764             =BINT51         EQU     #04247
  765             =BINT52         EQU     #04251
  766             =BINT53         EQU     #0425B
  767             =BINT54         EQU     #04265
  768             =BINT55         EQU     #0426F
  769             =BINT56         EQU     #04279
  770             =BINT57         EQU     #04283
  771             =BINT58         EQU     #0428D
  772             =BINT59         EQU     #04297
  773             =BINT6          EQU     #04085
  774             =BINT60         EQU     #042A1
  775             =BINT61         EQU     #042AB
  776             =BINT62         EQU     #042B5
  777             =BINT63         EQU     #042BF
  778             =BINT64         EQU     #042C9
  779             =BINT65         EQU     #042D3
  780             =BINT66         EQU     #042DD
  781             =BINT67         EQU     #042E7
  782             =BINT68         EQU     #042F1
  783             =BINT69         EQU     #042FB
  784             =BINT7          EQU     #0408F
  785             =BINT70         EQU     #04305
  786             =BINT71         EQU     #0430F
  787             =BINT72         EQU     #04319
  788             =BINT73         EQU     #04323
  789             =BINT74         EQU     #0432D
  790             =BINT75         EQU     #04337
  791             =BINT76         EQU     #04341
  792             =BINT77         EQU     #0434B
  793             =BINT78         EQU     #04355
  794             =BINT79         EQU     #0435F
  795             =BINT8          EQU     #04099
  796             =BINT80         EQU     #04369
  797             =BINT80h        EQU     #04549
  798             =BINT81         EQU     #04373
  799             =BINT82         EQU     #0437D
  800             =BINT83         EQU     #04387
  801             =BINT84         EQU     #04391
  802             =BINT85         EQU     #0439B
  803             =BINT86         EQU     #043A5
  804             =BINT87         EQU     #043AF
  805             =BINT88         EQU     #043B9
  806             =BINT89         EQU     #043C3
  807             =BINT9          EQU     #040A3
  808             =BINT90         EQU     #043CD
  809             =BINT91         EQU     #043D7
  810             =BINT92         EQU     #043E1
  811             =BINT93         EQU     #043EB
  812             =BINT94         EQU     #043F5
  813             =BINT95         EQU     #043FF
  814             =BINT96         EQU     #04409
  815             =BINT97         EQU     #04413
  816             =BINT98         EQU     #0441D
  817             =BINT99         EQU     #04427
  818             =BINTC0h        EQU     #047C9
  819             =BINT_114d      EQU     #044BD
  820             =BINT_115d      EQU     #044C7
  821             =BINT_116d      EQU     #044D1
  822             =BINT_117d      EQU     #044DB
  823             =BINT_122d      EQU     #0450D
  824             =BINT_128d      EQU     #04549
  825             =BINT_130d      EQU     #0455D
  826             =BINT_131d      EQU     #04567
  827             =BINT_263d      EQU     #11C21
  828             =BINT_305d      EQU     #11C53
  829             =BINT_306d      EQU     #11C5D
  830             =BINT_307d      EQU     #11C67
  831             =BINT_65d       EQU     #042D3
  832             =BINT_91d       EQU     #043D7
  833             =BINT_96d       EQU     #04409
  834             =BLANKIT        EQU     #1E9F9
  835             =BREAK          EQU     #3F292     sup
  836             =BTRow1@        EQU     #271EB
  837             =BadIfEdit      EQU     #23460
  838             =BinLookup      EQU     #38763
  839             =BlankClient    EQU     #3F5FE
  840             =BlankHelp      EQU     #3F630
  841             =Box/StdLabel   EQU     #234C4
  842             =Bubble         EQU     #3F6F1
  843             =C%>%           EQU     #06530
  844             =CACHE          EQU     #0D863
  845             =CALCCXT!       EQU     #12696
  846             =CALCCXT@       EQU     #126A6
  847             =CAND           EQU     #386E1
  848             =CAR$           EQU     #058A6
  849             =CARCOMP        EQU     #05842
  850             =CDR$           EQU     #05925
  851             =CDRCOMP        EQU     #0590C
  852             =CHANGETYPE     EQU     #0626C
  853             =CHECKHEIGHT    EQU     #3F5F1
  854             =CHECKKEY       EQU     #04F92
  855             =CHECKPICT      EQU     #3F31F
  856             =CHR>#          EQU     #0620A
  857             =CHR>$          EQU     #109DD
  858             =CHR_#          EQU     #10A38
  859             =CHR_'          EQU     #10A2A
  860             =CHR_*          EQU     #10A3F
  861             =CHR_+          EQU     #10A46
  862             =CHR_,          EQU     #10A4D
  863             =CHR_-          EQU     #10A54
  864             =CHR_->         EQU     #10C3E
  865             =CHR_.          EQU     #10A5B
  866             =CHR_...        EQU     #10A23
  867             =CHR_/          EQU     #10A62
  868             =CHR_0          EQU     #10A69
  869             =CHR_00         EQU     #10A1C
  870             =CHR_1          EQU     #10A70
  871             =CHR_2          EQU     #10A77
  872             =CHR_3          EQU     #10A7E
  873             =CHR_4          EQU     #10A85
  874             =CHR_5          EQU     #10A8C
  875             =CHR_6          EQU     #10A93
  876             =CHR_7          EQU     #10A9A
  877             =CHR_8          EQU     #10AA1
  878             =CHR_9          EQU     #10AA8
  879             =CHR_:          EQU     #10AAF
  880             =CHR_;          EQU     #10AB6
  881             =CHR_<          EQU     #10ABD
  882             =CHR_<<         EQU     #10C45
  883             =CHR_<=         EQU     #10CB5
  884             =CHR_<>         EQU     #10CC3
  885             =CHR_=          EQU     #10AC4
  886             =CHR_>          EQU     #10ACB
  887             =CHR_>=         EQU     #10CBC
  888             =CHR_>>         EQU     #10C4C
  889             =CHR_A          EQU     #10AD2
  890             =CHR_Angle      EQU     #10C53
  891             =CHR_B          EQU     #10AD9
  892             =CHR_C          EQU     #10AE0
  893             =CHR_D          EQU     #10AE7
  894             =CHR_DblQuote   EQU     #10A31
  895             =CHR_Deriv      EQU     #10C5A
  896             =CHR_E          EQU     #10AEE
  897             =CHR_F          EQU     #10AF5
  898             =CHR_G          EQU     #10AFC
  899             =CHR_H          EQU     #10B03
  900             =CHR_I          EQU     #10B0A
  901             =CHR_Integral   EQU     #10C61
  902             =CHR_J          EQU     #10B11
  903             =CHR_K          EQU     #10B18
  904             =CHR_L          EQU     #10B1F
  905             =CHR_LeftPar    EQU     #10C68
  906             =CHR_M          EQU     #10B26
  907             =CHR_N          EQU     #10B2D
  908             =CHR_Newline    EQU     #10C6F
  909             =CHR_O          EQU     #10B34
  910             =CHR_P          EQU     #10B3B
  911             =CHR_Pi         EQU     #10C76
  912             =CHR_Q          EQU     #10B42
  913             =CHR_R          EQU     #10B49
  914             =CHR_RightPar   EQU     #10C7D
  915             =CHR_S          EQU     #10B50
  916             =CHR_Sigma      EQU     #10C84
  917             =CHR_Space      EQU     #10C8B
  918             =CHR_T          EQU     #10B57
  919             =CHR_U          EQU     #10B5E
  920             =CHR_UndScore   EQU     #10C92
  921             =CHR_V          EQU     #10B65
  922             =CHR_W          EQU     #10B6C
  923             =CHR_X          EQU     #10B73
  924             =CHR_Y          EQU     #10B7A
  925             =CHR_Z          EQU     #10B81
  926             =CHR_[          EQU     #10C99
  927             =CHR_]          EQU     #10CA0
  928             =CHR_a          EQU     #10B88
  929             =CHR_b          EQU     #10B8F
  930             =CHR_c          EQU     #10B96
  931             =CHR_d          EQU     #10B9D
  932             =CHR_e          EQU     #10BA4
  933             =CHR_f          EQU     #10BAB
  934             =CHR_g          EQU     #10BB2
  935             =CHR_h          EQU     #10BB9
  936             =CHR_i          EQU     #10BC0
  937             =CHR_j          EQU     #10BC7
  938             =CHR_k          EQU     #10BCE
  939             =CHR_l          EQU     #10BD5
  940             =CHR_m          EQU     #10BDC
  941             =CHR_n          EQU     #10BE3
  942             =CHR_o          EQU     #10BEA
  943             =CHR_p          EQU     #10BF1
  944             =CHR_q          EQU     #10BF8
  945             =CHR_r          EQU     #10BFF
  946             =CHR_s          EQU     #10C06
  947             =CHR_t          EQU     #10C0D
  948             =CHR_u          EQU     #10C14
  949             =CHR_v          EQU     #10C1B
  950             =CHR_w          EQU     #10C22
  951             =CHR_x          EQU     #10C29
  952             =CHR_y          EQU     #10C30
  953             =CHR_z          EQU     #10C37
  954             =CHR_{          EQU     #10CA7
  955             =CHR_}          EQU     #10CAE
  956             =CK&DISPATCH0   EQU     #13573
  957             =CK&DISPATCH1   EQU     #1352A
  958             =CK&DISPATCH2   EQU     #13582
  959             =CK0            EQU     #12F1E
  960             =CK1&Dispatch   EQU     #1341F
  961             =CK2&Dispatch   EQU     #13430
  962             =CK3&Dispatch   EQU     #13441
  963             =CK4&Dispatch   EQU     #13452
  964             =CK5&Dispatch   EQU     #13463
  965             =CKGROBFITS     EQU     #3F320
  966             =CKREAL         EQU     #0E767
  967             =CKREF          EQU     #16451
  968             =CLCD10         EQU     #01F83
  969             =CLKTICKS       EQU     #3F7A7
  970             =CLOSEUART      EQU     #3F28E
  971             =CLRTOPICLAM    EQU     #3F5EE
  972             =CMPOBOB        EQU     #11CDF
  973             =COERCE         EQU     #13244
  974             =COERCEDUP      EQU     #0F5BB
  975             =COERCESWAP     EQU     #0F755
  976             =COLA           EQU     #077AA
  977             =COLACOLA       EQU     #0E4E8
  978             =COLARPITE      EQU     #0D657
  979             =COLASKIP       EQU     #0FCAA
  980             =COLA_EVAL      EQU     #0D636
  981             =COLAcase       EQU     #0E501
  982             =COMPEVAL       EQU     #1340B
  983             =COMPILEID      EQU     #0852B
  984             =COMPROMID      EQU     #08530
  985             =CONTEXT!       EQU     #0960E
  986             =CONTEXT@       EQU     #09660
  987             =COR            EQU     #3870B
  988             =CREATE         EQU     #08F9C
  989             =CREATEDIR      EQU     #22F3B
  990             =CRLF$          EQU     #16C46
  991             =CalcDir+Offs   EQU     #28862
  992             =CatNot         EQU     #28154
  993             =CatPgm         EQU     #281C7
  994             =CatThisCxt     EQU     #2815E
  995             =ChangeFocus    EQU     #3F5FF
  996             =Choose         EQU     #3F324
  997             =Choose&DoTask  EQU     #3F603
  998             =ChooseMenu0    EQU     #3F600
  999             =ChooseMenu1    EQU     #3F601
 1000             =ChooseMenu2    EQU     #3F602
 1001             =ChooseSimple   EQU     #3F325
 1002             =ChooseVEntry   EQU     #3F5CA
 1003             =ChooseVExit    EQU     #3F5CB
 1004             =ChooseViewUI   EQU     #3F5CC
 1005             =Ck&DecKeyLoc   EQU     #25F78
 1006             =ClearList0     EQU     #3F604
 1007             =ClearList1     EQU     #3F605
 1008             =ClearList2     EQU     #3F606
 1009             =ClearList3     EQU     #3F607
 1010             =ClearList4     EQU     #3F608
 1011             =ClearList5     EQU     #3F609
 1012             =ClearList6     EQU     #3F60A
 1013             =ClearList7     EQU     #3F60B
 1014             =ClearList8     EQU     #3F60C
 1015             =ClearList9     EQU     #3F60D
 1016             =CloseUart      EQU     #170BB
 1017             =ClrAllTOLVs    EQU     #12899
 1018             =ClrAllTVars    EQU     #12863
 1019             =ClrDA1Bad      EQU     #3660A
 1020             =ClrDA1OK       EQU     #3624D
 1021             =ClrDA2OK       EQU     #36298
 1022             =ClrDA2aBad     EQU     #36634
 1023             =ClrDA2aOK      EQU     #36266
 1024             =ClrDA2bBad     EQU     #3665E
 1025             =ClrDA2bNoCh    EQU     #365B6
 1026             =ClrDA2bOK      EQU     #3627F
 1027             =ClrDA3OK       EQU     #362AC
 1028             =ClrInAplet     EQU     #3F5C0
 1029             =ClrListUtil    EQU     #3F60E
 1030             =ClrSysFlag     EQU     #193D7
 1031             =ClrUserFlag    EQU     #193CB
 1032             =CodePl>%rc.p   EQU     #26068
 1033             =Connecting     EQU     #11E6F
 1034             =Contxt+Offs    EQU     #28890
 1035             =CopyRegCOb     EQU     #2E5CB
 1036             =DA1Bad?        EQU     #365EE
 1037             =DA1OK?         EQU     #35F55
 1038             =DA2OK?         EQU     #36045
 1039             =DA2aBad?       EQU     #36618
 1040             =DA2aLess1OK?   EQU     #36162
 1041             =DA2aOK?        EQU     #35FA5
 1042             =DA2bNoCh?      EQU     #3659A
 1043             =DA2bOK?        EQU     #35FF5
 1044             =DA3OK?         EQU     #3605E
 1045             =DA3OK?NOTIT    EQU     #3611C
 1046             =DAsOK?         EQU     #360AE
 1047             =DECOMP$        EQU     #20DC3
 1048             =DEPTH          EQU     #0314C
 1049             =DIMLIMITS      EQU     #171EE     sup
 1050             =DISPN          EQU     #1E701
 1051             =DISPROW1       EQU     #1E735
 1052             =DISPROW2       EQU     #1E745
 1053             =DISPROW3       EQU     #1E755
 1054             =DISPROW4       EQU     #1E765
 1055             =DISPROW5       EQU     #1E775
 1056             =DISPROW6       EQU     #1E785
 1057             =DISPROW7       EQU     #1E795
 1058             =DISPROW8       EQU     #1E7A5
 1059             =DO             EQU     #07BD0
 1060             =DO#EXIT        EQU     #209AE
 1061             =DO$EXIT        EQU     #209C7
 1062             =DO>STR         EQU     #205CB
 1063             =DOARRY         EQU     #029E8
 1064             =DOBAK          EQU     #02B62
 1065             =DOBIND         EQU     #07CBD
 1066             =DOBINT         EQU     #02911
 1067             =DOCHAR         EQU     #029BF
 1068             =DOCLLCD        EQU     #3F334
 1069             =DOCMP          EQU     #02977
 1070             =DOCODE         EQU     #02DCC
 1071             =DOCOL          EQU     #02D9D
 1072             =DOCSTR         EQU     #02A2C
 1073             =DODISP         EQU     #20652
 1074             =DOECMP         EQU     #0299D
 1075             =DOERASE        EQU     #3F336
 1076             =DOEREL         EQU     #02955
 1077             =DOEXT          EQU     #02ADA
 1078             =DOEXT0         EQU     #02B88
 1079             =DOEXT1         EQU     #02BAA
 1080             =DOEXT2         EQU     #02BCC
 1081             =DOEXT3         EQU     #02BEE
 1082             =DOEXT4         EQU     #02C10
 1083             =DOFINISH       EQU     #3F293
 1084             =DOFLASHP       EQU     #02775
 1085             =DOGROB         EQU     #02B1E
 1086             =DOHSTR         EQU     #02A4E
 1087             =DOHXS          EQU     #02A4E
 1088             =DOIDNT         EQU     #02E48
 1089             =DOINDIR        EQU     #10A07
 1090             =DOLAM          EQU     #02E6D
 1091             =DOLCD>         EQU     #3F338
 1092             =DOLCD>g0       EQU     #3F3FD
 1093             =DOLIB          EQU     #02B40
 1094             =DOLIST         EQU     #02A74
 1095             =DOLNKARRY      EQU     #02A0A
 1096             =DOREAL         EQU     #02933
 1097             =DOROMP         EQU     #02E92
 1098             =DOROOT         EQU     #3F78F
 1099             =DORRP          EQU     #02A96
 1100             =DOSHOWIT1      EQU     #3F60F
 1101             =DOSHOWIT1C     EQU     #192D4
 1102             =DOSYMB         EQU     #02AB8
 1103             =DOTAG          EQU     #02AFC
 1104             =DOWAIT         EQU     #3A7C7
 1105             =DROP           EQU     #03244
 1106             =DROP#1-        EQU     #100BF
 1107             =DROP'          EQU     #101CD
 1108             =DROPDUP        EQU     #0E322
 1109             =DROPFALSE      EQU     #0DDDD
 1110             =DROPLOOP       EQU     #0FD5E
 1111             =DROPNDROP      EQU     #10821
 1112             =DROPNULL$      EQU     #05550
 1113             =DROPONE        EQU     #0E4C1
 1114             =DROPOVER       EQU     #0F90A
 1115             =DROPRDROP      EQU     #0FBE1
 1116             =DROPROT        EQU     #0F8A6
 1117             =DROPSWAP       EQU     #0E287
 1118             =DROPTRUE       EQU     #0DDD4
 1119             =DROPZERO       EQU     #0E0E0
 1120             =DUMP           EQU     #0DA21
 1121             =DUP            EQU     #03188
 1122             =DUP#0<>        EQU     #0DE7F
 1123             =DUP#0<>WHILE   EQU     #0FCF0
 1124             =DUP#0=         EQU     #0DE11
 1125             =DUP#0=IT       EQU     #106C3
 1126             =DUP#0=ITE      EQU     #10740
 1127             =DUP#0=case     EQU     #0D45A
 1128             =DUP#0=csDROP   EQU     #10538
 1129             =DUP#0=csedrp   EQU     #0D471
 1130             =DUP#0_DO       EQU     #0FD77
 1131             =DUP#1+         EQU     #0E466
 1132             =DUP#1=         EQU     #0DE70
 1133             =DUP#<7         EQU     #0FF66
 1134             =DUP$>ID        EQU     #0FB7D
 1135             =DUP%0=         EQU     #10425
 1136             =DUP'           EQU     #101A5
 1137             =DUP1LAMBIND    EQU     #0FDC2
 1138             =DUP3PICK#+     EQU     #0FFE3
 1139             =DUP@           EQU     #0F4DF
 1140             =DUPDUP         EQU     #0F593
 1141             =DUPINCOMP      EQU     #0FAC9
 1142             =DUPINDEX@      EQU     #0FD09
 1143             =DUPLEN$        EQU     #0E336
 1144             =DUPLENCOMP     EQU     #0FB19
 1145             =DUPNULL$?      EQU     #0FAF1
 1146             =DUPNULLCOMP?   EQU     #0FB05
 1147             =DUPNULL{}?     EQU     #102EF
 1148             =DUPONE         EQU     #10330
 1149             =DUPPICK        EQU     #0F9BE
 1150             =DUPROLL        EQU     #0F9D2
 1151             =DUPROMPTR@     EQU     #0F4F3
 1152             =DUPROT         EQU     #0F892
 1153             =DUPTWO         EQU     #1036C
 1154             =DUPTYPEARRY?   EQU     #0DC8A
 1155             =DUPTYPEBINT?   EQU     #0DC3F
 1156             =DUPTYPECHAR?   EQU     #0DB9A
 1157             =DUPTYPECMP?    EQU     #0DC7B
 1158             =DUPTYPECOL?    EQU     #0DCC6
 1159             =DUPTYPECSTR?   EQU     #0DC5D
 1160             =DUPTYPEEXT?    EQU     #0DD02
 1161             =DUPTYPEGROB?   EQU     #0DCD5
 1162             =DUPTYPEHSTR?   EQU     #0DC4E
 1163             =DUPTYPEIDNT?   EQU     #0DBA9
 1164             =DUPTYPELAM?    EQU     #0DC30
 1165             =DUPTYPELIST?   EQU     #0DCE4
 1166             =DUPTYPEREAL?   EQU     #0DC6C
 1167             =DUPTYPEROMP?   EQU     #0DC99
 1168             =DUPTYPERRP?    EQU     #0DCA8
 1169             =DUPTYPESYMB?   EQU     #0DCB7
 1170             =DUPTYPETAG?    EQU     #0DCF3
 1171             =DUPUNROT       EQU     #0D0D8
 1172             =DUPZERO        EQU     #1031C
 1173             =Decomp%Short   EQU     #3F345
 1174             =DecompNoNL     EQU     #3F610
 1175             =DecompOb       EQU     #3F5E7
 1176             =DefauPtXit     EQU     #2EC6F
 1177             =DefauTrcInit   EQU     #2F763
 1178             =DefaultHint    EQU     #36A17
 1179             =DemoFrames     EQU     #3F8D0
 1180             =Digits@        EQU     #27213
 1181             =DisableIntr    EQU     #0114C
 1182             =DispMenu       EQU     #10E29
 1183             =DispMenu.1     EQU     #10E3D
 1184             =DispMsgBox     EQU     #3F349
 1185             =DispXFunc      EQU     #30473
 1186             =DispYFunc      EQU     #2FCDB
 1187             =DoAlert        EQU     #3F34B
 1188             =DoAlert&Query  EQU     #3F34C
 1189             =DoApletLib     EQU     #3F611
 1190             =DoAs2Col       EQU     #3F401
 1191             =DoBadKey       EQU     #23E15
 1192             =DoCApNoteV     EQU     #3F34E
 1193             =DoCApPlotSV    EQU     #3F34F
 1194             =DoCApPlotV     EQU     #3F612
 1195             =DoCApSketchV   EQU     #3F350
 1196             =DoCApSymbSV    EQU     #3F351
 1197             =DoCApSymbV     EQU     #3F613
 1198             =DoCApTableSV   EQU     #3F352
 1199             =DoCApTableV    EQU     #3F614
 1200             =DoCKeyCancel   EQU     #3F353
 1201             =DoCKeyChAll    EQU     #3F354
 1202             =DoCKeyCheck    EQU     #3F355
 1203             =DoCKeyOK       EQU     #3F356
 1204             =DoCKeyUnChAll  EQU     #3F357
 1205             =DoCurrAplet    EQU     #3F615
 1206             =DoDemo         EQU     #3F8D1
 1207             =DoDispBorder   EQU     #3F616
 1208             =DoDispField    EQU     #3F5C1
 1209             =DoDispList     EQU     #3F617
 1210             =DoDispPrompt   EQU     #3F618
 1211             =DoEditLCancel  EQU     #3F6FD
 1212             =DoEditLOK      EQU     #3F6FF
 1213             =DoEditLine     EQU     #3F701
 1214             =DoGetObFrSto   EQU     #3F294
 1215             =DoIOErrAlert   EQU     #3F295
 1216             =DoIOStatusBox  EQU     #3F296
 1217             =DoInApLbCxt    EQU     #17236
 1218             =DoInAppCxt     EQU     #12ACF
 1219             =DoInCalcCxt    EQU     #12AB6
 1220             =DoInCxt        EQU     #12A5C
 1221             =DoInFuncCxt    EQU     #12AE8
 1222             =DoInNotCxt     EQU     #28037
 1223             =DoInOtherCxt   EQU     #12B7E
 1224             =DoInParamCxt   EQU     #12B1A
 1225             =DoInPgmCxt     EQU     #27B91
 1226             =DoInPolarCxt   EQU     #12B01
 1227             =DoInSeqCxt     EQU     #12B33
 1228             =DoInSolveCxt   EQU     #12B65
 1229             =DoInStatCxt    EQU     #12B4C
 1230             =DoInputForm    EQU     #15A41
 1231             =DoKeyCancel    EQU     #3F359
 1232             =DoKeyCheck     EQU     #3F619
 1233             =DoKeyChoos/Ck  EQU     #3F61B
 1234             =DoKeyChoose    EQU     #3F61A
 1235             =DoKeyEdit      EQU     #3F61C
 1236             =DoKeyOK        EQU     #3F61D
 1237             =DoMKeyOK       EQU     #3F35B
 1238             =DoMatEdit      EQU     #3F702
 1239             =DoMsgBox       EQU     #3F35D
 1240             =DoQueryBox     EQU     #3F363
 1241             =DoRecv/GetOb   EQU     #3F02B
 1242             =DoRecvObFrEls  EQU     #3F297
 1243             =DoRestCovWin   EQU     #3F6B2 partial match
 1244             =DoResultTab    EQU     #3F80D
 1245             =DoRomPtrKey    EQU     #24376
 1246             =DoSaveCovWin   EQU     #3F6B1 partial match
 1247             =DoSendOb       EQU     #3F02C
 1248             =DoSendObToCDi  EQU     #3F298
 1249             =DoSendObToDir  EQU     #3F299
 1250             =DoSendObToEls  EQU     #3F2D8
 1251             =DoSendObToSto  EQU     #3F29A
 1252             =DoSpecAlert    EQU     #3F61E
 1253             =Docrunchc      EQU     #1924D
 1254             =Done?CkNoNul:  EQU     #16C90
 1255             =DropJunk       EQU     #352C0
 1256             =DropSysObs     EQU     #15EAD
 1257             =DummyMenuErr   EQU     #38304
 1258             =DummyVar       EQU     #28A40
 1259             =EDITDECOMP$    EQU     #20CB9
 1260             =EIGHT          EQU     #04099
 1261             =EIGHTEEN       EQU     #040FD
 1262             =EIGHTY         EQU     #04369
 1263             =EIGHTYEIGHT    EQU     #043B9
 1264             =EIGHTYNINE     EQU     #043C3
 1265             =EIGHTYONE      EQU     #04373
 1266             =ELEVEN         EQU     #040B7
 1267             =EQ             EQU     #03B2E
 1268             =EQIT           EQU     #106AA
 1269             =EQITE          EQU     #106F0
 1270             =EQLookup       EQU     #1090C
 1271             =EQOR           EQU     #0FEE4
 1272             =EQOVER         EQU     #0F91E
 1273             =EQUAL          EQU     #03B97
 1274             =EQUALNOT       EQU     #0FEBC
 1275             =EQUALNOTcase   EQU     #1066E
 1276             =EQUALOR        EQU     #0FEF8
 1277             =EQUALPOSCMP    EQU     #108DF
 1278             =EQUALPOSCOMP   EQU     #108DF
 1279             =EQUALcase      EQU     #10579
 1280             =EQUALcasedrp   EQU     #1051F
 1281             =EQcase         EQU     #0D4FC
 1282             =EQcasedrop     EQU     #0D483
 1283             =ERRBEEP        EQU     #20782
 1284             =ERRJMP         EQU     #056CF
 1285             =ERROR@         EQU     #054F8
 1286             =ERRORCLR       EQU     #05545
 1287             =ERROROUT       EQU     #100D3
 1288             =ERRORSTO       EQU     #05520
 1289             =ERRSET         EQU     #0565C
 1290             =ERRTRAP        EQU     #056B6
 1291             =EVAL           EQU     #0775C
 1292             =EVALCRUNCH     EQU     #20BBA
 1293             =EXITMSGSTO     EQU     #05635
 1294             =EXPAND         EQU     #0D7E5
 1295             =EXTN           EQU     #05C3A
 1296             =EXTOBOB        EQU     #11E8D
 1297             =EXTREAL        EQU     #04913
 1298             =EXTSYM         EQU     #0496D
 1299             =EditExstCase   EQU     #10646
 1300             =ElsieGet       EQU     #3F29B
 1301             =ElsiePkt       EQU     #3F29C
 1302             =ElsieSend      EQU     #3F29D
 1303             =Embedded?      EQU     #0E8C2
 1304             =EmptyList?     EQU     #3F36A
 1305             =EmptyRList?    EQU     #3F61F
 1306             =EnsureMenuOff  EQU     #38381
 1307             =EnterGraphView EQU     #380FE
 1308             =EnterTextView  EQU     #380CC
 1309             =EraseGraph     EQU     #3F5F0
 1310             =EraseGrob      EQU     #3F620
 1311             =Err#Chr00      EQU     #11C0D
 1312             =Err#Cont       EQU     #11CCB
 1313             =Err#Kill       EQU     #11C3F
 1314             =Err#NoLstArg   EQU     #11CE9
 1315             =Err#NoLstStk   EQU     #11C49
 1316             =EvalPart1      EQU     #17CC5
 1317             =EvalPart2      EQU     #17CD9
 1318             =EvalPart3      EQU     #17CED
 1319             =ExitAtLOOP     EQU     #1088A
 1320             =Extremum@      EQU     #273A3
 1321             =FALSE          EQU     #03AC0
 1322             =FALSE'         EQU     #10236
 1323             =FALSETRUE      EQU     #0FE03
 1324             =FAreaBad?      EQU     #3F631
 1325             =FIFTEEN        EQU     #040DF
 1326             =FIFTY          EQU     #0423D
 1327             =FIFTYEIGHT     EQU     #0428D
 1328             =FIFTYFIVE      EQU     #0426F
 1329             =FIFTYFOUR      EQU     #04265
 1330             =FIFTYNINE      EQU     #04297
 1331             =FIFTYONE       EQU     #04247
 1332             =FIFTYSEVEN     EQU     #04283
 1333             =FIFTYSIX       EQU     #04279
 1334             =FIFTYTHREE     EQU     #0425B
 1335             =FIFTYTWO       EQU     #04251
 1336             =FIVE           EQU     #0407B
 1337             =FIVEFOUR       EQU     #04391
 1338             =FIVESIX        EQU     #043A5
 1339             =FIVETHREE      EQU     #04387
 1340             =FLUSHKEYS      EQU     #00C3A
 1341             =FORTY          EQU     #041D9
 1342             =FORTYEIGHT     EQU     #04229
 1343             =FORTYFIVE      EQU     #0420B
 1344             =FORTYFOUR      EQU     #04201
 1345             =FORTYNINE      EQU     #04233
 1346             =FORTYONE       EQU     #041E3
 1347             =FORTYSEVEN     EQU     #0421F
 1348             =FORTYSIX       EQU     #04215
 1349             =FORTYTHREE     EQU     #041F7
 1350             =FORTYTWO       EQU     #041ED
 1351             =FOUR           EQU     #04071
 1352             =FOURFIVE       EQU     #042FB
 1353             =FOURROLLROT    EQU     #0F8E2
 1354             =FOURTEEN       EQU     #040D5
 1355             =FOURTHREE      EQU     #042E7
 1356             =FOURTWO        EQU     #042DD
 1357             =FOURpsh        EQU     #3F08F
 1358             =FSTFLOATROM#   EQU     #04A49
 1359             =FSTMACROROM#   EQU     #11D61
 1360             =FTypeCheck?    EQU     #3F623
 1361             =FTypeFixedL?   EQU     #3F622
 1362             =FTypeList?     EQU     #3F624
 1363             =FTypeText?     EQU     #3F625
 1364             =FUNCPLOT       EQU     #3F626
 1365             =FalseFalse     EQU     #3F090
 1366             =FalseTrue      EQU     #0FE03
 1367             =FitLeftSmF     EQU     #3F36F
 1368             =FitRightSmF    EQU     #3F627
 1369             =Format@        EQU     #271FF
 1370             =FuncPLoop      EQU     #3F628
 1371             =FuncPSetup1    EQU     #3F629
 1372             =FuncSplitViewers       EQU     #16D7E
 1373             =GARBAGE        EQU     #06742
 1374             =GBUFF          EQU     #1E97F
 1375             =GDISP?         EQU     #1F4C2
 1376             =GDISPCENTER    EQU     #3F62F
 1377             =GET@tTYPER     EQU     #12C7E
 1378             =GETATELN       EQU     #0371D
 1379             =GETEXITMSG     EQU     #05605
 1380             =GETKEY         EQU     #2661F
 1381             =GETLAM         EQU     #07D7E
 1382             =GETLAMPAIR     EQU     #0D3A1
 1383             =GETPTRLOOP     EQU     #058FC
 1384             =GETSERIAL      EQU     #3F29E
 1385             =GETTHEMESG     EQU     #05576
 1386             =GETTOUCH       EQU     #04F9E
 1387             =GETXMAX        EQU     #3F6A1
 1388             =GETXMIN        EQU     #3F6A3
 1389             =GETXPOS        EQU     #3F40D
 1390             =GETYMAX        EQU     #3F6A0
 1391             =GETYMIN        EQU     #3F6A2
 1392             =GETYPOS        EQU     #3F40E
 1393             =GPOverWrALp    EQU     #03672
 1394             =GPPushFLoop    EQU     #0DDA3
 1395             =GPPushTLoop    EQU     #0DD8A
 1396             =GROB!          EQU     #1D704
 1397             =GROB!ZERO      EQU     #1DAF8
 1398             =GROB!ZERODRP   EQU     #10105
 1399             =GROB+#         EQU     #3F632
 1400             =GROB>GDISP     EQU     #1F2AE
 1401             =GROBBUFF!      EQU     #3F633
 1402             =GROBDIM        EQU     #150A4
 1403             =GROBDIMw       EQU     #1047F
 1404             =GROBVIEW       EQU     #3F634
 1405             =GetApDirList   EQU     #3F5AB
 1406             =GetBVars.1     EQU     #3F29F
 1407             =GetChoiceFmt   EQU     #3F635
 1408             =GetChoiceList  EQU     #3F636
 1409             =GetDASpecFlag  EQU     #3F375
 1410             =GetElNoRomp    EQU     #15C02
 1411             =GetLastNotThis EQU     #3F410
 1412             =GetNextFId     EQU     #3F637
 1413             =GetNextToken   EQU     #3F0A0
 1414             =GetObType$     EQU     #3F2A1
 1415             =GetObTypePr$   EQU     #3F2A0
 1416             =GetPart1       EQU     #17C89
 1417             =GetPart2       EQU     #17C9D
 1418             =GetPart3       EQU     #17CB1
 1419             =GetPrevFId     EQU     #3F638
 1420             =GraphTableUI   EQU     #3F5EC
 1421             =GraphZoomUI    EQU     #3F5ED
 1422             =GtoField       EQU     #3F639
 1423             =HARDBUFF       EQU     #1E94F
 1424             =HARDBUFF2      EQU     #1E95F
 1425             =HARDHEIGHT     EQU     #1EE86
 1426             =HEIGHTENGROB   EQU     #1F0EB
 1427             =HOME>BAK       EQU     #09DBB
 1428             =HOMEDIR        EQU     #09698
 1429             =HTick@         EQU     #27033
 1430             =HXSREAL        EQU     #04733
 1431             =HZoom@         EQU     #2705B
 1432             =HisWidth@      EQU     #2770E
 1433             =Hmax@          EQU     #27736
 1434             =Hmin@          EQU     #27722
 1435             =ID>$           EQU     #063C9
 1436             =IDARRY         EQU     #04431
 1437             =IDCMP          EQU     #0441D
 1438             =IDLIST         EQU     #0443B
 1439             =IDLISTOB       EQU     #11D57
 1440             =IDREAL         EQU     #04413
 1441             =IDREALOB       EQU     #11D4D
 1442             =IFECheck       EQU     #3F63A
 1443             =IFEChoosByChr  EQU     #3F63B
 1444             =IFEChooseNext  EQU     #3F63C
 1445             =IFEDispClient  EQU     #3F63D
 1446             =IFEDispField   EQU     #3F63E
 1447             =IFEDispHelp    EQU     #3F63F
 1448             =IFEDispLabel   EQU     #3F640
 1449             =IFEDispTitle   EQU     #3F641
 1450             =IFEUnShowSel   EQU     #3F642
 1451             =IFEdLineMenu   EQU     #3F643
 1452             =IFMenu         EQU     #3F644
 1453             =IFSymbViewUI   EQU     #3F6AA
 1454             =INCOMPDROP     EQU     #0F462
 1455             =INDEX@         EQU     #079FA
 1456             =INDEX@#-       EQU     #1006F
 1457             =INDEXSTO       EQU     #07A49
 1458             =INHARDROM?     EQU     #140B7
 1459             =INNER#1=       EQU     #0FF7F
 1460             =INNERCOMP      EQU     #05C68
 1461             =INNERDUP       EQU     #0F51B
 1462             =INTEGER337     EQU     #11CD5
 1463             =INTEMNOTREF?   EQU     #0731C
 1464             =INT_00         EQU     #38641
 1465             =INT_01         EQU     #38646
 1466             =INT_02         EQU     #3864B
 1467             =INT_03         EQU     #38650
 1468             =INT_04         EQU     #38655
 1469             =INT_05         EQU     #3865A
 1470             =INT_06         EQU     #3865F
 1471             =INT_07         EQU     #38664
 1472             =INT_08         EQU     #38669
 1473             =INT_09         EQU     #3866E
 1474             =INT_0A         EQU     #38673
 1475             =INT_0B         EQU     #38678
 1476             =INT_0C         EQU     #3867D
 1477             =INT_0D         EQU     #38682
 1478             =INT_0E         EQU     #38687
 1479             =INT_0F         EQU     #3868C
 1480             =INT_10         EQU     #38691
 1481             =INT_11         EQU     #38696
 1482             =INT_12         EQU     #3869B
 1483             =INT_13         EQU     #386A0
 1484             =INT_14         EQU     #386A5
 1485             =INT_15         EQU     #386AA
 1486             =INT_16         EQU     #386AF
 1487             =INT_17         EQU     #386B4
 1488             =INT_18         EQU     #386B9
 1489             =INT_19         EQU     #386BE
 1490             =INT_1A         EQU     #386C3
 1491             =INT_1B         EQU     #386C8
 1492             =INT_1C         EQU     #386CD
 1493             =INT_1D         EQU     #386D2
 1494             =INT_1E         EQU     #386D7
 1495             =INT_1F         EQU     #386DC
 1496             =INT_NN         EQU     #385D4
 1497             =INVGROB        EQU     #1E5BD
 1498             =ISTOP@         EQU     #07A22
 1499             =ISTOPSTO       EQU     #07A6E
 1500             =IT             EQU     #0D585
 1501             =ITE            EQU     #0D6A1
 1502             =ITE_DROP       EQU     #0D621
 1503             =Id>ApNameId    EQU     #3F645
 1504             =InAplet?       EQU     #3F383
 1505             =InApletF?      EQU     #3F646
 1506             =Init2ColMets   EQU     #3F647
 1507             =InitEnab       EQU     #0A021
 1508             =InitIndep      EQU     #3F417
 1509             =InitListMets   EQU     #3F5AC
 1510             =InitMenu       EQU     #2523D
 1511             =Init_window    EQU     #3F648
 1512             =InpFormVEntry  EQU     #3F5C9
 1513             =InpFormVExit   EQU     #3F5C4
 1514             =InpFormViewUI  EQU     #3F5C5
 1515             =InvalServCmd   EQU     #11E65
 1516             =InvertField    EQU     #3F649
 1517             =IsIFMenu?      EQU     #3F64A
 1518             =IsNullField?   EQU     #3F64B
 1519             =IsTaskSwKey?   EQU     #245E2
 1520             =Isect@         EQU     #2737B
 1521             =JINDEX@        EQU     #07A31
 1522             =JINDEXSTO      EQU     #07A86
 1523             =JSTOP@         EQU     #07A3D
 1524             =JSTOPSTO       EQU     #07A9B
 1525             =JUMPBOT        EQU     #3F64C
 1526             =JUMPLEFT       EQU     #3F64D
 1527             =JUMPRIGHT      EQU     #3F64E
 1528             =JUMPTOP        EQU     #3F64F
 1529             =JstGETTHEMSG   EQU     #05599
 1530             =KEYINBUFFER?   EQU     #26943
 1531             =KILLGDISP      EQU     #1F37B
 1532             =Key>StdKeyOb   EQU     #23C2B
 1533             =KeyFace        EQU     #36F79
 1534             =LAMANYANY      EQU     #11D61
 1535             =LAMLIST        EQU     #044E5
 1536             =LAMREAL        EQU     #044B3
 1537             =LAST$          EQU     #0FB55
 1538             =LASTBUTN       EQU     #28A1A
 1539             =LASTRAM-WORD   EQU     #08C35
 1540             =LEDispBorder   EQU     #3F650
 1541             =LEDispItem     EQU     #3F651
 1542             =LEDispList     EQU     #3F652
 1543             =LEDispPrompt   EQU     #3F653
 1544             =LEN$           EQU     #05DEF
 1545             =LENCOMP        EQU     #05E34
 1546             =LESetIDecomp   EQU     #3F654
 1547             =LESetItem      EQU     #3F384
 1548             =LESetRowWidth  EQU     #3F655
 1549             =LF$            EQU     #124C4
 1550             =LHighlight     EQU     #3F656
 1551             =LINECHANGE     EQU     #3F657
 1552             =LINEOFF        EQU     #3F388
 1553             =LINEOFF3       EQU     #3F389
 1554             =LINEON         EQU     #3F38A
 1555             =LINEON3        EQU     #3F38B
 1556             =LISTCMP        EQU     #0437D
 1557             =LISTID         EQU     #043A5
 1558             =LISTLAM        EQU     #043AF
 1559             =LISTLISTOB     EQU     #11D43
 1560             =LISTOB         EQU     #04369
 1561             =LISTREAL       EQU     #04373
 1562             =LISTREALOB     EQU     #11D2F
 1563             =LISTREALREAL   EQU     #11D39
 1564             =LOOP           EQU     #07B0D
 1565             =LSTBIMACROM#   EQU     #11D61
 1566             =LUnHighlight   EQU     #3F658
 1567             =LastBut0       EQU     #28918
 1568             =LastBut1       EQU     #2891F
 1569             =LastBut10      EQU     #2895E
 1570             =LastBut11      EQU     #28965
 1571             =LastBut12      EQU     #2896C
 1572             =LastBut13      EQU     #28973
 1573             =LastBut14      EQU     #2897A
 1574             =LastBut15      EQU     #28981
 1575             =LastBut16      EQU     #28988
 1576             =LastBut17      EQU     #2898F
 1577             =LastBut18      EQU     #28996
 1578             =LastBut19      EQU     #2899D
 1579             =LastBut2       EQU     #28926
 1580             =LastBut20      EQU     #289A4
 1581             =LastBut21      EQU     #289AB
 1582             =LastBut22      EQU     #289B2
 1583             =LastBut23      EQU     #289B9
 1584             =LastBut24      EQU     #289C0
 1585             =LastBut25      EQU     #289C7
 1586             =LastBut26      EQU     #289CE
 1587             =LastBut27      EQU     #289D5
 1588             =LastBut28      EQU     #289DC
 1589             =LastBut29      EQU     #289E3
 1590             =LastBut3       EQU     #2892D
 1591             =LastBut30      EQU     #289EA
 1592             =LastBut31      EQU     #289F1
 1593             =LastBut32      EQU     #289F8
 1594             =LastBut4       EQU     #28934
 1595             =LastBut5       EQU     #2893B
 1596             =LastBut6       EQU     #28942
 1597             =LastBut7       EQU     #28949
 1598             =LastBut8       EQU     #28950
 1599             =LastBut9       EQU     #28957
 1600             =LastEq@        EQU     #270D3
 1601             =LastIndep@     EQU     #270BF
 1602             =LastX@         EQU     #27097
 1603             =LastY@         EQU     #270AB
 1604             =LeaveGraphView EQU     #380E5
 1605             =LeaveTextView  EQU     #380E5
 1606             =ListBar        EQU     #3F659
 1607             =ListNames      EQU     #3F65A
 1608             =ListOfEqs@     EQU     #273DA
 1609             =LockAlpha      EQU     #25023
 1610             =Lookup         EQU     #0EDF0
 1611             =Lookup.1       EQU     #0EE09
 1612             =M+prep         EQU     #3F2A2
 1613             =MAKEARRY       EQU     #171FA     sup
 1614             =MAKEGROB       EQU     #1D622
 1615             =MAKERRP        EQU     #07FBD
 1616             =MATCON         EQU     #17206     sup
 1617             =MATREDIM       EQU     #17212     sup
 1618             =MATTRN         EQU     #1721E     sup
 1619             =MDIMS          EQU     #1722A     sup
 1620             =MDIMSDROP      EQU     #0F877
 1621             =MEM            EQU     #06761
 1622             =MEMERR         EQU     #04053
 1623             =MENUOFF?       EQU     #3F392
 1624             =MINUSFIVE      EQU     #11EC9
 1625             =MINUSFOUR      EQU     #11EBF
 1626             =MINUSONE       EQU     #11EA1
 1627             =MINUSTHREE     EQU     #11EB5
 1628             =MINUSTWO       EQU     #11EAB
 1629             =Make1stAplet   EQU     #3F65C
 1630             =MakeBoxLabel   EQU     #10FC6
 1631             =MakeDirLabel   EQU     #11028
 1632             =MakeInvLabel   EQU     #1108A
 1633             =MakeNoteVTtl   EQU     #3F393
 1634             =MakeNumSVTtl   EQU     #3F65D
 1635             =MakeNumVTtl    EQU     #3F65B
 1636             =MakePlotSVTtl  EQU     #3F65E
 1637             =MakePlotVTtl   EQU     #3F65F
 1638             =MakeSketVTtl   EQU     #3F660
 1639             =MakeStdLabel   EQU     #10F64
 1640             =MakeSymbSVTtl  EQU     #3F661
 1641             =MakeSymbVTtl   EQU     #3F662
 1642             =MakeTitleBar   EQU     #3F394
 1643             =MakeViewTitle  EQU     #3F663
 1644             =MemStoAns      EQU     #3F712
 1645             =MiniVar        EQU     #38345
 1646             =ModifierKey?   EQU     #23FC7
 1647             =MoreDown?      EQU     #3F664
 1648             =MoreU/D?       EQU     #3F665
 1649             =MoreUp?        EQU     #3F666
 1650             =MsgBoxMenu     EQU     #3F396
 1651             =N+1DROP        EQU     #0F84F
 1652             =NDROP          EQU     #0326E
 1653             =NDUP           EQU     #031D9
 1654             =NDUPN          EQU     #15337
 1655             =NEWINDEP       EQU     #3F397
 1656             =NEWLINE$       EQU     #124C4
 1657             =NEWLINE$&$     EQU     #0FA79
 1658             =NEWLINE&$      EQU     #0FA79
 1659             =NEXTCOMPOB     EQU     #0F15A
 1660             =NINE           EQU     #040A3
 1661             =NINETEEN       EQU     #04107
 1662             =NINETY         EQU     #043CD
 1663             =NINETYEIGHT    EQU     #0441D
 1664             =NINETYFIVE     EQU     #043FF
 1665             =NINETYFOUR     EQU     #043F5
 1666             =NINETYNINE     EQU     #04427
 1667             =NINETYTHREE    EQU     #043EB
 1668             =NINETYTWO      EQU     #043E1
 1669             =NOP            EQU     #0765C
 1670             =NOT            EQU     #03AF2
 1671             =NOT?SEMI       EQU     #0D5F5
 1672             =NOT?SWAPDROP   EQU     #0F81D
 1673             =NOTAND         EQU     #0F52F
 1674             =NOTESCXT!      EQU     #126D6
 1675             =NOTESCXT@      EQU     #126E6
 1676             =NOT_UNTIL      EQU     #0FCBE
 1677             =NOT_WHILE      EQU     #0FCD7
 1678             =NOTcase        EQU     #0D576
 1679             =NOTcase2DROP   EQU     #0D54D
 1680             =NOTcase2drop   EQU     #0D4D9
 1681             =NOTcaseDROP    EQU     #0D529
 1682             =NOTcaseFALSE   EQU     #1014B
 1683             =NOTcaseTRUE    EQU     #10132
 1684             =NOTcasedrop    EQU     #0D4B1
 1685             =NOTcsdrpfls    EQU     #10380
 1686             =NTHCOMDDUP     EQU     #0F5F7
 1687             =NTHCOMPDROP    EQU     #0F476
 1688             =NTHELCOMP      EQU     #05E6F
 1689             =NTHOF          EQU     #108F8
 1690             =NULL$          EQU     #05D98
 1691             =NULL$?         EQU     #05D28
 1692             =NULL$SWAP      EQU     #0F633
 1693             =NULL::         EQU     #05DB6
 1694             =NULLCOMP?      EQU     #05D70
 1695             =NULLHXS        EQU     #05D8E
 1696             =NULLID         EQU     #20AFF
 1697             =NULLLAM        EQU     #109FB
 1698             =NULLSYMB       EQU     #05DAC
 1699             =NULLargcase    EQU     #16EE3
 1700             =NULL{}         EQU     #05DA2
 1701             =NUMEVAL1       EQU     #13C06
 1702             =NcaseSIZEERR   EQU     #103AD
 1703             =NcaseTYPEERR   EQU     #103C1
 1704             =NextApOfType   EQU     #3F667
 1705             =NextTextLine   EQU     #3F668
 1706             =NoExitAction   EQU     #234B0
 1707             =NotAndbitmap   EQU     #38C6B
 1708             =NotesViewUI    EQU     #3F6A9
 1709             =NullMenuKey    EQU     #29B79
 1710             =OB>BAK         EQU     #3F2A3
 1711             =OCRC           EQU     #060FD
 1712             =OFFSRRP        EQU     #07E87
 1713             =ONE            EQU     #04053
 1714             =ONE#>          EQU     #0FFCF
 1715             =ONECOLA        EQU     #10295
 1716             =ONEDUP         EQU     #10358
 1717             =ONEFALSE       EQU     #0FE2B
 1718             =ONEFALSE'      EQU     #1021D
 1719             =ONEHUNDRED     EQU     #04431
 1720             =ONEONE         EQU     #10358
 1721             =ONESWAP        EQU     #0F741
 1722             =ONE_DO         EQU     #07BA7
 1723             =ONE_EQ         EQU     #0FC7D
 1724             =ONSRRP?        EQU     #07F66
 1725             =OR             EQU     #03B75
 1726             =ORNOT          EQU     #0FEA8
 1727             =ORcase         EQU     #0E537
 1728             =OSIZE          EQU     #060BB
 1729             =OVER           EQU     #032C2
 1730             =OVER#+         EQU     #1000B
 1731             =OVER#-         EQU     #1005B
 1732             =OVER#0=        EQU     #0FF2A
 1733             =OVER#1-        EQU     #108B2
 1734             =OVER#<         EQU     #0FF3E
 1735             =OVER#=         EQU     #0DDBC
 1736             =OVER#=case     EQU     #0D445
 1737             =OVER#>         EQU     #0FFBB
 1738             =OVER'          EQU     #101E1
 1739             =OVER5PICK      EQU     #1050B
 1740             =OVERARSIZE     EQU     #0FA22
 1741             =OVERDUP        EQU     #0F5A7
 1742             =OVEREQcase     EQU     #0D4FC
 1743             =OVERINDEX@     EQU     #0FD31
 1744             =OVERSWAP       EQU     #0F60B
 1745             =OVERUNROT      EQU     #0F60B
 1746             =Ob>Seco        EQU     #10862
 1747             =OnKeyDown?     EQU     #00B38
 1748             =OpenIO         EQU     #3F040
 1749             =OpenUart?Clr   EQU     #3F2A4
 1750             =Orbitmap       EQU     #38C45
 1751             =P::N           EQU     #1677E
 1752             =PGMCXT!        EQU     #126B6
 1753             =PGMCXT@        EQU     #126C6
 1754             =PICK           EQU     #032E2
 1755             =PIXOFF         EQU     #1FCCF
 1756             =PIXOFF3        EQU     #1FCA3
 1757             =PIXON          EQU     #1FCDE
 1758             =PIXON3         EQU     #1FCB9
 1759             =PIXON?         EQU     #1FE26
 1760             =PIXON?3        EQU     #1FE1A
 1761             =POLErrorTrap   EQU     #35798
 1762             =POLKeyUI       EQU     #35743
 1763             =POLResUI&Err   EQU     #357CA
 1764             =POLRestoreUI   EQU     #357E3
 1765             =POLSaveUI      EQU     #355AE
 1766             =POLSetUI       EQU     #3565D
 1767             =POLSetUIExt    EQU     #35725
 1768             =POP#           EQU     #06E19
 1769             =PORT0ADDR      EQU     #09C3C
 1770             =POS$           EQU     #0EE54
 1771             =POS$REV        EQU     #0EE60
 1772             =POSCHR         EQU     #0EE54
 1773             =POSCHRREV      EQU     #0EE60
 1774             =POSCOMP        EQU     #0ED0F
 1775             =PREVRAM-WORD   EQU     #08C85
 1776             =PRINT          EQU     #3F2A5
 1777             =PRLG           EQU     #028FC
 1778             =PROGIDCMP      EQU     #11D93
 1779             =PROGIDEXT      EQU     #11DA7
 1780             =PROGIDLIST     EQU     #11D9D
 1781             =PROGIDREAL     EQU     #11D89
 1782             =PROTERR        EQU     #11E5B
 1783             =PTYPE>PINFO    EQU     #347CC
 1784             =PURGE          EQU     #0952D
 1785             =PUSH%LOOP      EQU     #1B374
 1786             =PUSHA          EQU     #03A86
 1787             =PUTEL          EQU     #18DBC
 1788             =PUTLAM         EQU     #07DC2
 1789             =PUTLIST        EQU     #3F043
 1790             =PUTSERIAL      EQU     #3F2A6
 1791             =PUTXMAX        EQU     #16EB1
 1792             =PUTXMIN        EQU     #3F69F
 1793             =PUTYMAX        EQU     #16ECA
 1794             =PUTYMIN        EQU     #3F69E
 1795             =PageDnNGrob    EQU     #15573
 1796             =PageDnYGrob    EQU     #1552F
 1797             =PageUpNGrob    EQU     #154EB
 1798             =PageUpYGrob    EQU     #154A7
 1799             =ParOuterLoop   EQU     #35577
 1800             =ParseExpr      EQU     #24E34
 1801             =PickedEqs@     EQU     #3F41D
 1802             =PictViewUI     EQU     #3F6B0
 1803             =PlaceFVals     EQU     #3F669
 1804             =Plot2Flg@      EQU     #270FB
 1805             =PlotCKSUM@     EQU     #2710F
 1806             =PlotFlag@      EQU     #270E7
 1807             =PlotOvViewUI   EQU     #3F62A
 1808             =PlotSetViewUI  EQU     #3F6AB
 1809             =PlotViewUI     EQU     #3F66A
 1810             =PopASavptr     EQU     #19ACC
 1811             =Port0Ids       EQU     #3F2AA
 1812             =PrepCurrAplet  EQU     #3F66B
 1813             =PrepEdLKeyOb   EQU     #3F3AA
 1814             =PrintHist      EQU     #3F2A7
 1815             =PrintLcd       EQU     #3F2A8
 1816             =PrintVar       EQU     #3F2A9
 1817             =PrintVarOb     EQU     #3F0C4
 1818             =PurgeAplet     EQU     #3F66D
 1819             =PurgeApletOb   EQU     #3F66C
 1820             =Push#FLoop     EQU     #143AF
 1821             =Put3x5         EQU     #3F20A
 1822             =Put5x7         EQU     #38C7E
 1823             =PutDASpecFlag  EQU     #3F3AB
 1824             =Putbitmap      EQU     #38BC8
 1825             =R>             EQU     #077F8
 1826             =R@             EQU     #077EB
 1827             =RAM-WORDNAME   EQU     #08BF2
 1828             =RDROP          EQU     #07790
 1829             =RDROPCOLA      EQU     #0E4D3
 1830             =RDUP           EQU     #20898
 1831             =REALLISTREAL   EQU     #11CD5
 1832             =REALOBOB       EQU     #04A49
 1833             =REALREALOB     EQU     #11C2B
 1834             =REALSTRID      EQU     #11C85
 1835             =REALSTRSTR     EQU     #11C67
 1836             =REALcase       EQU     #1060A
 1837             =RECLAIMDISP    EQU     #1F3C6
 1838             =REDIMPREP      EQU     #3F80E
 1839             =REPEAT         EQU     #079BE
 1840             =REPEATER       EQU     #1747B
 1841             =REPEATERCH     EQU     #1747B
 1842             =REPKEY?        EQU     #05051
 1843             =REPLACE        EQU     #08ED9
 1844             =RESOROMP       EQU     #161CC
 1845             =RNDXY          EQU     #1C44A
 1846             =ROLL           EQU     #03325
 1847             =ROLLDROP       EQU     #0F863
 1848             =ROLLSWAP       EQU     #0F61F
 1849             =ROM-WORD?      EQU     #0DB30
 1850             =ROMPANY        EQU     #049A9
 1851             =ROMPTR>#       EQU     #095D2
 1852             =ROMPTR@        EQU     #087B6
 1853             =ROT            EQU     #03295
 1854             =ROT#+          EQU     #0FFF7
 1855             =ROT#+SWAP      EQU     #0F6A6
 1856             =ROT#-          EQU     #10047
 1857             =ROT#1+         EQU     #10097
 1858             =ROT#1+UNROT    EQU     #150FC
 1859             =ROT+SWAP       EQU     #0F6A6
 1860             =ROT2DROP       EQU     #0E2A1
 1861             =ROT2DUP        EQU     #0F557
 1862             =ROTAND         EQU     #0F56B
 1863             =ROTDROP        EQU     #0CD01
 1864             =ROTDROPSWAP    EQU     #0CCEE
 1865             =ROTDUP         EQU     #0E2F0
 1866             =ROTOVER        EQU     #0F57F
 1867             =ROTROT2DROP    EQU     #0CF16
 1868             =ROTSWAP        EQU     #0CCC7
 1869             =ROTUntop&      EQU     #107A9
 1870             =RPICK          EQU     #2094F
 1871             =RPIT           EQU     #078D6
 1872             =RPITE          EQU     #0789C
 1873             =RROLL          EQU     #208ED
 1874             =RSKIP          EQU     #100E7
 1875             =RSWAP          EQU     #0CC9D
 1876             =RclAplet       EQU     #3F3B7
 1877             =RclAplet?Err   EQU     #3F66E
 1878             =RclFieldVal    EQU     #3F66F
 1879             =RclResetVal    EQU     #3F670
 1880             =ReCalcFlag@    EQU     #27786
 1881             =Replace_List   EQU     #3F671
 1882             =Retry          EQU     #11E79
 1883             =Root@          EQU     #27353
 1884             =SAVPTR         EQU     #06F73
 1885             =SCROLLDOWN     EQU     #3F3B9
 1886             =SCROLLLEFT     EQU     #3F672
 1887             =SCROLLRIGHT    EQU     #3F673
 1888             =SCROLLUP       EQU     #3F3BA
 1889             =SEFINISH       EQU     #3F2AB
 1890             =SEMI           EQU     #0312B
 1891             =SETLBERR       EQU     #05763
 1892             =SETMEMERR      EQU     #0576F
 1893             =SETNONEXTERR   EQU     #131EC
 1894             =SETPLOTENV     EQU     #3F3BB
 1895             =SETROMPERR     EQU     #057CF
 1896             =SETSIZEERR     EQU     #131FC
 1897             =SETSTACKERR    EQU     #1321C
 1898             =SETTYPEERR     EQU     #1320C
 1899             =SEVEN          EQU     #0408F
 1900             =SEVENTEEN      EQU     #040F3
 1901             =SEVENTY        EQU     #04305
 1902             =SEVENTYEIGHT   EQU     #04355
 1903             =SEVENTYFIVE    EQU     #04337
 1904             =SEVENTYFOUR    EQU     #0432D
 1905             =SEVENTYNINE    EQU     #0435F
 1906             =SEVENTYONE     EQU     #0430F
 1907             =SEVENTYSEVEN   EQU     #0434B
 1908             =SEVENTYSIX     EQU     #04341
 1909             =SEVENTYTHREE   EQU     #04323
 1910             =SEVENTYTWO     EQU     #04319
 1911             =SIX            EQU     #04085
 1912             =SIXFIVE        EQU     #0443B
 1913             =SIXTEEN        EQU     #040E9
 1914             =SIXTY          EQU     #042A1
 1915             =SIXTYEIGHT     EQU     #042F1
 1916             =SIXTYFIVE      EQU     #042D3
 1917             =SIXTYFOUR      EQU     #042C9
 1918             =SIXTYONE       EQU     #042AB
 1919             =SIXTYSIX       EQU     #042DD
 1920             =SIXTYTHREE     EQU     #042BF
 1921             =SIXTYTWO       EQU     #042B5
 1922             =SKIP           EQU     #07926
 1923             =SKIPOB         EQU     #03019
 1924             =SLOW           EQU     #25186
 1925             =SPACE$         EQU     #124E0
 1926             =STArryList     EQU     #16C54
 1927             =STBigKeyDef    EQU     #17D47
 1928             =STDoMedium     EQU     #3F805
 1929             =STDoSmall      EQU     #3F806
 1930             =STEditKeyDef   EQU     #17D98
 1931             =STErrorGrob    EQU     #3F735
 1932             =STInitCols     EQU     #3F807
 1933             =STInsKeyDef    EQU     #17DC8
 1934             =STJump         EQU     #3F808
 1935             =STJumpN        EQU     #3F809
 1936             =STO            EQU     #08644
 1937             =STO'           EQU     #101F5
 1938             =STOLAM         EQU     #08638
 1939             =STO_tTYPE      EQU     #26F75
 1940             =STRLIST        EQU     #0425B
 1941             =STRREALREAL    EQU     #11CF3
 1942             =STSortCol      EQU     #3F80A
 1943             =STStatsKeyDef  EQU     #17DF6
 1944             =STTableDisp    EQU     #3F736
 1945             =STTableExit    EQU     #3F737
 1946             =STTableHKeys   EQU     #3F738
 1947             =STTableInit    EQU     #3F739
 1948             =STypeAnyChr    EQU     #10D10
 1949             =STypeDirChr    EQU     #10CCA
 1950             =STypeLibChr    EQU     #10CFB
 1951             =STypeLstChr    EQU     #10CED
 1952             =STypeMatChr    EQU     #10CF4
 1953             =STypeNteChr    EQU     #10CD8
 1954             =STypePgmChr    EQU     #10CDF
 1955             =STypeTgtChr    EQU     #10D02
 1956             =STypeVarChr    EQU     #10CE6
 1957             =STypeVecChr    EQU     #10D09
 1958             =STypeZapChr    EQU     #10CD1
 1959             =SUB$           EQU     #05EEC
 1960             =SUB$1#         EQU     #14370
 1961             =SUB$SWAP       EQU     #0F647
 1962             =SUBCOMP        EQU     #05FDA
 1963             =SUBGROB        EQU     #1D9BA
 1964             =SV_?defined    EQU     #3F674
 1965             =SV_actual      EQU     #3F675
 1966             =SV_calledit    EQU     #3F676
 1967             =SV_getbody     EQU     #3F677
 1968             =SV_keycancel   EQU     #16F3F
 1969             =SV_keycheck    EQU     #16F67
 1970             =SV_keyedit     EQU     #16F7B
 1971             =SV_keyeval     EQU     #16F9C
 1972             =SV_keyok       EQU     #16F53
 1973             =SV_keyshow     EQU     #16FBD
 1974             =SV_setgrob19   EQU     #3F67B
 1975             =SV_setitem0    EQU     #3F67C
 1976             =SVarType@      EQU     #276E6
 1977             =SWAP           EQU     #03223
 1978             =SWAP#-         EQU     #0E30F
 1979             =SWAP#1+        EQU     #0E47F
 1980             =SWAP#1-        EQU     #100AB
 1981             =SWAP%%/        EQU     #10439
 1982             =SWAP%>C%       EQU     #0FB91
 1983             =SWAP&$         EQU     #0DE9A
 1984             =SWAP'          EQU     #101B9
 1985             =SWAP2DUP       EQU     #1930B
 1986             =SWAP3PICK      EQU     #104CF
 1987             =SWAP4PICK      EQU     #104F7
 1988             =SWAP4ROLL      EQU     #104A7
 1989             =SWAPCKREF      EQU     #107F9
 1990             =SWAPCOLA       EQU     #0FBFA
 1991             =SWAPDROP       EQU     #0CD73
 1992             =SWAPDROPDUP    EQU     #0E3AB
 1993             =SWAPDUP        EQU     #0E2C2
 1994             =SWAPINCOMP     EQU     #0FADD
 1995             =SWAPINDEX@     EQU     #0FD1D
 1996             =SWAPLOOP       EQU     #0FD45
 1997             =SWAPONE        EQU     #10344
 1998             =SWAPOVER#-     EQU     #10083
 1999             =SWAPROT        EQU     #0CD13
 2000             =SWAPStatFlag   EQU     #3F73B partial match
 2001             =SWAPStatFlags  EQU     #3F73B
 2002             =SWAPUnDROP     EQU     #1017D
 2003             =SWAPUnNDROP    EQU     #10191
 2004             =SWAPcompSWAP   EQU     #3F2AC
 2005             =SYMARRY        EQU     #046B1
 2006             =SYMBCMP        EQU     #045FD
 2007             =SYMBN          EQU     #05C26
 2008             =SYMBNUMSOLVE   EQU     #3F73C
 2009             =SYMBREAL       EQU     #045F3
 2010             =SYMBSYM        EQU     #0464D
 2011             =SYMBUNIT       EQU     #04675
 2012             =SYMCMP         EQU     #0469D
 2013             =SYMCMPCMP      EQU     #11DF7
 2014             =SYMCMPREAL     EQU     #11DED
 2015             =SYMCMPSYM      EQU     #11E01
 2016             =SYMEXT         EQU     #04715
 2017             =SYMID          EQU     #046C5
 2018             =SYMIDCMP       EQU     #11E15
 2019             =SYMIDEXT       EQU     #11E29
 2020             =SYMIDLIST      EQU     #11E1F
 2021             =SYMIDREAL      EQU     #11E0B
 2022             =SYMLAM         EQU     #046CF
 2023             =SYMLIST        EQU     #046BB
 2024             =SYMOB          EQU     #04689
 2025             =SYMREAL        EQU     #04693
 2026             =SYMREALCMP     EQU     #11DD9
 2027             =SYMREALREAL    EQU     #11DCF
 2028             =SYMREALSYM     EQU     #11DE3
 2029             =SYMSTR         EQU     #046A7
 2030             =SYMSYM         EQU     #046ED
 2031             =SYMSYMB        EQU     #046E3
 2032             =SYMSYMCMP      EQU     #11E3D
 2033             =SYMSYMREAL     EQU     #11E33
 2034             =SYSCONTEXT     EQU     #09698
 2035             =SYSRRP?        EQU     #096DA
 2036             =SafeCrunch%    EQU     #3F3C1
 2037             =SafeDecomp     EQU     #3F3C2
 2038             =SaveListMets   EQU     #3F67D
 2039             =Sel&DispNextF  EQU     #3F67E
 2040             =SelNextField   EQU     #3F67F
 2041             =SelPrevField   EQU     #3F680
 2042             =SelectAplet    EQU     #3F3C4
 2043             =SeqTableViewUI EQU     #3F6AC
 2044             =Seq_eval0      EQU     #3F5E8
 2045             =Seq_eval1      EQU     #3F5E9
 2046             =Seq_eval2      EQU     #3F5EA
 2047             =Seq_evaln      EQU     #3F5EB
 2048             =SetDA12NoCh    EQU     #3631F
 2049             =SetDA12Temp    EQU     #3639C
 2050             =SetDA12a3NCh   EQU     #3635B
 2051             =SetDA13NoCh    EQU     #36347
 2052             =SetDA1Bad      EQU     #365FC
 2053             =SetDA1IsStat   EQU     #366A4
 2054             =SetDA1NoCh     EQU     #36554
 2055             =SetDA1Temp     EQU     #361D5
 2056             =SetDA1Valid    EQU     #3617B
 2057             =SetDA23NoCh    EQU     #36333
 2058             =SetDA2NoCh     EQU     #3630B
 2059             =SetDA2Temp     EQU     #36388
 2060             =SetDA2Valid    EQU     #362DE
 2061             =SetDA2aBad     EQU     #36626
 2062             =SetDA2aEcho    EQU     #3622F
 2063             =SetDA2aNoCh    EQU     #3657E
 2064             =SetDA2aTemp    EQU     #361EE
 2065             =SetDA2aValid   EQU     #36194
 2066             =SetDA2bBad     EQU     #36650
 2067             =SetDA2bNoCh    EQU     #365A8
 2068             =SetDA2bValid   EQU     #361A8
 2069             =SetDA3Bad      EQU     #3667A
 2070             =SetDA3NoCh     EQU     #365D2
 2071             =SetDA3Temp     EQU     #3621B
 2072             =SetDA3Valid    EQU     #361C1
 2073             =SetDA3ValidF   EQU     #36482
 2074             =SetDAsBad      EQU     #3F3C5
 2075             =SetDAsNoCh     EQU     #3636F
 2076             =SetDAsTemp     EQU     #363B0
 2077             =SetEcma94      EQU     #3F2AD
 2078             =SetFAreaBad    EQU     #3F5C6
 2079             =SetFAreaOK     EQU     #3F3C6
 2080             =SetFAreasBad   EQU     #3F681
 2081             =SetFAreasOK    EQU     #3F682
 2082             =SetInAplet     EQU     #3F683
 2083             =SetNoRollDA2   EQU     #366FB
 2084             =SetRedrawFlag  EQU     #3F3C9
 2085             =SetSysFlag     EQU     #193A7
 2086             =SetUserFlag    EQU     #1939B
 2087             =Set_window     EQU     #3F684
 2088             =Shrink$        EQU     #199AA
 2089             =Slope@         EQU     #27367
 2090             =SolveNumViewUI EQU     #3F6AE
 2091             =Split1CKSUM@   EQU     #27123
 2092             =Split2CKSUM@   EQU     #27137
 2093             =SplitRow@      EQU     #271D7
 2094             =SplitTraceInit EQU     #2F8BC
 2095             =Stat2Flag@     EQU     #27772
 2096             =StatFit@       EQU     #2783A
 2097             =StatFont@      EQU     #2779A
 2098             =StatMark@      EQU     #2774A
 2099             =StatMisc[]@    EQU     #277A4
 2100             =StatModel@     EQU     #2775E
 2101             =StatPlot@      EQU     #276FA
 2102             =StatTableViewUI        EQU     #3F6AD
 2103             =StatType!      EQU     #276CD
 2104             =StatType@      EQU     #276D2
 2105             =Std/BoxLabel   EQU     #23537
 2106             =StdApEntry     EQU     #3F5EF
 2107             =StdDecompNoNL  EQU     #3F686
 2108             =StdIOProc      EQU     #3F2AE
 2109             =StdTableViewUI EQU     #3F685
 2110             =StndXYCoord?   EQU     #3F687
 2111             =StoAns@        EQU     #156DA
 2112             =StoAns@Drp     EQU     #3F741
 2113             =StoAplet       EQU     #3F3CB
 2114             =StoVar         EQU     #26F25
 2115             =StripTicks     EQU     #3F3CE
 2116             =SwapL/RMets    EQU     #3F5AD
 2117             =SymbSetViewUI  EQU     #3F6AF
 2118             =SymbViewUI     EQU     #3F688
 2119             =SysITE         EQU     #10768
 2120             =TAGGEDANY      EQU     #04869
 2121             =TBColL3x5      EQU     #3F80F
 2122             =TBColL5x7      EQU     #3F810
 2123             =TBColR3x5      EQU     #3F811
 2124             =TBColR5x7      EQU     #3F812
 2125             =TBDrawF3x5     EQU     #3F813
 2126             =TBDrawF5x7     EQU     #3F814
 2127             =TBEdSfKeys     EQU     #3F742
 2128             =TBErrorGrob    EQU     #3F743
 2129             =TBFormat       EQU     #3F744
 2130             =TBFuncDecomp   EQU     #3F745
 2131             =TBInv3x5C0     EQU     #3F747
 2132             =TBInv3x5C1     EQU     #3F748
 2133             =TBInv3x5C2     EQU     #3F749
 2134             =TBInv3x5C3     EQU     #3F74A
 2135             =TBInv5x7C0     EQU     #3F815
 2136             =TBInv5x7C1     EQU     #3F816
 2137             =TBInv5x7C2     EQU     #3F817
 2138             =TBRollD3x5     EQU     #3F818
 2139             =TBRollD5x7     EQU     #3F819
 2140             =TBRollU3x5     EQU     #3F81A
 2141             =TBRollU5x7     EQU     #3F81B
 2142             =TBStdZooms     EQU     #3F752
 2143             =TBStndSplitInfo        EQU     #18D1D
 2144             =TCol1@         EQU     #271C3
 2145             =TDDat3x5C1     EQU     #3F81C
 2146             =TDDat3x5C2     EQU     #3F81D
 2147             =TDDat3x5C3     EQU     #3F81E
 2148             =TDDat3x5C4     EQU     #3F81F
 2149             =TDDat3x5C5     EQU     #3F820
 2150             =TDDatD3x5      EQU     #3F821
 2151             =TDDatL3x5      EQU     #3F822
 2152             =TDDatR3x5      EQU     #3F823
 2153             =TDDatU3x5      EQU     #3F824
 2154             =TDDataF3x5     EQU     #3F825
 2155             =TEN            EQU     #040AD
 2156             =TFlags@        EQU     #27187
 2157             =THIRTEEN       EQU     #040CB
 2158             =THIRTY         EQU     #04175
 2159             =THIRTYEIGHT    EQU     #041C5
 2160             =THIRTYFIVE     EQU     #041A7
 2161             =THIRTYFOUR     EQU     #0419D
 2162             =THIRTYNINE     EQU     #041CF
 2163             =THIRTYONE      EQU     #0417F
 2164             =THIRTYSEVEN    EQU     #041BB
 2165             =THIRTYSIX      EQU     #041B1
 2166             =THIRTYTHREE    EQU     #04193
 2167             =THIRTYTWO      EQU     #04189
 2168             =THREE          EQU     #04067
 2169             =THREEFIVE      EQU     #0425B
 2170             =THREEFOUR      EQU     #04251
 2171             =THREE{}N       EQU     #0FAB5
 2172             =TOADISP        EQU     #1F4A8
 2173             =TOGDISP        EQU     #1F490
 2174             =TOGLINE        EQU     #3F3D0
 2175             =TOGLINE3       EQU     #3F689
 2176             =TOLErrorTrap   EQU     #35D2E
 2177             =TOLKeyUI       EQU     #35CD9
 2178             =TOLResUI&Err   EQU     #35D60
 2179             =TOLRestoreUI   EQU     #35D79
 2180             =TOLSaveUI      EQU     #35B58
 2181             =TOLSetTopicUI  EQU     #35BA3
 2182             =TOLSetViewUI   EQU     #35C0C
 2183             =TOLVar1!       EQU     #12D57
 2184             =TOLVar10!      EQU     #12D60
 2185             =TOLVar100!     EQU     #12DBA
 2186             =TOLVar100@     EQU     #12E92
 2187             =TOLVar101!     EQU     #12DBB
 2188             =TOLVar101@     EQU     #12E93
 2189             =TOLVar102!     EQU     #12DBC
 2190             =TOLVar102@     EQU     #12E94
 2191             =TOLVar103!     EQU     #12DBD
 2192             =TOLVar103@     EQU     #12E95
 2193             =TOLVar104!     EQU     #12DBE
 2194             =TOLVar104@     EQU     #12E96
 2195             =TOLVar105!     EQU     #12DBF
 2196             =TOLVar105@     EQU     #12E97
 2197             =TOLVar106!     EQU     #12DC0
 2198             =TOLVar106@     EQU     #12E98
 2199             =TOLVar107!     EQU     #12DC1
 2200             =TOLVar107@     EQU     #12E99
 2201             =TOLVar108!     EQU     #12DC2
 2202             =TOLVar108@     EQU     #12E9A
 2203             =TOLVar109!     EQU     #12DC3
 2204             =TOLVar109@     EQU     #12E9B
 2205             =TOLVar10@      EQU     #12E38
 2206             =TOLVar11!      EQU     #12D61
 2207             =TOLVar110!     EQU     #12DC4
 2208             =TOLVar110@     EQU     #12E9C
 2209             =TOLVar111!     EQU     #12DC5
 2210             =TOLVar111@     EQU     #12E9D
 2211             =TOLVar112!     EQU     #12DC6
 2212             =TOLVar112@     EQU     #12E9E
 2213             =TOLVar113!     EQU     #12DC7
 2214             =TOLVar113@     EQU     #12E9F
 2215             =TOLVar114!     EQU     #12DC8
 2216             =TOLVar114@     EQU     #12EA0
 2217             =TOLVar115!     EQU     #12DC9
 2218             =TOLVar115@     EQU     #12EA1
 2219             =TOLVar116!     EQU     #12DCA
 2220             =TOLVar116@     EQU     #12EA2
 2221             =TOLVar117!     EQU     #12DCB
 2222             =TOLVar117@     EQU     #12EA3
 2223             =TOLVar118!     EQU     #12DCC
 2224             =TOLVar118@     EQU     #12EA4
 2225             =TOLVar119!     EQU     #12DCD
 2226             =TOLVar119@     EQU     #12EA5
 2227             =TOLVar11@      EQU     #12E39
 2228             =TOLVar12!      EQU     #12D62
 2229             =TOLVar120!     EQU     #12DCE
 2230             =TOLVar120@     EQU     #12EA6
 2231             =TOLVar121!     EQU     #12DCF
 2232             =TOLVar121@     EQU     #12EA7
 2233             =TOLVar122!     EQU     #12DD0
 2234             =TOLVar122@     EQU     #12EA8
 2235             =TOLVar123!     EQU     #12DD1
 2236             =TOLVar123@     EQU     #12EA9
 2237             =TOLVar124!     EQU     #12DD2
 2238             =TOLVar124@     EQU     #12EAA
 2239             =TOLVar125!     EQU     #12DD3
 2240             =TOLVar125@     EQU     #12EAB
 2241             =TOLVar126!     EQU     #12DD4
 2242             =TOLVar126@     EQU     #12EAC
 2243             =TOLVar127!     EQU     #12DD5
 2244             =TOLVar127@     EQU     #12EAD
 2245             =TOLVar128!     EQU     #12DD6
 2246             =TOLVar128@     EQU     #12EAE
 2247             =TOLVar129!     EQU     #12DD7
 2248             =TOLVar129@     EQU     #12EAF
 2249             =TOLVar12@      EQU     #12E3A
 2250             =TOLVar13!      EQU     #12D63
 2251             =TOLVar130!     EQU     #12DD8
 2252             =TOLVar130@     EQU     #12EB0
 2253             =TOLVar131!     EQU     #12DD9
 2254             =TOLVar131@     EQU     #12EB1
 2255             =TOLVar132!     EQU     #12DDA
 2256             =TOLVar132@     EQU     #12EB2
 2257             =TOLVar133!     EQU     #12DDB
 2258             =TOLVar133@     EQU     #12EB3
 2259             =TOLVar134!     EQU     #12DDC
 2260             =TOLVar134@     EQU     #12EB4
 2261             =TOLVar135!     EQU     #12DDD
 2262             =TOLVar135@     EQU     #12EB5
 2263             =TOLVar136!     EQU     #12DDE
 2264             =TOLVar136@     EQU     #12EB6
 2265             =TOLVar137!     EQU     #12DDF
 2266             =TOLVar137@     EQU     #12EB7
 2267             =TOLVar138!     EQU     #12DE0
 2268             =TOLVar138@     EQU     #12EB8
 2269             =TOLVar139!     EQU     #12DE1
 2270             =TOLVar139@     EQU     #12EB9
 2271             =TOLVar13@      EQU     #12E3B
 2272             =TOLVar14!      EQU     #12D64
 2273             =TOLVar140!     EQU     #12DE2
 2274             =TOLVar140@     EQU     #12EBA
 2275             =TOLVar141!     EQU     #12DE3
 2276             =TOLVar141@     EQU     #12EBB
 2277             =TOLVar142!     EQU     #12DE4
 2278             =TOLVar142@     EQU     #12EBC
 2279             =TOLVar143!     EQU     #12DE5
 2280             =TOLVar143@     EQU     #12EBD
 2281             =TOLVar144!     EQU     #12DE6
 2282             =TOLVar144@     EQU     #12EBE
 2283             =TOLVar145!     EQU     #12DE7
 2284             =TOLVar145@     EQU     #12EBF
 2285             =TOLVar146!     EQU     #12DE8
 2286             =TOLVar146@     EQU     #12EC0
 2287             =TOLVar147!     EQU     #12DE9
 2288             =TOLVar147@     EQU     #12EC1
 2289             =TOLVar148!     EQU     #12DEA
 2290             =TOLVar148@     EQU     #12EC2
 2291             =TOLVar149!     EQU     #12DEB
 2292             =TOLVar149@     EQU     #12EC3
 2293             =TOLVar14@      EQU     #12E3C
 2294             =TOLVar15!      EQU     #12D65
 2295             =TOLVar150!     EQU     #12DEC
 2296             =TOLVar150@     EQU     #12EC4
 2297             =TOLVar151!     EQU     #12DED
 2298             =TOLVar151@     EQU     #12EC5
 2299             =TOLVar152!     EQU     #12DEE
 2300             =TOLVar152@     EQU     #12EC6
 2301             =TOLVar153!     EQU     #12DEF
 2302             =TOLVar153@     EQU     #12EC7
 2303             =TOLVar154!     EQU     #12DF0
 2304             =TOLVar154@     EQU     #12EC8
 2305             =TOLVar155!     EQU     #12DF1
 2306             =TOLVar155@     EQU     #12EC9
 2307             =TOLVar156!     EQU     #12DF2
 2308             =TOLVar156@     EQU     #12ECA
 2309             =TOLVar157!     EQU     #12DF3
 2310             =TOLVar157@     EQU     #12ECB
 2311             =TOLVar158!     EQU     #12DF4
 2312             =TOLVar158@     EQU     #12ECC
 2313             =TOLVar159!     EQU     #12DF5
 2314             =TOLVar159@     EQU     #12ECD
 2315             =TOLVar15@      EQU     #12E3D
 2316             =TOLVar16!      EQU     #12D66
 2317             =TOLVar160!     EQU     #12DF6
 2318             =TOLVar160@     EQU     #12ECE
 2319             =TOLVar161!     EQU     #12DF7
 2320             =TOLVar161@     EQU     #12ECF
 2321             =TOLVar162!     EQU     #12DF8
 2322             =TOLVar162@     EQU     #12ED0
 2323             =TOLVar163!     EQU     #12DF9
 2324             =TOLVar163@     EQU     #12ED1
 2325             =TOLVar164!     EQU     #12DFA
 2326             =TOLVar164@     EQU     #12ED2
 2327             =TOLVar165!     EQU     #12DFB
 2328             =TOLVar165@     EQU     #12ED3
 2329             =TOLVar166!     EQU     #12DFC
 2330             =TOLVar166@     EQU     #12ED4
 2331             =TOLVar167!     EQU     #12DFD
 2332             =TOLVar167@     EQU     #12ED5
 2333             =TOLVar168!     EQU     #12DFE
 2334             =TOLVar168@     EQU     #12ED6
 2335             =TOLVar169!     EQU     #12DFF
 2336             =TOLVar169@     EQU     #12ED7
 2337             =TOLVar16@      EQU     #12E3E
 2338             =TOLVar17!      EQU     #12D67
 2339             =TOLVar170!     EQU     #12E00
 2340             =TOLVar170@     EQU     #12ED8
 2341             =TOLVar171!     EQU     #12E01
 2342             =TOLVar171@     EQU     #12ED9
 2343             =TOLVar172!     EQU     #12E02
 2344             =TOLVar172@     EQU     #12EDA
 2345             =TOLVar173!     EQU     #12E03
 2346             =TOLVar173@     EQU     #12EDB
 2347             =TOLVar174!     EQU     #12E04
 2348             =TOLVar174@     EQU     #12EDC
 2349             =TOLVar175!     EQU     #12E05
 2350             =TOLVar175@     EQU     #12EDD
 2351             =TOLVar176!     EQU     #12E06
 2352             =TOLVar176@     EQU     #12EDE
 2353             =TOLVar177!     EQU     #12E07
 2354             =TOLVar177@     EQU     #12EDF
 2355             =TOLVar178!     EQU     #12E08
 2356             =TOLVar178@     EQU     #12EE0
 2357             =TOLVar179!     EQU     #12E09
 2358             =TOLVar179@     EQU     #12EE1
 2359             =TOLVar17@      EQU     #12E3F
 2360             =TOLVar18!      EQU     #12D68
 2361             =TOLVar180!     EQU     #12E0A
 2362             =TOLVar180@     EQU     #12EE2
 2363             =TOLVar181!     EQU     #12E0B
 2364             =TOLVar181@     EQU     #12EE3
 2365             =TOLVar182!     EQU     #12E0C
 2366             =TOLVar182@     EQU     #12EE4
 2367             =TOLVar183!     EQU     #12E0D
 2368             =TOLVar183@     EQU     #12EE5
 2369             =TOLVar184!     EQU     #12E0E
 2370             =TOLVar184@     EQU     #12EE6
 2371             =TOLVar185!     EQU     #12E0F
 2372             =TOLVar185@     EQU     #12EE7
 2373             =TOLVar186!     EQU     #12E10
 2374             =TOLVar186@     EQU     #12EE8
 2375             =TOLVar187!     EQU     #12E11
 2376             =TOLVar187@     EQU     #12EE9
 2377             =TOLVar188!     EQU     #12E12
 2378             =TOLVar188@     EQU     #12EEA
 2379             =TOLVar189!     EQU     #12E13
 2380             =TOLVar189@     EQU     #12EEB
 2381             =TOLVar18@      EQU     #12E40
 2382             =TOLVar19!      EQU     #12D69
 2383             =TOLVar190!     EQU     #12E14
 2384             =TOLVar190@     EQU     #12EEC
 2385             =TOLVar191!     EQU     #12E15
 2386             =TOLVar191@     EQU     #12EED
 2387             =TOLVar192!     EQU     #12E16
 2388             =TOLVar192@     EQU     #12EEE
 2389             =TOLVar193!     EQU     #12E17
 2390             =TOLVar193@     EQU     #12EEF
 2391             =TOLVar194!     EQU     #12E18
 2392             =TOLVar194@     EQU     #12EF0
 2393             =TOLVar195!     EQU     #12E19
 2394             =TOLVar195@     EQU     #12EF1
 2395             =TOLVar196!     EQU     #12E1A
 2396             =TOLVar196@     EQU     #12EF2
 2397             =TOLVar197!     EQU     #12E1B
 2398             =TOLVar197@     EQU     #12EF3
 2399             =TOLVar198!     EQU     #12E1C
 2400             =TOLVar198@     EQU     #12EF4
 2401             =TOLVar199!     EQU     #12E1D
 2402             =TOLVar199@     EQU     #12EF5
 2403             =TOLVar19@      EQU     #12E41
 2404             =TOLVar1@       EQU     #12E2F
 2405             =TOLVar2!       EQU     #12D58
 2406             =TOLVar20!      EQU     #12D6A
 2407             =TOLVar200!     EQU     #12E1E
 2408             =TOLVar200@     EQU     #12EF6
 2409             =TOLVar201!     EQU     #12E1F
 2410             =TOLVar201@     EQU     #12EF7
 2411             =TOLVar202!     EQU     #12E20
 2412             =TOLVar202@     EQU     #12EF8
 2413             =TOLVar203!     EQU     #12E21
 2414             =TOLVar203@     EQU     #12EF9
 2415             =TOLVar204!     EQU     #12E22
 2416             =TOLVar204@     EQU     #12EFA
 2417             =TOLVar205!     EQU     #12E23
 2418             =TOLVar205@     EQU     #12EFB
 2419             =TOLVar206!     EQU     #12E24
 2420             =TOLVar206@     EQU     #12EFC
 2421             =TOLVar207!     EQU     #12E25
 2422             =TOLVar207@     EQU     #12EFD
 2423             =TOLVar208!     EQU     #12E26
 2424             =TOLVar208@     EQU     #12EFE
 2425             =TOLVar209!     EQU     #12E27
 2426             =TOLVar209@     EQU     #12EFF
 2427             =TOLVar20@      EQU     #12E42
 2428             =TOLVar21!      EQU     #12D6B
 2429             =TOLVar210!     EQU     #12E28
 2430             =TOLVar210@     EQU     #12F00
 2431             =TOLVar211!     EQU     #12E29
 2432             =TOLVar211@     EQU     #12F01
 2433             =TOLVar212!     EQU     #12E2A
 2434             =TOLVar212@     EQU     #12F02
 2435             =TOLVar213!     EQU     #12E2B
 2436             =TOLVar213@     EQU     #12F03
 2437             =TOLVar214!     EQU     #12E2C
 2438             =TOLVar214@     EQU     #12F04
 2439             =TOLVar215!     EQU     #12E2D
 2440             =TOLVar215@     EQU     #12F05
 2441             =TOLVar216!     EQU     #12E2E
 2442             =TOLVar216@     EQU     #12F06
 2443             =TOLVar21@      EQU     #12E43
 2444             =TOLVar22!      EQU     #12D6C
 2445             =TOLVar22@      EQU     #12E44
 2446             =TOLVar23!      EQU     #12D6D
 2447             =TOLVar23@      EQU     #12E45
 2448             =TOLVar24!      EQU     #12D6E
 2449             =TOLVar24@      EQU     #12E46
 2450             =TOLVar25!      EQU     #12D6F
 2451             =TOLVar25@      EQU     #12E47
 2452             =TOLVar26!      EQU     #12D70
 2453             =TOLVar26@      EQU     #12E48
 2454             =TOLVar27!      EQU     #12D71
 2455             =TOLVar27@      EQU     #12E49
 2456             =TOLVar28!      EQU     #12D72
 2457             =TOLVar28@      EQU     #12E4A
 2458             =TOLVar29!      EQU     #12D73
 2459             =TOLVar29@      EQU     #12E4B
 2460             =TOLVar2@       EQU     #12E30
 2461             =TOLVar3!       EQU     #12D59
 2462             =TOLVar30!      EQU     #12D74
 2463             =TOLVar30@      EQU     #12E4C
 2464             =TOLVar31!      EQU     #12D75
 2465             =TOLVar31@      EQU     #12E4D
 2466             =TOLVar32!      EQU     #12D76
 2467             =TOLVar32@      EQU     #12E4E
 2468             =TOLVar33!      EQU     #12D77
 2469             =TOLVar33@      EQU     #12E4F
 2470             =TOLVar34!      EQU     #12D78
 2471             =TOLVar34@      EQU     #12E50
 2472             =TOLVar35!      EQU     #12D79
 2473             =TOLVar35@      EQU     #12E51
 2474             =TOLVar36!      EQU     #12D7A
 2475             =TOLVar36@      EQU     #12E52
 2476             =TOLVar37!      EQU     #12D7B
 2477             =TOLVar37@      EQU     #12E53
 2478             =TOLVar38!      EQU     #12D7C
 2479             =TOLVar38@      EQU     #12E54
 2480             =TOLVar39!      EQU     #12D7D
 2481             =TOLVar39@      EQU     #12E55
 2482             =TOLVar3@       EQU     #12E31
 2483             =TOLVar4!       EQU     #12D5A
 2484             =TOLVar40!      EQU     #12D7E
 2485             =TOLVar40@      EQU     #12E56
 2486             =TOLVar41!      EQU     #12D7F
 2487             =TOLVar41@      EQU     #12E57
 2488             =TOLVar42!      EQU     #12D80
 2489             =TOLVar42@      EQU     #12E58
 2490             =TOLVar43!      EQU     #12D81
 2491             =TOLVar43@      EQU     #12E59
 2492             =TOLVar44!      EQU     #12D82
 2493             =TOLVar44@      EQU     #12E5A
 2494             =TOLVar45!      EQU     #12D83
 2495             =TOLVar45@      EQU     #12E5B
 2496             =TOLVar46!      EQU     #12D84
 2497             =TOLVar46@      EQU     #12E5C
 2498             =TOLVar47!      EQU     #12D85
 2499             =TOLVar47@      EQU     #12E5D
 2500             =TOLVar48!      EQU     #12D86
 2501             =TOLVar48@      EQU     #12E5E
 2502             =TOLVar49!      EQU     #12D87
 2503             =TOLVar49@      EQU     #12E5F
 2504             =TOLVar4@       EQU     #12E32
 2505             =TOLVar5!       EQU     #12D5B
 2506             =TOLVar50!      EQU     #12D88
 2507             =TOLVar50@      EQU     #12E60
 2508             =TOLVar51!      EQU     #12D89
 2509             =TOLVar51@      EQU     #12E61
 2510             =TOLVar52!      EQU     #12D8A
 2511             =TOLVar52@      EQU     #12E62
 2512             =TOLVar53!      EQU     #12D8B
 2513             =TOLVar53@      EQU     #12E63
 2514             =TOLVar54!      EQU     #12D8C
 2515             =TOLVar54@      EQU     #12E64
 2516             =TOLVar55!      EQU     #12D8D
 2517             =TOLVar55@      EQU     #12E65
 2518             =TOLVar56!      EQU     #12D8E
 2519             =TOLVar56@      EQU     #12E66
 2520             =TOLVar57!      EQU     #12D8F
 2521             =TOLVar57@      EQU     #12E67
 2522             =TOLVar58!      EQU     #12D90
 2523             =TOLVar58@      EQU     #12E68
 2524             =TOLVar59!      EQU     #12D91
 2525             =TOLVar59@      EQU     #12E69
 2526             =TOLVar5@       EQU     #12E33
 2527             =TOLVar6!       EQU     #12D5C
 2528             =TOLVar60!      EQU     #12D92
 2529             =TOLVar60@      EQU     #12E6A
 2530             =TOLVar61!      EQU     #12D93
 2531             =TOLVar61@      EQU     #12E6B
 2532             =TOLVar62!      EQU     #12D94
 2533             =TOLVar62@      EQU     #12E6C
 2534             =TOLVar63!      EQU     #12D95
 2535             =TOLVar63@      EQU     #12E6D
 2536             =TOLVar64!      EQU     #12D96
 2537             =TOLVar64@      EQU     #12E6E
 2538             =TOLVar65!      EQU     #12D97
 2539             =TOLVar65@      EQU     #12E6F
 2540             =TOLVar66!      EQU     #12D98
 2541             =TOLVar66@      EQU     #12E70
 2542             =TOLVar67!      EQU     #12D99
 2543             =TOLVar67@      EQU     #12E71
 2544             =TOLVar68!      EQU     #12D9A
 2545             =TOLVar68@      EQU     #12E72
 2546             =TOLVar69!      EQU     #12D9B
 2547             =TOLVar69@      EQU     #12E73
 2548             =TOLVar6@       EQU     #12E34
 2549             =TOLVar7!       EQU     #12D5D
 2550             =TOLVar70!      EQU     #12D9C
 2551             =TOLVar70@      EQU     #12E74
 2552             =TOLVar71!      EQU     #12D9D
 2553             =TOLVar71@      EQU     #12E75
 2554             =TOLVar72!      EQU     #12D9E
 2555             =TOLVar72@      EQU     #12E76
 2556             =TOLVar73!      EQU     #12D9F
 2557             =TOLVar73@      EQU     #12E77
 2558             =TOLVar74!      EQU     #12DA0
 2559             =TOLVar74@      EQU     #12E78
 2560             =TOLVar75!      EQU     #12DA1
 2561             =TOLVar75@      EQU     #12E79
 2562             =TOLVar76!      EQU     #12DA2
 2563             =TOLVar76@      EQU     #12E7A
 2564             =TOLVar77!      EQU     #12DA3
 2565             =TOLVar77@      EQU     #12E7B
 2566             =TOLVar78!      EQU     #12DA4
 2567             =TOLVar78@      EQU     #12E7C
 2568             =TOLVar79!      EQU     #12DA5
 2569             =TOLVar79@      EQU     #12E7D
 2570             =TOLVar7@       EQU     #12E35
 2571             =TOLVar8!       EQU     #12D5E
 2572             =TOLVar80!      EQU     #12DA6
 2573             =TOLVar80@      EQU     #12E7E
 2574             =TOLVar81!      EQU     #12DA7
 2575             =TOLVar81@      EQU     #12E7F
 2576             =TOLVar82!      EQU     #12DA8
 2577             =TOLVar82@      EQU     #12E80
 2578             =TOLVar83!      EQU     #12DA9
 2579             =TOLVar83@      EQU     #12E81
 2580             =TOLVar84!      EQU     #12DAA
 2581             =TOLVar84@      EQU     #12E82
 2582             =TOLVar85!      EQU     #12DAB
 2583             =TOLVar85@      EQU     #12E83
 2584             =TOLVar86!      EQU     #12DAC
 2585             =TOLVar86@      EQU     #12E84
 2586             =TOLVar87!      EQU     #12DAD
 2587             =TOLVar87@      EQU     #12E85
 2588             =TOLVar88!      EQU     #12DAE
 2589             =TOLVar88@      EQU     #12E86
 2590             =TOLVar89!      EQU     #12DAF
 2591             =TOLVar89@      EQU     #12E87
 2592             =TOLVar8@       EQU     #12E36
 2593             =TOLVar9!       EQU     #12D5F
 2594             =TOLVar90!      EQU     #12DB0
 2595             =TOLVar90@      EQU     #12E88
 2596             =TOLVar91!      EQU     #12DB1
 2597             =TOLVar91@      EQU     #12E89
 2598             =TOLVar92!      EQU     #12DB2
 2599             =TOLVar92@      EQU     #12E8A
 2600             =TOLVar93!      EQU     #12DB3
 2601             =TOLVar93@      EQU     #12E8B
 2602             =TOLVar94!      EQU     #12DB4
 2603             =TOLVar94@      EQU     #12E8C
 2604             =TOLVar95!      EQU     #12DB5
 2605             =TOLVar95@      EQU     #12E8D
 2606             =TOLVar96!      EQU     #12DB6
 2607             =TOLVar96@      EQU     #12E8E
 2608             =TOLVar97!      EQU     #12DB7
 2609             =TOLVar97@      EQU     #12E8F
 2610             =TOLVar98!      EQU     #12DB8
 2611             =TOLVar98@      EQU     #12E90
 2612             =TOLVar99!      EQU     #12DB9
 2613             =TOLVar99@      EQU     #12E91
 2614             =TOLVar9@       EQU     #12E37
 2615             =TOLVarN!       EQU     #1281D
 2616             =TOLVarN@       EQU     #12840
 2617             =TOLVarSet!     EQU     #1292B
 2618             =TOSRRP         EQU     #07EE2
 2619             =TOTEMPOB       EQU     #06E2F
 2620             =TOTEMPSWAP     EQU     #0F543
 2621             =TRCXY          EQU     #1C45E
 2622             =TRUE           EQU     #03A81
 2623             =TRUE'          EQU     #10209
 2624             =TRUEFALSE      EQU     #0FDEF
 2625             =TStart@        EQU     #2714B
 2626             =TStep@         EQU     #2715F
 2627             =TURNMENUOFF    EQU     #3F3D5
 2628             =TURNMENUON     EQU     #3F3D6
 2629             =TWELVE         EQU     #040C1
 2630             =TWENTY         EQU     #04111
 2631             =TWENTYEIGHT    EQU     #04161
 2632             =TWENTYFIVE     EQU     #04143
 2633             =TWENTYFOUR     EQU     #04139
 2634             =TWENTYNINE     EQU     #0416B
 2635             =TWENTYONE      EQU     #0411B
 2636             =TWENTYSEVEN    EQU     #04157
 2637             =TWENTYSIX      EQU     #0414D
 2638             =TWENTYTHREE    EQU     #0412F
 2639             =TWENTYTWO      EQU     #04125
 2640             =TWO            EQU     #0405D
 2641             =TWODROPNULL$   EQU     #05569
 2642             =TWO{}N         EQU     #0FAA1
 2643             =TYPE           EQU     #03C64
 2644             =TYPEARRY?      EQU     #0DC8F
 2645             =TYPEBINT?      EQU     #0DC44
 2646             =TYPECARRY?     EQU     #0DE01
 2647             =TYPECHAR?      EQU     #0DB9F
 2648             =TYPECMP        EQU     #03FE5
 2649             =TYPECMP?       EQU     #0DC80
 2650             =TYPECOL        EQU     #04003
 2651             =TYPECOL?       EQU     #0DCCB
 2652             =TYPECSTR?      EQU     #0DC62
 2653             =TYPEEREL       EQU     #0402B
 2654             =TYPEEXT        EQU     #04035
 2655             =TYPEEXT?       EQU     #0DD07
 2656             =TYPEGROB?      EQU     #0DCDA
 2657             =TYPEHSTR?      EQU     #0DC53
 2658             =TYPEIDNT       EQU     #03FF9
 2659             =TYPEIDNT?      EQU     #0DBAE
 2660             =TYPELAM        EQU     #04021
 2661             =TYPELAM?       EQU     #0DC35
 2662             =TYPELIST       EQU     #03FEF
 2663             =TYPELIST?      EQU     #0DCE9
 2664             =TYPERARRY?     EQU     #0DDE6
 2665             =TYPEREAL       EQU     #03FDB
 2666             =TYPEREAL?      EQU     #0DC71
 2667             =TYPEROMP?      EQU     #0DC9E
 2668             =TYPERRP        EQU     #04017
 2669             =TYPERRP?       EQU     #0DCAD
 2670             =TYPESYMB       EQU     #0400D
 2671             =TYPESYMB?      EQU     #0DCBC
 2672             =TZoom@         EQU     #27173
 2673             =TablSetViewUI  EQU     #3F68A
 2674             =TakeOver       EQU     #24448
 2675             =Tcol@          EQU     #271AF
 2676             =TempMenuBuff   EQU     #3F68B
 2677             =TestSysFlag    EQU     #193FA
 2678             =TestUserFlag   EQU     #193EE
 2679             =TopOuterLoop   EQU     #35A6F
 2680             =TopicVar1!     EQU     #12CA1
 2681             =TopicVar10!    EQU     #12CAA
 2682             =TopicVar10@    EQU     #12D05
 2683             =TopicVar11!    EQU     #12CAB
 2684             =TopicVar11@    EQU     #12D06
 2685             =TopicVar12!    EQU     #12CAC
 2686             =TopicVar12@    EQU     #12D07
 2687             =TopicVar13!    EQU     #12CAD
 2688             =TopicVar13@    EQU     #12D08
 2689             =TopicVar14!    EQU     #12CAE
 2690             =TopicVar14@    EQU     #12D09
 2691             =TopicVar15!    EQU     #12CAF
 2692             =TopicVar15@    EQU     #12D0A
 2693             =TopicVar16!    EQU     #12CB0
 2694             =TopicVar16@    EQU     #12D0B
 2695             =TopicVar17!    EQU     #12CB1
 2696             =TopicVar17@    EQU     #12D0C
 2697             =TopicVar18!    EQU     #12CB2
 2698             =TopicVar18@    EQU     #12D0D
 2699             =TopicVar19!    EQU     #12CB3
 2700             =TopicVar19@    EQU     #12D0E
 2701             =TopicVar1@     EQU     #12CFC
 2702             =TopicVar2!     EQU     #12CA2
 2703             =TopicVar20!    EQU     #12CB4
 2704             =TopicVar20@    EQU     #12D0F
 2705             =TopicVar21!    EQU     #12CB5
 2706             =TopicVar21@    EQU     #12D10
 2707             =TopicVar22!    EQU     #12CB6
 2708             =TopicVar22@    EQU     #12D11
 2709             =TopicVar23!    EQU     #12CB7
 2710             =TopicVar23@    EQU     #12D12
 2711             =TopicVar24!    EQU     #12CB8
 2712             =TopicVar24@    EQU     #12D13
 2713             =TopicVar25!    EQU     #12CB9
 2714             =TopicVar25@    EQU     #12D14
 2715             =TopicVar26!    EQU     #12CBA
 2716             =TopicVar26@    EQU     #12D15
 2717             =TopicVar27!    EQU     #12CBB
 2718             =TopicVar27@    EQU     #12D16
 2719             =TopicVar28!    EQU     #12CBC
 2720             =TopicVar28@    EQU     #12D17
 2721             =TopicVar29!    EQU     #12CBD
 2722             =TopicVar29@    EQU     #12D18
 2723             =TopicVar2@     EQU     #12CFD
 2724             =TopicVar3!     EQU     #12CA3
 2725             =TopicVar30!    EQU     #12CBE
 2726             =TopicVar30@    EQU     #12D19
 2727             =TopicVar31!    EQU     #12CBF
 2728             =TopicVar31@    EQU     #12D1A
 2729             =TopicVar32!    EQU     #12CC0
 2730             =TopicVar32@    EQU     #12D1B
 2731             =TopicVar33!    EQU     #12CC1
 2732             =TopicVar33@    EQU     #12D1C
 2733             =TopicVar34!    EQU     #12CC2
 2734             =TopicVar34@    EQU     #12D1D
 2735             =TopicVar35!    EQU     #12CC3
 2736             =TopicVar35@    EQU     #12D1E
 2737             =TopicVar36!    EQU     #12CC4
 2738             =TopicVar36@    EQU     #12D1F
 2739             =TopicVar37!    EQU     #12CC5
 2740             =TopicVar37@    EQU     #12D20
 2741             =TopicVar38!    EQU     #12CC6
 2742             =TopicVar38@    EQU     #12D21
 2743             =TopicVar39!    EQU     #12CC7
 2744             =TopicVar39@    EQU     #12D22
 2745             =TopicVar3@     EQU     #12CFE
 2746             =TopicVar4!     EQU     #12CA4
 2747             =TopicVar40!    EQU     #12CC8
 2748             =TopicVar40@    EQU     #12D23
 2749             =TopicVar41!    EQU     #12CC9
 2750             =TopicVar41@    EQU     #12D24
 2751             =TopicVar42!    EQU     #12CCA
 2752             =TopicVar42@    EQU     #12D25
 2753             =TopicVar43!    EQU     #12CCB
 2754             =TopicVar43@    EQU     #12D26
 2755             =TopicVar44!    EQU     #12CCC
 2756             =TopicVar44@    EQU     #12D27
 2757             =TopicVar45!    EQU     #12CCD
 2758             =TopicVar45@    EQU     #12D28
 2759             =TopicVar46!    EQU     #12CCE
 2760             =TopicVar46@    EQU     #12D29
 2761             =TopicVar47!    EQU     #12CCF
 2762             =TopicVar47@    EQU     #12D2A
 2763             =TopicVar48!    EQU     #12CD0
 2764             =TopicVar48@    EQU     #12D2B
 2765             =TopicVar49!    EQU     #12CD1
 2766             =TopicVar49@    EQU     #12D2C
 2767             =TopicVar4@     EQU     #12CFF
 2768             =TopicVar5!     EQU     #12CA5
 2769             =TopicVar50!    EQU     #12CD2
 2770             =TopicVar50@    EQU     #12D2D
 2771             =TopicVar51!    EQU     #12CD3
 2772             =TopicVar51@    EQU     #12D2E
 2773             =TopicVar52!    EQU     #12CD4
 2774             =TopicVar52@    EQU     #12D2F
 2775             =TopicVar53!    EQU     #12CD5
 2776             =TopicVar53@    EQU     #12D30
 2777             =TopicVar54!    EQU     #12CD6
 2778             =TopicVar54@    EQU     #12D31
 2779             =TopicVar55!    EQU     #12CD7
 2780             =TopicVar55@    EQU     #12D32
 2781             =TopicVar56!    EQU     #12CD8
 2782             =TopicVar56@    EQU     #12D33
 2783             =TopicVar57!    EQU     #12CD9
 2784             =TopicVar57@    EQU     #12D34
 2785             =TopicVar58!    EQU     #12CDA
 2786             =TopicVar58@    EQU     #12D35
 2787             =TopicVar59!    EQU     #12CDB
 2788             =TopicVar59@    EQU     #12D36
 2789             =TopicVar5@     EQU     #12D00
 2790             =TopicVar6!     EQU     #12CA6
 2791             =TopicVar60!    EQU     #12CDC
 2792             =TopicVar60@    EQU     #12D37
 2793             =TopicVar61!    EQU     #12CDD
 2794             =TopicVar61@    EQU     #12D38
 2795             =TopicVar62!    EQU     #12CDE
 2796             =TopicVar62@    EQU     #12D39
 2797             =TopicVar63!    EQU     #12CDF
 2798             =TopicVar63@    EQU     #12D3A
 2799             =TopicVar64!    EQU     #12CE0
 2800             =TopicVar64@    EQU     #12D3B
 2801             =TopicVar65!    EQU     #12CE1
 2802             =TopicVar65@    EQU     #12D3C
 2803             =TopicVar66!    EQU     #12CE2
 2804             =TopicVar66@    EQU     #12D3D
 2805             =TopicVar67!    EQU     #12CE3
 2806             =TopicVar67@    EQU     #12D3E
 2807             =TopicVar68!    EQU     #12CE4
 2808             =TopicVar68@    EQU     #12D3F
 2809             =TopicVar69!    EQU     #12CE5
 2810             =TopicVar69@    EQU     #12D40
 2811             =TopicVar6@     EQU     #12D01
 2812             =TopicVar7!     EQU     #12CA7
 2813             =TopicVar70!    EQU     #12CE6
 2814             =TopicVar70@    EQU     #12D41
 2815             =TopicVar71!    EQU     #12CE7
 2816             =TopicVar71@    EQU     #12D42
 2817             =TopicVar72!    EQU     #12CE8
 2818             =TopicVar72@    EQU     #12D43
 2819             =TopicVar73!    EQU     #12CE9
 2820             =TopicVar73@    EQU     #12D44
 2821             =TopicVar74!    EQU     #12CEA
 2822             =TopicVar74@    EQU     #12D45
 2823             =TopicVar75!    EQU     #12CEB
 2824             =TopicVar75@    EQU     #12D46
 2825             =TopicVar76!    EQU     #12CEC
 2826             =TopicVar76@    EQU     #12D47
 2827             =TopicVar77!    EQU     #12CED
 2828             =TopicVar77@    EQU     #12D48
 2829             =TopicVar78!    EQU     #12CEE
 2830             =TopicVar78@    EQU     #12D49
 2831             =TopicVar79!    EQU     #12CEF
 2832             =TopicVar79@    EQU     #12D4A
 2833             =TopicVar7@     EQU     #12D02
 2834             =TopicVar8!     EQU     #12CA8
 2835             =TopicVar80!    EQU     #12CF0
 2836             =TopicVar80@    EQU     #12D4B
 2837             =TopicVar81!    EQU     #12CF1
 2838             =TopicVar81@    EQU     #12D4C
 2839             =TopicVar82!    EQU     #12CF2
 2840             =TopicVar82@    EQU     #12D4D
 2841             =TopicVar83!    EQU     #12CF3
 2842             =TopicVar83@    EQU     #12D4E
 2843             =TopicVar84!    EQU     #12CF4
 2844             =TopicVar84@    EQU     #12D4F
 2845             =TopicVar85!    EQU     #12CF5
 2846             =TopicVar85@    EQU     #12D50
 2847             =TopicVar86!    EQU     #12CF6
 2848             =TopicVar86@    EQU     #12D51
 2849             =TopicVar87!    EQU     #12CF7
 2850             =TopicVar87@    EQU     #12D52
 2851             =TopicVar88!    EQU     #12CF8
 2852             =TopicVar88@    EQU     #12D53
 2853             =TopicVar89!    EQU     #12CF9
 2854             =TopicVar89@    EQU     #12D54
 2855             =TopicVar8@     EQU     #12D03
 2856             =TopicVar9!     EQU     #12CA9
 2857             =TopicVar90!    EQU     #12CFA
 2858             =TopicVar90@    EQU     #12D55
 2859             =TopicVar91!    EQU     #12CFB
 2860             =TopicVar91@    EQU     #12D56
 2861             =TopicVar9@     EQU     #12D04
 2862             =TopicVarN!     EQU     #3873F
 2863             =TopicVarN@     EQU     #3871B
 2864             =TraceY         EQU     #2FF8E
 2865             =Trow@          EQU     #2719B
 2866             =TrueFalse      EQU     #0FDEF
 2867             =TrueTrue       EQU     #0C476
 2868             =TurnOff        EQU     #04A53
 2869             =UARTBUFLEN     EQU     #3F2AF
 2870             =UNCOERCE       EQU     #13319
 2871             =UNCOERCE%%     EQU     #10411
 2872             =UNITSYM        EQU     #0496D
 2873             =UNROLL         EQU     #0339E
 2874             =UNROT          EQU     #0CD84
 2875             =UNROTDROP      EQU     #0E3C6
 2876             =UNROTDUP       EQU     #0F5CF
 2877             =UNROTOVER      EQU     #0F96E
 2878             =UNTIL          EQU     #079A1
 2879             =UnLockAlpha    EQU     #25037
 2880             =UnpackGrob     EQU     #3F8D2
 2881             =Update_tTYPE   EQU     #3F3E9
 2882             =UserITE        EQU     #10754
 2883             =UserSto        EQU     #3F3EA
 2884             =VERYSLOW       EQU     #251A1
 2885             =VERYVERYSLOW   EQU     #251B1
 2886             =VLMAlarmMsg    EQU     #11CAD
 2887             =VLMUserKeys    EQU     #11CA3
 2888             =VLMcmdlmsg     EQU     #11CC1
 2889             =VLMhistmsg     EQU     #11C99
 2890             =VLMlastargs    EQU     #11CB7
 2891             =VLMmsg         EQU     #11C7B
 2892             =VLMpurgemsg    EQU     #11C71
 2893             =VLMstkmsg      EQU     #11C85
 2894             =VLMundomsg     EQU     #11C8F
 2895             =VTick@         EQU     #27047
 2896             =VZoom@         EQU     #2706F
 2897             =WHILE          EQU     #079C7
 2898             =WINDOWBOT?     EQU     #3F68C
 2899             =WINDOWCORNER   EQU     #1FC49
 2900             =WINDOWDOWN     EQU     #1F57B
 2901             =WINDOWLEFT     EQU     #1F83F
 2902             =WINDOWLEFT?    EQU     #3F68D
 2903             =WINDOWRIGHT    EQU     #1FA0C
 2904             =WINDOWRIGHT?   EQU     #3F68E
 2905             =WINDOWTOP?     EQU     #3F68F
 2906             =WINDOWUP       EQU     #1F523
 2907             =WINDOWXY       EQU     #1FB06
 2908             =WaitForKey     EQU     #262DB
 2909             =WaitTbz0       EQU     #1708D
 2910             =WidthSmF       EQU     #3F690
 2911             =X@             EQU     #09C41
 2912             =XEQSETLIB      EQU     #3F1CF
 2913             =XFERFAIL       EQU     #11E51
 2914             =XHI            EQU     #04567
 2915             =XHI-1          EQU     #0455D
 2916             =XOR            EQU     #03ADA
 2917             =XPURGEp        EQU     #09D31
 2918             =XPURGEp0       EQU     #09D6D
 2919             =XRCLp          EQU     #09BBF
 2920             =XRCLp0         EQU     #09C19
 2921             =XSTOp          EQU     #099D6
 2922             =XSTOp0         EQU     #09BA1
 2923             =XYGROBDISP     EQU     #1EBCA
 2924             =XYZ>ZCOLA      EQU     #0FC0E
 2925             =XYZ>ZTRUE      EQU     #0F791
 2926             =XYZW>YWZX      EQU     #104A7
 2927             =Xmax!          EQU     #26FA2
 2928             =Xmax2@         EQU     #26FF7
 2929             =Xmax@          EQU     #26FA7
 2930             =Xmin!          EQU     #26F8E
 2931             =Xmin2@         EQU     #26FE3
 2932             =Xmin@          EQU     #26F93
 2933             =Xorbitmap      EQU     #38C58
 2934             =YHI            EQU     #042C9
 2935             =Ymax2@         EQU     #2701F
 2936             =Ymax@          EQU     #26FCF
 2937             =Ymin2@         EQU     #2700B
 2938             =Ymin@          EQU     #26FBB
 2939             =ZERO           EQU     #04049
 2940             =ZEROFALSE      EQU     #0FE17
 2941             =ZEROISTOPSTO   EQU     #1088A
 2942             =ZEROOVER       EQU     #0F95A
 2943             =ZEROSWAP       EQU     #0F714
 2944             =ZEROZERO       EQU     #0E996
 2945             =ZERO_DO        EQU     #07B9C
 2946             =ZoomAutoUI     EQU     #3F62B
 2947             =alg=           EQU     #3A8DD
 2948             =apletPTR!      EQU     #126F6
 2949             =apletPTR@      EQU     #12706
 2950             =apndit         EQU     #3F148
 2951             =argswap        EQU     #3F149
 2952             =argswap&&      EQU     #3F2B0
 2953             =argswapnext    EQU     #3F2B1
 2954             =backup         EQU     #0467F
 2955             =blackbox       EQU     #3F826
 2956             =case           EQU     #0D55C
 2957             =case2DROP      EQU     #0D539
 2958             =case2drop      EQU     #0D4E8
 2959             =case2drpfls    EQU     #0FE7B
 2960             =caseDEADKEY    EQU     #10466
 2961             =caseDROP       EQU     #0D514
 2962             =caseDoBadKey   EQU     #10466
 2963             =caseDrpBadKy   EQU     #1044D
 2964             =caseERRJMP     EQU     #0FA51
 2965             =caseFALSE      EQU     #0FE94
 2966             =caseSIZEERR    EQU     #10399
 2967             =caseTRUE       EQU     #0FDDB
 2968             =casedrop       EQU     #0D4C0
 2969             =casedrpfls     EQU     #0FE62
 2970             =casedrptru     EQU     #10119
 2971             =char           EQU     #0449F
 2972             =check_xrange   EQU     #3F691
 2973             =check_yrange   EQU     #3F692
 2974             =chooselst      EQU     #3F2B2
 2975             =completed      EQU     #0C476
 2976             =d*             EQU     #37205
 2977             =d<             EQU     #371A9
 2978             =d<=            EQU     #371D0
 2979             =d>             EQU     #37135
 2980             =d>%            EQU     #374C0
 2981             =d>=            EQU     #371BB
 2982             =dARRYcase      EQU     #1061E
 2983             =dDIV           EQU     #372DF
 2984             =dIDNTNcase     EQU     #10682
 2985             =dLISTcase      EQU     #10632
 2986             =dMOD           EQU     #37303
 2987             =dREALNcase     EQU     #10696
 2988             =dirstrucchk    EQU     #0B964
 2989             =dmuldiv        EQU     #37325
 2990             =docr           EQU     #3F2B3
 2991             =doptr!         EQU     #12802
 2992             =doptr@         EQU     #127F2
 2993             =dowait         EQU     #3A7DB
 2994             =dvarlsBIND     EQU     #102A9
 2995             =dvbind         EQU     #3F063
 2996             =elsiename      EQU     #3F2B4
 2997             =failed         EQU     #0C48A
 2998             =filename       EQU     #3F151
 2999             =funcCache@     EQU     #27416
 3000             =funcPTR!       EQU     #12716
 3001             =funcPTR@       EQU     #12726
 3002             =gFldVal        EQU     #3F5C7
 3003             =get1           EQU     #0D05D
 3004             =grobAlertIcon  EQU     #3F5D6
 3005             =grobCheck      EQU     #3F5CE
 3006             =grobCheckKey   EQU     #3F5D5
 3007             =grobCheckX     EQU     #3F5CF
 3008             =grobInvChk     EQU     #3F5D0
 3009             =grobInvChkX    EQU     #3F5D1
 3010             =grobInvNoChk   EQU     #3F5D4
 3011             =grobInvUnChkX  EQU     #3F5D3
 3012             =grobMoreDown   EQU     #3F693
 3013             =grobMoreUp     EQU     #3F694
 3014             =grobNoMore     EQU     #3F695
 3015             =grobPOBox2     EQU     #3F699
 3016             =grobPOBox3     EQU     #3F69A
 3017             =grobPOBox4     EQU     #3F69B
 3018             =grobPOBox5     EQU     #3F69C
 3019             =grobPOBoxP2    EQU     #3F696
 3020             =grobPOBoxP3    EQU     #3F697
 3021             =grobPOBoxP4    EQU     #3F698
 3022             =grobQueryIcon  EQU     #3F5D7
 3023             =grobTitleBar   EQU     #3F5D8
 3024             =grobUnCheckX   EQU     #3F5D2
 3025             =idE0           EQU     #2C940
 3026             =idE1           EQU     #2C871
 3027             =idE2           EQU     #2C888
 3028             =idE3           EQU     #2C89F
 3029             =idE4           EQU     #2C8B6
 3030             =idE5           EQU     #2C8CD
 3031             =idE6           EQU     #2C8E4
 3032             =idE7           EQU     #2C8FB
 3033             =idE8           EQU     #2C912
 3034             =idE9           EQU     #2C929
 3035             =idF0           EQU     #2AB0F
 3036             =idF1           EQU     #2A6F2
 3037             =idF2           EQU     #2A767
 3038             =idF3           EQU     #2A7DC
 3039             =idF4           EQU     #2A851
 3040             =idF5           EQU     #2A8C6
 3041             =idF6           EQU     #2A93B
 3042             =idF7           EQU     #2A9B0
 3043             =idF8           EQU     #2AA25
 3044             =idF9           EQU     #2AA9A
 3045             =idR0           EQU     #2B8C5
 3046             =idR1           EQU     #2B4A8
 3047             =idR2           EQU     #2B51D
 3048             =idR3           EQU     #2B592
 3049             =idR4           EQU     #2B607
 3050             =idR5           EQU     #2B67C
 3051             =idR6           EQU     #2B6F1
 3052             =idR7           EQU     #2B766
 3053             =idR8           EQU     #2B7DB
 3054             =idR9           EQU     #2B850
 3055             =idU0           EQU     #2A67D
 3056             =idU1           EQU     #2A1D9
 3057             =idU2           EQU     #2A25D
 3058             =idU3           EQU     #2A2E1
 3059             =idU4           EQU     #2A365
 3060             =idU5           EQU     #2A3E9
 3061             =idU6           EQU     #2A46D
 3062             =idU7           EQU     #2A4F1
 3063             =idU8           EQU     #2A575
 3064             =idU9           EQU     #2A5F9
 3065             =idX0           EQU     #2B3BE
 3066             =idX1           EQU     #2AB84
 3067             =idX2           EQU     #2AC6E
 3068             =idX3           EQU     #2AD58
 3069             =idX4           EQU     #2AE42
 3070             =idX5           EQU     #2AF2C
 3071             =idX6           EQU     #2B016
 3072             =idX7           EQU     #2B100
 3073             =idX8           EQU     #2B1EA
 3074             =idX9           EQU     #2B2D4
 3075             =idY0           EQU     #2B433
 3076             =idY1           EQU     #2ABF9
 3077             =idY2           EQU     #2ACE3
 3078             =idY3           EQU     #2ADCD
 3079             =idY4           EQU     #2AEB7
 3080             =idY5           EQU     #2AFA1
 3081             =idY6           EQU     #2B08B
 3082             =idY7           EQU     #2B175
 3083             =idY8           EQU     #2B25F
 3084             =idY9           EQU     #2B349
 3085             =idntany        EQU     #04409
 3086             =illnameerr     EQU     #11C0D
 3087             =j%0=case       EQU     #105F6
 3088             =jEQcase        EQU     #10551
 3089             =lamany         EQU     #044A9
 3090             =lbrac          EQU     #123E8
 3091             =library        EQU     #045DF
 3092             =loopdirck      EQU     #0B9C9
 3093             =metaDUP        EQU     #1538F
 3094             =metaROTDUP     EQU     #10795
 3095             =metainsert     EQU     #3F2B5
 3096             =newsymbPA      EQU     #3F2B6
 3097             =nultrior       EQU     #3F068
 3098             =numargs        EQU     #3F1D0
 3099             =oneexpr        EQU     #3F2B7
 3100             =onestring      EQU     #3F16C
 3101             =optfilename    EQU     #3F2B8
 3102             =otherNG?       EQU     #12C4B
 3103             =otherPTR!      EQU     #127D6
 3104             =otherPTR@      EQU     #127E6
 3105             =pZpargSWAPUn   EQU     #1080D
 3106             =paramPTR!      EQU     #12756
 3107             =paramPTR@      EQU     #12766
 3108             =plDRPpZparg    EQU     #107D1
 3109             =polarPTR!      EQU     #12736
 3110             =polarPTR@      EQU     #12746
 3111             =popflag        EQU     #0D5CB
 3112             =prx1           EQU     #3F2B9
 3113             =psh            EQU     #15068
 3114             =psh&           EQU     #3F2BA
 3115             =psh1           EQU     #3F06A
 3116             =psh1&          EQU     #14F98
 3117             =psh1&rev       EQU     #3F1D2
 3118             =psh1top&       EQU     #3F06B
 3119             =psharg         EQU     #3F2BB
 3120             =pshmonop       EQU     #3F2BC
 3121             =pshtop&        EQU     #3F170
 3122             =pshzer         EQU     #3F06C
 3123             =pull           EQU     #14F70
 3124             =pullpsh1&      EQU     #3F06F
 3125             =pullrev        EQU     #3F070
 3126             =rbrac          EQU     #123DC
 3127             =realPA         EQU     #3F176
 3128             =resolved       EQU     #3F177
 3129             =reversym       EQU     #15194
 3130             =roll2ND        EQU     #3F2BD
 3131             =roll2top&      EQU     #107BD
 3132             =roll3RD        EQU     #3F1D3
 3133             =roll4TH        EQU     #3F2BE
 3134             =rollNTH        EQU     #3F2BF
 3135             =rolltwotop&    EQU     #107BD
 3136             =rrp            EQU     #0421F
 3137             =s1>            EQU     #3F69D
 3138             =sFldVal        EQU     #3F5C8
 3139             =seqPTR!        EQU     #12776
 3140             =seqPTR@        EQU     #12786
 3141             =setbeep        EQU     #2074F
 3142             =solvePTR!      EQU     #127B6
 3143             =solvePTR@      EQU     #127C6
 3144             =solverTTT      EQU     #13EA3
 3145             =startSQFORM    EQU     #3F2C0
 3146             =statPTR!       EQU     #12796
 3147             =statPTR@       EQU     #127A6
 3148             =symcomp        EQU     #17C61
 3149             =syminner&      EQU     #3F2C1
 3150             =syminner&N     EQU     #3F075
 3151             =syminnertwo    EQU     #3F2C2
 3152             =tTYPE@         EQU     #26F7F
 3153             =threeexprs     EQU     #3F2C3
 3154             =ticR           EQU     #0D752
 3155             =toLEN_DO       EQU     #0FD90
 3156             =tok$           EQU     #12432
 3157             =tok&           EQU     #1243E
 3158             =tok'           EQU     #12510
 3159             =tok*           EQU     #12564
 3160             =tok+           EQU     #1257C
 3161             =tok,           EQU     #1251C
 3162             =tok-           EQU     #12588
 3163             =tok.           EQU     #12528
 3164             =tok/           EQU     #12570
 3165             =tok0           EQU     #125D8
 3166             =tok1           EQU     #125E4
 3167             =tok2           EQU     #125F0
 3168             =tok3           EQU     #125FC
 3169             =tok4           EQU     #12608
 3170             =tok5           EQU     #12614
 3171             =tok6           EQU     #12620
 3172             =tok7           EQU     #1262C
 3173             =tok8           EQU     #12638
 3174             =tok8cktrior    EQU     #0C5DD
 3175             =tok8trior      EQU     #0C5E9
 3176             =tok9           EQU     #12644
 3177             =tok:           EQU     #17357
 3178             =tok;           EQU     #12534
 3179             =tok;triand     EQU     #3F1A2
 3180             =tok<<          EQU     #12462
 3181             =tok=           EQU     #12594
 3182             =tok>>          EQU     #12456
 3183             =tokCTGROB      EQU     #125B8
 3184             =tokCTSTR       EQU     #125CA
 3185             =tokDER         EQU     #125AC
 3186             =tokESC         EQU     #1244A
 3187             =tokSIGMA       EQU     #12486
 3188             =tokSQRT        EQU     #125A0
 3189             =tokUNKNOWN     EQU     #124EC
 3190             =tokWHERE       EQU     #12492
 3191             =tok[           EQU     #123F6
 3192             =tok]           EQU     #123DC
 3193             =tok^           EQU     #12558
 3194             =tok_           EQU     #124E0
 3195             =tokanglesign   EQU     #1247A
 3196             =tokexponent    EQU     #1246E
 3197             =toklparen      EQU     #12540
 3198             =tokquote       EQU     #12504
 3199             =tokrparen      EQU     #1254C
 3200             =toksharp       EQU     #1241A
 3201             =toktriand      EQU     #3F2C4
 3202             =tokuscore      EQU     #12426
 3203             =tok{           EQU     #12402
 3204             =tok}           EQU     #1240E
 3205             =top&           EQU     #3F077
 3206             =top&Cr         EQU     #1077C
 3207             =topic_install  EQU     #381B5
 3208             =topic_uninstall        EQU     #382B4
 3209             =twoexprs       EQU     #3F2C5
 3210             =twostrings     EQU     #3F2C6
 3211             =uart_buffer    EQU     #80319
 3212             =unroll2ND      EQU     #3F1A4
 3213             =unroll3RD      EQU     #3F2C7
 3214             =unroll4TH      EQU     #3F2C8
 3215             =unrollNTH      EQU     #3F2C9
 3216             =unsyminner     EQU     #3F079
 3217             =unsymone       EQU     #3F2CA
 3218             =verysyminner   EQU     #3F07A
 3219             =veryunsymin    EQU     #3F07B
 3220             =vunsymfcn      EQU     #3F2CB
 3221             =x#?            EQU     #3DF0F
 3222             =x%             EQU     #3C452
 3223             =x%CH           EQU     #3C53B
 3224             =x%T            EQU     #3C4C9
 3225             =x'             EQU     #3ED7E
 3226             =x+             EQU     #3AB9F
 3227             =x-             EQU     #3AD68
 3228             =x->NUM         EQU     #3A648
 3229             =x->Q           EQU     #3D80A
 3230             =x->QPI         EQU     #3D829
 3231             =x/             EQU     #3AFCA
 3232             =x<             EQU     #3C685
 3233             =x<<            EQU     #3ED4D
 3234             =x<=?           EQU     #3E049
 3235             =x<?            EQU     #3C685
 3236             =x=             EQU     #3A8DD
 3237             =x==            EQU     #3C7B9
 3238             =x=?            EQU     #3C7B9
 3239             =x>             EQU     #3C729
 3240             =x>=?           EQU     #3E0ED
 3241             =x>>            EQU     #3ED68
 3242             =x>?            EQU     #3C729
 3243             =x>HMS          EQU     #3C27B
 3244             =x>NUM          EQU     #3A648
 3245             =xABS           EQU     #3AA49
 3246             =xACOS          EQU     #3B9E1
 3247             =xACOSH         EQU     #3BAD8
 3248             =xALG->         EQU     #3E57E
 3249             =xALOG          EQU     #3BCDB
 3250             =xAND           EQU     #3DC94
 3251             =xAPPLY         EQU     #3D122
 3252             =xARG           EQU     #3B5A0
 3253             =xASIN          EQU     #3B95B
 3254             =xASINH         EQU     #3BA93
 3255             =xATAN          EQU     #3BA49
 3256             =xATANH         EQU     #3BB4A
 3257             =xAngle         EQU     #2C43A
 3258             =xAns           EQU     #2C331
 3259             =xArea          EQU     #2C9B2
 3260             =xAxes          EQU     #2C457
 3261             =xBEEP          EQU     #3A62E
 3262             =xC0            EQU     #2B9AB
 3263             =xC1            EQU     #2B8DC
 3264             =xC2            EQU     #2B8F3
 3265             =xC3            EQU     #2B90A
 3266             =xC4            EQU     #2B921
 3267             =xC5            EQU     #2B938
 3268             =xC6            EQU     #2B94F
 3269             =xC7            EQU     #2B966
 3270             =xC8            EQU     #2B97D
 3271             =xC9            EQU     #2B994
 3272             =xCASE          EQU     #3EE91
 3273             =xCEIL          EQU     #3BEB2
 3274             =xCHS           EQU     #3A9B8
 3275             =xCLLCD         EQU     #3A864
 3276             =xCMDAPPLY      EQU     #3D5B2
 3277             =xCNRM          EQU     #3C33A
 3278             =xCOLCT         EQU     #3D9F3
 3279             =xCOMB          EQU     #3C5E4
 3280             =xCONJ          EQU     #3AA9F
 3281             =xCONSTANTe     EQU     #3AB5B
 3282             =xCONT          EQU     #3A8C0
 3283             =xCORR          EQU     #2BF46
 3284             =xCOS           EQU     #3B7D5
 3285             =xCOSH          EQU     #3B8C7
 3286             =xCOV           EQU     #2BF61
 3287             =xCROSS         EQU     #3C3EC
 3288             =xConnect       EQU     #2C48D
 3289             =xCoord         EQU     #2C574
 3290             =xD0            EQU     #2B9AB
 3291             =xD1            EQU     #2B8DC
 3292             =xD2            EQU     #2B8F3
 3293             =xD3            EQU     #2B90A
 3294             =xD4            EQU     #2B921
 3295             =xD5            EQU     #2B938
 3296             =xD6            EQU     #2B94F
 3297             =xD7            EQU     #2B966
 3298             =xD8            EQU     #2B97D
 3299             =xD9            EQU     #2B994
 3300             =xD>R           EQU     #3C223
 3301             =xDER           EQU     #3CB4E
 3302             =xDET           EQU     #3C36D
 3303             =xDIR           EQU     #3EFBF
 3304             =xDISP          EQU     #3A614
 3305             =xDO            EQU     #3E695
 3306             =xDOERR         EQU     #3A3D2
 3307             =xDOT           EQU     #3C3A0
 3308             =xDate          EQU     #2C41F
 3309             =xDigits        EQU     #2C7F3
 3310             =xE             EQU     #2BB6A
 3311             =xELSE          EQU     #3E54D
 3312             =xENDDO         EQU     #3EDD3
 3313             =xENDTIC        EQU     #3ED98
 3314             =xEPS           EQU     #3AB39
 3315             =xERR0          EQU     #3A400
 3316             =xERRM          EQU     #3A42A
 3317             =xERRN          EQU     #3A415
 3318             =xERRTHEN       EQU     #3EE34
 3319             =xEVAL          EQU     #3A43F
 3320             =xEVAL>         EQU     #3D6AE
 3321             =xEXIT          EQU     #3A3D2
 3322             =xEXP           EQU     #3BBAD
 3323             =xEXPAN         EQU     #3DA36
 3324             =xEXPM          EQU     #3BD5B
 3325             =xEXPM1         EQU     #3BD5B
 3326             =xExtremum      EQU     #2C98F
 3327             =xF0            EQU     #2AAB4
 3328             =xF1            EQU     #2A697
 3329             =xF2            EQU     #2A70C
 3330             =xF3            EQU     #2A781
 3331             =xF4            EQU     #2A7F6
 3332             =xF5            EQU     #2A86B
 3333             =xF6            EQU     #2A8E0
 3334             =xF7            EQU     #2A955
 3335             =xF8            EQU     #2A9CA
 3336             =xF9            EQU     #2AA3F
 3337             =xFACT          EQU     #3BD96
 3338             =xFCNAPPLY      EQU     #3D19D
 3339             =xFIT           EQU     #2C34A
 3340             =xFLOOR         EQU     #3BE77
 3341             =xFORMUNIT      EQU     #3D905
 3342             =xFP            EQU     #3BE3C
 3343             =xFUNCTION      EQU     #3DC48
 3344             =xFmList        EQU     #3D9A3
 3345             =xFmMat         EQU     #3D9CF
 3346             =xFormat        EQU     #2C7D4
 3347             =xGrid          EQU     #2C472
 3348             =xH1            EQU     #2B9C2
 3349             =xH2            EQU     #2B9D3
 3350             =xH3            EQU     #2B9E4
 3351             =xH4            EQU     #2B9F5
 3352             =xH5            EQU     #2BA06
 3353             =xHAngle        EQU     #2C363
 3354             =xHDigits       EQU     #2C3A3
 3355             =xHFormat       EQU     #2C382
 3356             =xHMS+          EQU     #3C2CB
 3357             =xHMS-          EQU     #3C2E5
 3358             =xHMS>          EQU     #3C2A7
 3359             =xHTick         EQU     #2C658
 3360             =xHighRes       EQU     #2C4AE
 3361             =xHisWidth      EQU     #2CB2D
 3362             =xHmax          EQU     #2CB67
 3363             =xHmin          EQU     #2CB4C
 3364             =xHzoom         EQU     #2C692
 3365             =xI             EQU     #2BBBE
 3366             =xIF            EQU     #3E416
 3367             =xIFEND         EQU     #3E568
 3368             =xIFERR         EQU     #3EB17
 3369             =xIFT           EQU     #3A569
 3370             =xIFTE          EQU     #3A475
 3371             =xIM            EQU     #3CA86
 3372             =xINF           EQU     #3AB17
 3373             =xINTEGRAL      EQU     #3CD50
 3374             =xINV           EQU     #3B528
 3375             =xINVERSE       EQU     #3B4C3
 3376             =xIP            EQU     #3BE01
 3377             =xISOL          EQU     #3DAA0
 3378             =xIerr          EQU     #2C3E9
 3379             =xIndep         EQU     #2C5FD
 3380             =xInvCursor     EQU     #2C511
 3381             =xIsect         EQU     #2C972
 3382             =xKEY           EQU     #3A879
 3383             =xKILL          EQU     #3A3A8
 3384             =xLAST          EQU     #3A662
 3385             =xLN            EQU     #3BBF7
 3386             =xLNP1          EQU     #3BD25
 3387             =xLOG           EQU     #3BC69
 3388             =xLabels        EQU     #2C534
 3389             =xMANT          EQU     #3C1F2
 3390             =xMATCHDN       EQU     #3D8C6
 3391             =xMATCHUP       EQU     #3D898
 3392             =xMAX           EQU     #3BF1E
 3393             =xMAXR          EQU     #3AB17
 3394             =xMAXS          EQU     #2BE2B
 3395             =xMEANS         EQU     #2BD4D
 3396             =xMEANX         EQU     #2BE93
 3397             =xMEANY         EQU     #2BEE0
 3398             =xMEDIAN        EQU     #2BE46
 3399             =xMIN           EQU     #3BFF9
 3400             =xMINR          EQU     #3AB39
 3401             =xMINS          EQU     #2BE10
 3402             =xMOD           EQU     #3C1A3
 3403             =xNEG           EQU     #3A9B8
 3404             =xNEGNEG        EQU     #3AD12
 3405             =xNEXT          EQU     #3E98E
 3406             =xNOEVAL>       EQU     #3D7A7
 3407             =xNOT           EQU     #3DDBE
 3408             =xNS            EQU     #2BDF9
 3409             =xNmax          EQU     #2CAAB
 3410             =xNmin          EQU     #2CA90
 3411             =xNoteText      EQU     #2C812
 3412             =xNumCol        EQU     #2C794
 3413             =xNumFont       EQU     #2C7B3
 3414             =xNumIndep      EQU     #2C731
 3415             =xNumRow        EQU     #2C775
 3416             =xNumStart      EQU     #2C6CC
 3417             =xNumStep       EQU     #2C6EF
 3418             =xNumType       EQU     #2C710
 3419             =xNumZoom       EQU     #2C754
 3420             =xOFF           EQU     #3A3BD
 3421             =xOR            EQU     #3DD33
 3422             =xPARAMETRIC    EQU     #3DC60
 3423             =xPERM          EQU     #3C624
 3424             =xPI            EQU     #3AAF5
 3425             =xPOLAR         EQU     #3DC54
 3426             =xPREDIV        EQU     #3D977
 3427             =xPSDEV         EQU     #2BDDC
 3428             =xPVARS         EQU     #2BDA2
 3429             =xP\8DR         EQU     #3C935
 3430             =xPage          EQU     #2C835
 3431             =xPageNum       EQU     #2C850
 3432             =xQ1            EQU     #2BE65
 3433             =xQ3            EQU     #2BE7C
 3434             =xQUAD          EQU     #3DB03
 3435             =xQUOTE         EQU     #3D068
 3436             =xR0            EQU     #2B86A
 3437             =xR1            EQU     #2B44D
 3438             =xR2            EQU     #2B4C2
 3439             =xR3            EQU     #2B537
 3440             =xR4            EQU     #2B5AC
 3441             =xR5            EQU     #2B621
 3442             =xR6            EQU     #2B696
 3443             =xR7            EQU     #2B70B
 3444             =xR8            EQU     #2B780
 3445             =xR9            EQU     #2B7F5
 3446             =xR>D           EQU     #3C24F
 3447             =xRAND          EQU     #3C5AD
 3448             =xRDZ           EQU     #3C5C2
 3449             =xRE            EQU     #3CA30
 3450             =xRELERR        EQU     #2BF7A
 3451             =xREPEAT        EQU     #3E634
 3452             =xRND           EQU     #3C07F
 3453             =xRNRM          EQU     #3C307
 3454             =xROOT          EQU     #3CCB5
 3455             =xRPN->         EQU     #3EC15
 3456             =xRSD           EQU     #3C430
 3457             =xRULES         EQU     #3DA79
 3458             =xR\8DP         EQU     #3C885
 3459             =xRadixMark     EQU     #2C3C4
 3460             =xRecenter      EQU     #2C4EE
 3461             =xRoot          EQU     #2C957
 3462             =xS1            EQU     #2BA17
 3463             =xS1fit         EQU     #2CC1D
 3464             =xS1mark        EQU     #2CB82
 3465             =xS2            EQU     #2BA28
 3466             =xS2fit         EQU     #2CC3A
 3467             =xS2mark        EQU     #2CBA1
 3468             =xS3            EQU     #2BA39
 3469             =xS3fit         EQU     #2CC57
 3470             =xS3mark        EQU     #2CBC0
 3471             =xS4            EQU     #2BA4A
 3472             =xS4fit         EQU     #2CC74
 3473             =xS4mark        EQU     #2CBDF
 3474             =xS5            EQU     #2BA5B
 3475             =xS5fit         EQU     #2CC91
 3476             =xS5mark        EQU     #2CBFE
 3477             =xSAME          EQU     #3DC72
 3478             =xSHOW          EQU     #3DB51
 3479             =xSIGN          EQU     #3B5EF
 3480             =xSILENT'       EQU     #3EBFB
 3481             =xSIN           EQU     #3B781
 3482             =xSINH          EQU     #3B87D
 3483             =xSQ            EQU     #3B6E6
 3484             =xSQRT          EQU     #3B639
 3485             =xSSDEV         EQU     #2BDBF
 3486             =xSTART         EQU     #3E710
 3487             =xSTARTVAR      EQU     #3E7A8
 3488             =xSTEP          EQU     #3EABD
 3489             =xSUM           EQU     #3CEF5
 3490             =xSVARS         EQU     #2BD85
 3491             =xSX            EQU     #2BEB0
 3492             =xSX2           EQU     #2BEC7
 3493             =xSXY           EQU     #2BF2D
 3494             =xSY            EQU     #2BEFD
 3495             =xSY2           EQU     #2BF14
 3496             =xSYSEVAL       EQU     #3A5C4
 3497             =xSeqPlot       EQU     #2CAC6
 3498             =xSimult        EQU     #2C4CF
 3499             =xSlope         EQU     #2C9CD
 3500             =xStatMode      EQU     #2CAE7
 3501             =xStatPlot      EQU     #2CB0A
 3502             =xTAN           EQU     #3B829
 3503             =xTANH          EQU     #3B911
 3504             =xTAYLR         EQU     #3DBDC
 3505             =xTHEN          EQU     #3E4AB
 3506             =xTHENCASE      EQU     #3EF1F
 3507             =xTOTS          EQU     #2BD6A
 3508             =xTRNC          EQU     #3C111
 3509             =xTStep         EQU     #2CA20
 3510             =xThetaMax      EQU     #2CA58
 3511             =xThetaMin      EQU     #2CA3D
 3512             =xThetaStep     EQU     #2CA73
 3513             =xTime          EQU     #2C404
 3514             =xTmax          EQU     #2CA05
 3515             =xTmin          EQU     #2C9EA
 3516             =xTracing       EQU     #2C553
 3517             =xU0            EQU     #2A613
 3518             =xU1            EQU     #2A174
 3519             =xU2            EQU     #2A1F3
 3520             =xU3            EQU     #2A277
 3521             =xU4            EQU     #2A2FB
 3522             =xU5            EQU     #2A37F
 3523             =xU6            EQU     #2A403
 3524             =xU7            EQU     #2A487
 3525             =xU8            EQU     #2A50B
 3526             =xU9            EQU     #2A58F
 3527             =xUNTIL         EQU     #3E700
 3528             =xVTick         EQU     #2C675
 3529             =xVzoom         EQU     #2C6AF
 3530             =xWAIT          EQU     #3A777
 3531             =xWHERE         EQU     #3D017
 3532             =xWHILE         EQU     #3E5C1
 3533             =xWHILEEND      EQU     #3EDB3
 3534             =xX0            EQU     #2B363
 3535             =xX1            EQU     #2AB29
 3536             =xX2            EQU     #2AC13
 3537             =xX3            EQU     #2ACFD
 3538             =xX4            EQU     #2ADE7
 3539             =xX5            EQU     #2AED1
 3540             =xX6            EQU     #2AFBB
 3541             =xX7            EQU     #2B0A5
 3542             =xX8            EQU     #2B18F
 3543             =xX9            EQU     #2B279
 3544             =xXOR           EQU     #3DE2A
 3545             =xXPON          EQU     #3BEED
 3546             =xXROOT         EQU     #3B36B
 3547             =xXcross        EQU     #2C61A
 3548             =xXmax          EQU     #2C5AC
 3549             =xXmin          EQU     #2C591
 3550             =xY0            EQU     #2B3D8
 3551             =xY1            EQU     #2AB9E
 3552             =xY2            EQU     #2AC88
 3553             =xY3            EQU     #2AD72
 3554             =xY4            EQU     #2AE5C
 3555             =xY5            EQU     #2AF46
 3556             =xY6            EQU     #2B030
 3557             =xY7            EQU     #2B11A
 3558             =xY8            EQU     #2B204
 3559             =xY9            EQU     #2B2EE
 3560             =xYcross        EQU     #2C639
 3561             =xYmax          EQU     #2C5E2
 3562             =xYmin          EQU     #2C5C7
 3563             =x^             EQU     #3B178
 3564             =xa             EQU     #2BB16
 3565             =xb             EQU     #2BB2B
 3566             =xc             EQU     #2BB40
 3567             =xd             EQU     #2BB55
 3568             =xf             EQU     #2BB7F
 3569             =xg             EQU     #2BB94
 3570             =xg0            EQU     #2C24B
 3571             =xg1            EQU     #2C262
 3572             =xg2            EQU     #2C279
 3573             =xg3            EQU     #2C290
 3574             =xg4            EQU     #2C2A7
 3575             =xg5            EQU     #2C2BE
 3576             =xg6            EQU     #2C2D5
 3577             =xg7            EQU     #2C2EC
 3578             =xg8            EQU     #2C303
 3579             =xg9            EQU     #2C31A
 3580             =xh             EQU     #2BBA9
 3581             =xi             EQU     #3AB7D
 3582             =xint           EQU     #3CAD2
 3583             =xj             EQU     #2BBD3
 3584             =xk             EQU     #2BBE8
 3585             =xl             EQU     #2BBFD
 3586             =xl0            EQU     #2C165
 3587             =xl1            EQU     #2C17C
 3588             =xl2            EQU     #2C193
 3589             =xl3            EQU     #2C1AA
 3590             =xl4            EQU     #2C1C1
 3591             =xl5            EQU     #2C1D8
 3592             =xl6            EQU     #2C1EF
 3593             =xl7            EQU     #2C206
 3594             =xl8            EQU     #2C21D
 3595             =xl9            EQU     #2C234
 3596             =xm             EQU     #2BC12
 3597             =xm0            EQU     #2C07F
 3598             =xm1            EQU     #2C096
 3599             =xm2            EQU     #2C0AD
 3600             =xm3            EQU     #2C0C4
 3601             =xm4            EQU     #2C0DB
 3602             =xm5            EQU     #2C0F2
 3603             =xm6            EQU     #2C109
 3604             =xm7            EQU     #2C120
 3605             =xm8            EQU     #2C137
 3606             =xm9            EQU     #2C14E
 3607             =xn             EQU     #2BC27
 3608             =xn1            EQU     #2BAC1
 3609             =xn2            EQU     #2BAD2
 3610             =xn3            EQU     #2BAE3
 3611             =xn4            EQU     #2BAF4
 3612             =xn5            EQU     #2BB05
 3613             =xo             EQU     #2BC3C
 3614             =xp             EQU     #2BC51
 3615             =xq             EQU     #2BC66
 3616             =xr             EQU     #2BC7B
 3617             =xs             EQU     #2BC90
 3618             =xs1            EQU     #2BA6C
 3619             =xs2            EQU     #2BA7D
 3620             =xs3            EQU     #2BA8E
 3621             =xs4            EQU     #2BA9F
 3622             =xs5            EQU     #2BAB0
 3623             =xt             EQU     #2BCA5
 3624             =xtheta         EQU     #2BD38
 3625             =xu             EQU     #2BCBA
 3626             =xv             EQU     #2BCCF
 3627             =xw             EQU     #2BCE4
 3628             =xx             EQU     #2BCF9
 3629             =xy             EQU     #2BD0E
 3630             =xz             EQU     #2BD23
 3631             =xz0            EQU     #2BF99
 3632             =xz1            EQU     #2BFB0
 3633             =xz2            EQU     #2BFC7
 3634             =xz3            EQU     #2BFDE
 3635             =xz4            EQU     #2BFF5
 3636             =xz5            EQU     #2C00C
 3637             =xz6            EQU     #2C023
 3638             =xz7            EQU     #2C03A
 3639             =xz8            EQU     #2C051
 3640             =xz9            EQU     #2C068
 3641             ={NoteText}     EQU     #3F8FB
 3642             ={NumVars}      EQU     #3F903
 3643             ={SketchSet}    EQU     #3F900
 3644             ={StatVars}     EQU     #3F902
 3645             ={}N            EQU     #05C12
 3646             =~*ord          EQU     #00640AB
 3647             =~*spec         EQU     #00630AB
 3648             =~*xH           EQU     #0049004
 3649             =~*xW           EQU     #004A004
 3650             =~::args        EQU     #00060E8
 3651             =~?NULLSETDIM   EQU     #00130E8
 3652             =~ALSKey1.1     EQU     #00000A5
 3653             =~ALSKey1.2     EQU     #00010A5
 3654             =~ALSKey1.3     EQU     #00020A5
 3655             =~ALSKey1.4     EQU     #00030A5
 3656             =~ALSKey1.5     EQU     #00040A5
 3657             =~ALSKey1.6     EQU     #00050A5
 3658             =~ALSKey2.1     EQU     #00060A5
 3659             =~ALSKey2.2     EQU     #00070A5
 3660             =~ALSKey2.3     EQU     #00080A5
 3661             =~ALSKey2.4     EQU     #00090A5
 3662             =~ALSKey3.1     EQU     #000A0A5
 3663             =~ALSKey3.2     EQU     #000B0A5
 3664             =~ALSKey3.3     EQU     #000C0A5
 3665             =~ALSKey3.4     EQU     #000D0A5
 3666             =~ALSKey3.5     EQU     #000E0A5
 3667             =~ALSKey3.6     EQU     #000F0A5
 3668             =~ALSKey4.1     EQU     #00100A5
 3669             =~ALSKey4.2     EQU     #00110A5
 3670             =~ALSKey4.3     EQU     #00120A5
 3671             =~ALSKey4.4     EQU     #00130A5
 3672             =~ALSKey4.5     EQU     #00140A5
 3673             =~ALSKey5.1     EQU     #00150A5
 3674             =~ALSKey5.2     EQU     #00160A5
 3675             =~ALSKey5.3     EQU     #00170A5
 3676             =~ALSKey5.4     EQU     #00180A5
 3677             =~ALSKey5.5     EQU     #00190A5
 3678             =~ALSKey6.1     EQU     #001A0A5
 3679             =~ALSKey6.2     EQU     #001B0A5
 3680             =~ALSKey6.3     EQU     #001C0A5
 3681             =~ALSKey6.4     EQU     #001D0A5
 3682             =~ALSKey6.5     EQU     #001E0A5
 3683             =~ALSKey7.1     EQU     #001F0A5
 3684             =~ALSKey7.2     EQU     #00200A5
 3685             =~ALSKey7.3     EQU     #00210A5
 3686             =~ALSKey7.4     EQU     #00220A5
 3687             =~ALSKey7.5     EQU     #00230A5
 3688             =~ALSKey8.1     EQU     #00240A5
 3689             =~ALSKey8.2     EQU     #00250A5
 3690             =~ALSKey8.3     EQU     #00260A5
 3691             =~ALSKey8.4     EQU     #00270A5
 3692             =~ALSKey8.5     EQU     #00280A5
 3693             =~ALSKey9.1     EQU     #00290A5
 3694             =~ALSKey9.2     EQU     #002A0A5
 3695             =~ALSKey9.3     EQU     #002B0A5
 3696             =~ALSKey9.4     EQU     #002C0A5
 3697             =~ALSKey9.5     EQU     #002D0A5
 3698             =~ANSKey1.1     EQU     #00000A4
 3699             =~ANSKey1.2     EQU     #00010A4
 3700             =~ANSKey1.3     EQU     #00020A4
 3701             =~ANSKey1.4     EQU     #00030A4
 3702             =~ANSKey1.5     EQU     #00040A4
 3703             =~ANSKey1.6     EQU     #00050A4
 3704             =~ANSKey2.1     EQU     #00060A4
 3705             =~ANSKey2.2     EQU     #00070A4
 3706             =~ANSKey2.3     EQU     #00080A4
 3707             =~ANSKey2.4     EQU     #00090A4
 3708             =~ANSKey3.1     EQU     #000A0A4
 3709             =~ANSKey3.2     EQU     #000B0A4
 3710             =~ANSKey3.3     EQU     #000C0A4
 3711             =~ANSKey3.4     EQU     #000D0A4
 3712             =~ANSKey3.5     EQU     #000E0A4
 3713             =~ANSKey3.6     EQU     #000F0A4
 3714             =~ANSKey4.1     EQU     #00100A4
 3715             =~ANSKey4.2     EQU     #00110A4
 3716             =~ANSKey4.3     EQU     #00120A4
 3717             =~ANSKey4.4     EQU     #00130A4
 3718             =~ANSKey4.5     EQU     #00140A4
 3719             =~ANSKey5.1     EQU     #00150A4
 3720             =~ANSKey5.2     EQU     #00160A4
 3721             =~ANSKey5.3     EQU     #00170A4
 3722             =~ANSKey5.4     EQU     #00180A4
 3723             =~ANSKey5.5     EQU     #00190A4
 3724             =~ANSKey6.1     EQU     #001A0A4
 3725             =~ANSKey6.2     EQU     #001B0A4
 3726             =~ANSKey6.3     EQU     #001C0A4
 3727             =~ANSKey6.4     EQU     #001D0A4
 3728             =~ANSKey6.5     EQU     #001E0A4
 3729             =~ANSKey7.1     EQU     #001F0A4
 3730             =~ANSKey7.2     EQU     #00200A4
 3731             =~ANSKey7.3     EQU     #00210A4
 3732             =~ANSKey7.4     EQU     #00220A4
 3733             =~ANSKey7.5     EQU     #00230A4
 3734             =~ANSKey8.1     EQU     #00240A4
 3735             =~ANSKey8.2     EQU     #00250A4
 3736             =~ANSKey8.3     EQU     #00260A4
 3737             =~ANSKey8.4     EQU     #00270A4
 3738             =~ANSKey8.5     EQU     #00280A4
 3739             =~ANSKey9.1     EQU     #00290A4
 3740             =~ANSKey9.2     EQU     #002A0A4
 3741             =~ANSKey9.3     EQU     #002B0A4
 3742             =~ANSKey9.4     EQU     #002C0A4
 3743             =~ANSKey9.5     EQU     #002D0A4
 3744             =~AttentionKe   EQU     #002E0A1 partial match
 3745             =~CHECKEXISTS   EQU     #00830F0
 3746             =~CLRTOPICLAM   EQU     #00260F1 ~_fp_
 3747             =~COLCTDER      EQU     #008F0F0
 3748             =~COLCTFCNAP    EQU     #00940F0
 3749             =~COLCTIFTE     EQU     #00920F0
 3750             =~COLCTINTG     EQU     #00900F0
 3751             =~COLCTQUOTE    EQU     #00930F0
 3752             =~COLCTSUM      EQU     #00910F0
 3753             =~COMPLEXDUMM   EQU     #0083002 partial match
 3754             =~ChkDaList     EQU     #00580AB
 3755             =~DArrow        EQU     #000E0A1
 3756             =~DefauStat2T   EQU     #00210F1 partial match
 3757             =~DefauStatTy   EQU     #00200F1 partial match
 3758             =~DoExponent    EQU     #00330A2
 3759             =~DoMenuKey1N   EQU     #00000A1 partial match
 3760             =~DoMenuKey2N   EQU     #00010A1 partial match
 3761             =~DoMenuKey3N   EQU     #00020A1 partial match
 3762             =~DoMenuKey4N   EQU     #00030A1 partial match
 3763             =~DoMenuKey5N   EQU     #00040A1 partial match
 3764             =~DoMenuKey6N   EQU     #00050A1 partial match
 3765             =~DoNumeric:    EQU     #001F0E8
 3766             =~Enter/Again   EQU     #00320A1
 3767             =~FarDArrow     EQU     #000E0A2
 3768             =~FarLArrow     EQU     #000D0A2
 3769             =~FarRArrow     EQU     #000F0A2
 3770             =~FarUArrow     EQU     #00090A2
 3771             =~GETPLTLABLS   EQU     #00270F1
 3772             =~GetTypeText   EQU     #001F0F1 ~_fp_
 3773             =~I:-InvSin     EQU     #00010F0
 3774             =~I:-InvSinh    EQU     #00090F0
 3775             =~I:Acosh       EQU     #00170F0
 3776             =~I:Asinh       EQU     #00160F0
 3777             =~I:Atan        EQU     #00130F0
 3778             =~I:LnTan       EQU     #00030F0
 3779             =~I:LnTanh      EQU     #000A0F0
 3780             =~I:Tanh        EQU     #000C0F0
 3781             =~INTEMPOB?     EQU     #00220E8 ~_fp_
 3782             =~INTGACOS      EQU     #00060F0
 3783             =~INTGALOG      EQU     #000F0F0
 3784             =~INTGASIN      EQU     #00050F0
 3785             =~INTGATAN      EQU     #00070F0
 3786             =~INTGCOS       EQU     #00020F0
 3787             =~INTGCOSH      EQU     #000B0F0
 3788             =~INTGDER       EQU     #00190F0
 3789             =~INTGEXPM      EQU     #000E0F0
 3790             =~INTGINV       EQU     #00120F0
 3791             =~INTGLN        EQU     #00100F0
 3792             =~INTGLOG       EQU     #00110F0
 3793             =~INTGSIGN      EQU     #00180F0
 3794             =~INTGSIN       EQU     #00000F0
 3795             =~INTGSINH      EQU     #00080F0
 3796             =~INTGSQ        EQU     #00140F0
 3797             =~INTGSQRT      EQU     #00150F0
 3798             =~INTGTAN       EQU     #00040F0
 3799             =~INTGTANH      EQU     #000D0F0
 3800             =~LArrow        EQU     #000D0A1
 3801             =~LIXRecv       EQU     #00300E8 ~_fp_
 3802             =~LIXSend       EQU     #00310E8 ~_fp_
 3803             =~LSKey1.1      EQU     #00000A2
 3804             =~LSKey1.2      EQU     #00010A2
 3805             =~LSKey1.3      EQU     #00020A2
 3806             =~LSKey1.4      EQU     #00030A2
 3807             =~LSKey1.5      EQU     #00040A2
 3808             =~LSKey1.6      EQU     #00050A2
 3809             =~LSKey2.1      EQU     #00060A2
 3810             =~LSKey2.2      EQU     #00070A2
 3811             =~LSKey2.3      EQU     #00080A2
 3812             =~LSKey3.1      EQU     #000A0A2
 3813             =~LSKey3.2      EQU     #000B0A2
 3814             =~LSKey3.3      EQU     #000C0A2
 3815             =~LSKey4.1      EQU     #00100A2
 3816             =~LSKey4.2      EQU     #00110A2
 3817             =~LSKey4.3      EQU     #00120A2
 3818             =~LSKey4.4      EQU     #00130A2
 3819             =~LSKey4.5      EQU     #00140A2
 3820             =~LSKey5.1      EQU     #00150A2
 3821             =~LSKey5.2      EQU     #00160A2
 3822             =~LSKey5.4      EQU     #00180A2
 3823             =~LSKey5.5      EQU     #00190A2
 3824             =~LSKey6.1      EQU     #001A0A2
 3825             =~LSKey6.2      EQU     #001B0A2
 3826             =~LSKey6.3      EQU     #001C0A2
 3827             =~LSKey6.4      EQU     #001D0A2
 3828             =~LSKey6.5      EQU     #001E0A2
 3829             =~LSKey7.1      EQU     #001F0A2
 3830             =~LSKey7.2      EQU     #00200A2
 3831             =~LSKey7.3      EQU     #00210A2
 3832             =~LSKey7.4      EQU     #00220A2
 3833             =~LSKey7.5      EQU     #00230A2
 3834             =~LSKey8.1      EQU     #00240A2
 3835             =~LSKey8.2      EQU     #00250A2
 3836             =~LSKey8.3      EQU     #00260A2
 3837             =~LSKey8.4      EQU     #00270A2
 3838             =~LSKey8.5      EQU     #00280A2
 3839             =~LSKey9.1      EQU     #00290A2
 3840             =~LSKey9.2      EQU     #002A0A2
 3841             =~LSKey9.3      EQU     #002B0A2
 3842             =~LSKey9.4      EQU     #002C0A2
 3843             =~LSKey9.5      EQU     #002D0A2
 3844             =~MAKEEPIDN     EQU     #00330C2
 3845             =~MiscIFMsg     EQU     #00000B9
 3846             =~NSKey3.2      EQU     #000B0A1
 3847             =~NSKey3.3      EQU     #000C0A1
 3848             =~NSKey4.1      EQU     #00100A1
 3849             =~NSKey4.2      EQU     #00110A1
 3850             =~NSKey4.3      EQU     #00120A1
 3851             =~NSKey4.4      EQU     #00130A1
 3852             =~NSKey4.5      EQU     #00140A1
 3853             =~NSKey5.2      EQU     #00160A1
 3854             =~NSKey5.3      EQU     #00170A1
 3855             =~NSKey5.4      EQU     #00180A1
 3856             =~NSKey5.5      EQU     #00190A1
 3857             =~NSKey6.1      EQU     #001A0A1
 3858             =~NSKey6.2      EQU     #001B0A1
 3859             =~NSKey6.3      EQU     #001C0A1
 3860             =~NSKey6.4      EQU     #001D0A1
 3861             =~NSKey6.5      EQU     #001E0A1
 3862             =~NSKey7.1      EQU     #001F0A1
 3863             =~NSKey7.2      EQU     #00200A1
 3864             =~NSKey7.3      EQU     #00210A1
 3865             =~NSKey7.4      EQU     #00220A1
 3866             =~NSKey7.5      EQU     #00230A1
 3867             =~NSKey8.1      EQU     #00240A1
 3868             =~NSKey8.2      EQU     #00250A1
 3869             =~NSKey8.3      EQU     #00260A1
 3870             =~NSKey8.4      EQU     #00270A1
 3871             =~NSKey8.5      EQU     #00280A1
 3872             =~NSKey9.2      EQU     #002A0A1
 3873             =~NSKey9.3      EQU     #002B0A1
 3874             =~NSKey9.4      EQU     #002C0A1
 3875             =~NSKey9.5      EQU     #002D0A1
 3876             =~NotHidden     EQU     #00210E8
 3877             =~NullMenuKey   EQU     #012F0F2
 3878             =~POINTERR      EQU     #00280F1 ~_fp_
 3879             =~POINTEXIT     EQU     #00290F1 ~_fp_
 3880             =~POLARDUMMY    EQU     #0084002
 3881             =~PlotIFMsg     EQU     #00000BE
 3882             =~PlotViewKey   EQU     #00330A1
 3883             =~PolyNSymbF    EQU     #00080C0
 3884             =~PolyNSymbP    EQU     #00070C0
 3885             =~RArrow        EQU     #000F0A1
 3886             =~REIM[]*       EQU     #00620F0
 3887             =~SETTOPICLAM   EQU     #00250F1
 3888             =~SolveApEntr   EQU     #00240F1 partial match
 3889             =~SolveIFMsg    EQU     #00000BF
 3890             =~StatIFMsg     EQU     #00000BB
 3891             =~StdApEntry    EQU     #00230F1 ~_fp_
 3892             =~SymbViewKey   EQU     #00340A1
 3893             =~TableViewKe   EQU     #00350A1 partial match
 3894             =~TopicLibKey   EQU     #00360A1
 3895             =~UpArrow       EQU     #00090A1
 3896             =~UseHidden{}   EQU     #00200E8 partial match
 3897             =~WHEREDER      EQU     #00780F0 ~_fp_
 3898             =~WHEREFCNAPP   EQU     #00770F0 partial match
 3899             =~WHEREIFTE     EQU     #00790F0 ~_fp_
 3900             =~WHEREINTG     EQU     #007C0F0 ~_fp_
 3901             =~WHERESUM      EQU     #007D0F0 ~_fp_
 3902             =~WHEREWHERE    EQU     #007A0F0 ~_fp_
 3903             =~XEQDIAG>L     EQU     #004B0AB ~_fp_
 3904             =~XEQDIAG>R     EQU     #004C0AB ~_fp_
 3905             =~XEQRANM       EQU     #004D0AB ~_fp_
 3906             =~XEQSYMLIN     EQU     #003B0AB ~_fp_
 3907             =~XEQXDPTCH     EQU     #00810F0
 3908             =~XEVALp*       EQU     #008A0F0
 3909             =~XEVALp?       EQU     #00890F0
 3910             =~XPURGEp*      EQU     #008C0F0
 3911             =~XPURGEp?      EQU     #008B0F0
 3912             =~XRCLp*        EQU     #00880F0
 3913             =~XRCLp?        EQU     #00850F0
 3914             =~XRCLp?acc>    EQU     #008E0F0
 3915             =~XRCLpL        EQU     #00870F0
 3916             =~XRCLpNL       EQU     #00860F0
 3917             =~XSTOCHECK     EQU     #007E0F0
 3918             =~XSTOCHECK10   EQU     #007F0F0
 3919             =~Xcont         EQU     #00820F0
 3920             =~adjdiv        EQU     #004D0F0
 3921             =~adjdivsign    EQU     #004B0F0
 3922             =~adjsign       EQU     #004C0F0
 3923             =~arryspec      EQU     #002E0E8
 3924             =~bad^          EQU     #00690AB
 3925             =~convertaddr   EQU     #008D0F0 partial match
 3926             =~copysub       EQU     #002D0E8
 3927             =~covD/D*       EQU     #00950F0
 3928             =~covD/D+       EQU     #00980F0
 3929             =~covD/D-       EQU     #00990F0
 3930             =~covD/D/       EQU     #009A0F0
 3931             =~covD/D=       EQU     #009B0F0
 3932             =~covD/DABS     EQU     #009D0F0
 3933             =~covD/DACOS    EQU     #009E0F0
 3934             =~covD/DACOSH   EQU     #009F0F0
 3935             =~covD/DALOG    EQU     #00A00F0
 3936             =~covD/DAPPLY   EQU     #00BB0F0 ~_fp_
 3937             =~covD/DARG     EQU     #00A10F0
 3938             =~covD/DASIN    EQU     #00A20F0
 3939             =~covD/DASINH   EQU     #00A30F0
 3940             =~covD/DATAN    EQU     #00A40F0
 3941             =~covD/DATANH   EQU     #00A50F0
 3942             =~covD/DCOS     EQU     #00A60F0
 3943             =~covD/DCOSH    EQU     #00A70F0
 3944             =~covD/DCROSS   EQU     #00960F0 ~_fp_
 3945             =~covD/DDER     EQU     #00B70F0
 3946             =~covD/DDOT     EQU     #00970F0 ~_fp_
 3947             =~covD/DEXP     EQU     #00A80F0
 3948             =~covD/DIFTE    EQU     #00AD0F0
 3949             =~covD/DINTG    EQU     #00B90F0 ~_fp_
 3950             =~covD/DINV     EQU     #00A90F0
 3951             =~covD/DLN      EQU     #00AA0F0
 3952             =~covD/DLNP1    EQU     #00AB0F0
 3953             =~covD/DLOG     EQU     #00AC0F0
 3954             =~covD/DSIN     EQU     #00AE0F0
 3955             =~covD/DSINH    EQU     #00AF0F0
 3956             =~covD/DSQ      EQU     #00B00F0
 3957             =~covD/DSQRT    EQU     #00B10F0
 3958             =~covD/DSUM     EQU     #00BA0F0 ~_fp_
 3959             =~covD/DTAN     EQU     #00B20F0
 3960             =~covD/DTANH    EQU     #00B30F0
 3961             =~covD/DWHERE   EQU     #00B80F0 ~_fp_
 3962             =~covD/D^       EQU     #00B40F0
 3963             =~covD/D^X      EQU     #00B50F0
 3964             =~covD/D^Y      EQU     #00B60F0
 3965             =~covD/Dalg=    EQU     #009C0F0
 3966             =~covINV*       EQU     #00C90F0
 3967             =~covINV+       EQU     #00C60F0
 3968             =~covINV-       EQU     #00C70F0
 3969             =~covINV/       EQU     #00CA0F0
 3970             =~covINV=       EQU     #00C80F0
 3971             =~covINVALOG    EQU     #00D40F0
 3972             =~covINVCOS     EQU     #00CF0F0
 3973             =~covINVCOSH    EQU     #00D20F0
 3974             =~covINVEXP     EQU     #00CD0F0
 3975             =~covINVEXPM1   EQU     #00D50F0
 3976             =~covINVSIN     EQU     #00CE0F0
 3977             =~covINVSINH    EQU     #00D10F0
 3978             =~covINVTAN     EQU     #00D00F0
 3979             =~covINVTANH    EQU     #00D30F0
 3980             =~covINV^       EQU     #00CB0F0
 3981             =~covINV^X      EQU     #00CC0F0
 3982             =~covLBSTO      EQU     #00800F0
 3983             =~covMANATG     EQU     #00C50F0
 3984             =~covMANCSIV    EQU     #00C10F0
 3985             =~covMANEXP     EQU     #00BF0F0
 3986             =~covMANMENU*   EQU     #00BD0F0 partial match
 3987             =~covMANMENU+   EQU     #00BC0F0 partial match
 3988             =~covMANMENUC   EQU     #00C30F0 partial match
 3989             =~covMANMENUE   EQU     #00C20F0 partial match
 3990             =~covMANMENUL   EQU     #00C00F0 partial match
 3991             =~covMANMENU^   EQU     #00BE0F0
 3992             =~covMANTRG     EQU     #00C40F0
 3993             =~covWSPLIT     EQU     #007B0F0
 3994             =~covmanCOL     EQU     #00760F0
 3995             =~covmetaLIBS   EQU     #00840F0
 3996             =~docmdlist     EQU     #000D0E8 ~_fp_
 3997             =~doidseqn      EQU     #00040E8 ~_fp_
 3998             =~dolatorre     EQU     #000F0E8 ~_fp_
 3999             =~dolatorre+    EQU     #00110E8
 4000             =~dolatorre2    EQU     #00120E8
 4001             =~dolist+       EQU     #00190E8
 4002             =~dontuple      EQU     #00020E8 ~_fp_
 4003             =~dontuple#     EQU     #00030E8 ~_fp_
 4004             =~dopcoeff      EQU     #005D0AB
 4005             =~dopolydiv     EQU     #005C0AB
 4006             =~dopolyz       EQU     #005B0AB ~_fp_
 4007             =~doptrseqn     EQU     #000A0E8 ~_fp_
 4008             =~dopval        EQU     #006B0AB
 4009             =~dosecntuple   EQU     #00010E8 ~_fp_
 4010             =~dosecseqn     EQU     #00080E8 ~_fp_
 4011             =~doseq         EQU     #00000E8
 4012             =~doseqn        EQU     #000B0E8 ~_fp_
 4013             =~doseqn#       EQU     #000C0E8
 4014             =~dosort        EQU     #001A0E8 ~_fp_
 4015             =~elsielists?   EQU     #00100E8
 4016             =~etorc         EQU     #002F0E8
 4017             =~idE0          EQU     #01100F2
 4018             =~idE1          EQU     #01070F2
 4019             =~idE2          EQU     #01080F2
 4020             =~idE3          EQU     #01090F2
 4021             =~idE4          EQU     #010A0F2
 4022             =~idE5          EQU     #010B0F2
 4023             =~idE6          EQU     #010C0F2
 4024             =~idE7          EQU     #010D0F2
 4025             =~idE8          EQU     #010E0F2
 4026             =~idE9          EQU     #010F0F2
 4027             =~idF0          EQU     #00270F2
 4028             =~idF1          EQU     #00150F2
 4029             =~idF2          EQU     #00170F2
 4030             =~idF3          EQU     #00190F2
 4031             =~idF4          EQU     #001B0F2
 4032             =~idF5          EQU     #001D0F2
 4033             =~idF6          EQU     #001F0F2
 4034             =~idF7          EQU     #00210F2
 4035             =~idF8          EQU     #00230F2
 4036             =~idF9          EQU     #00250F2
 4037             =~idR0          EQU     #00630F2
 4038             =~idR1          EQU     #00510F2
 4039             =~idR2          EQU     #00530F2
 4040             =~idR3          EQU     #00550F2
 4041             =~idR4          EQU     #00570F2
 4042             =~idR5          EQU     #00590F2
 4043             =~idR6          EQU     #005B0F2
 4044             =~idR7          EQU     #005D0F2
 4045             =~idR8          EQU     #005F0F2
 4046             =~idR9          EQU     #00610F2
 4047             =~idU0          EQU     #00130F2
 4048             =~idU1          EQU     #00010F2
 4049             =~idU2          EQU     #00030F2
 4050             =~idU3          EQU     #00050F2
 4051             =~idU4          EQU     #00070F2
 4052             =~idU5          EQU     #00090F2
 4053             =~idU6          EQU     #000B0F2
 4054             =~idU7          EQU     #000D0F2
 4055             =~idU8          EQU     #000F0F2
 4056             =~idU9          EQU     #00110F2
 4057             =~idX0          EQU     #004D0F2
 4058             =~idX1          EQU     #00290F2
 4059             =~idX2          EQU     #002D0F2
 4060             =~idX3          EQU     #00310F2
 4061             =~idX4          EQU     #00350F2
 4062             =~idX5          EQU     #00390F2
 4063             =~idX6          EQU     #003D0F2
 4064             =~idX7          EQU     #00410F2
 4065             =~idX8          EQU     #00450F2
 4066             =~idX9          EQU     #00490F2
 4067             =~idY0          EQU     #004F0F2
 4068             =~idY1          EQU     #002B0F2
 4069             =~idY2          EQU     #002F0F2
 4070             =~idY3          EQU     #00330F2
 4071             =~idY4          EQU     #00370F2
 4072             =~idY5          EQU     #003B0F2
 4073             =~idY6          EQU     #003F0F2
 4074             =~idY7          EQU     #00430F2
 4075             =~idY8          EQU     #00470F2
 4076             =~idY9          EQU     #004B0F2
 4077             =~la+COL        EQU     #000D0C3 ~_fp_
 4078             =~la+COLs       EQU     #000E0C3
 4079             =~la+ELEM       EQU     #00110C3
 4080             =~la+ELEMc      EQU     #00100C3 ~_fp_
 4081             =~la+ELEMr      EQU     #000F0C3 ~_fp_
 4082             =~la+RCsLP      EQU     #000C0C3
 4083             =~la+ROW        EQU     #000A0C3 ~_fp_
 4084             =~la+ROWs       EQU     #000B0C3
 4085             =~la-COL        EQU     #00090C3 ~_fp_
 4086             =~la-ROW        EQU     #00070C3 ~_fp_
 4087             =~la>COL        EQU     #00140C3 ~_fp_
 4088             =~la>DIAG       EQU     #00170C3 ~_fp_
 4089             =~la>ELEM       EQU     #00130C3
 4090             =~la>ROW        EQU     #00120C3 ~_fp_
 4091             =~laBPMUTE      EQU     #00200C2
 4092             =~laCOL>        EQU     #00160C3 ~_fp_
 4093             =~laCOND        EQU     #004D0C2 ~_fp_
 4094             =~laCONDdone    EQU     #004E0C2
 4095             =~laCSWP        EQU     #00040C3 ~_fp_
 4096             =~laDELROW      EQU     #00190C3
 4097             =~laDIAG>       EQU     #00180C3 ~_fp_
 4098             =~laDT          EQU     #00510C2
 4099             =~laECQhQAQh    EQU     #00070C2
 4100             =~laEGV         EQU     #00040C2 ~_fp_
 4101             =~laEGVL        EQU     #00020C2 ~_fp_
 4102             =~laEGVL%%      EQU     #00030C2
 4103             =~laEGetTiny    EQU     #005E0C2
 4104             =~laEgCQRI      EQU     #001B0C2
 4105             =~laEgCQRIk1    EQU     #001C0C2
 4106             =~laEgCSchur    EQU     #001A0C2
 4107             =~laEgHF        EQU     #00060C2
 4108             =~laEgIsoVal    EQU     #000A0C2
 4109             =~laEgM*G2      EQU     #00110C2
 4110             =~laEgM*RG3     EQU     #000F0C2
 4111             =~laEgPrep      EQU     #001E0C2
 4112             =~laEgQRIk0     EQU     #000C0C2
 4113             =~laEgQkHA      EQU     #00080C2
 4114             =~laEgRQRI      EQU     #000B0C2
 4115             =~laEgRQRIk1    EQU     #000D0C2
 4116             =~laEgRSchur    EQU     #00090C2
 4117             =~laEgRWilk3    EQU     #000E0C2
 4118             =~laEgRotR      EQU     #00130C2
 4119             =~laEgSclCls    EQU     #00190C2
 4120             =~laEgValr      EQU     #00120C2
 4121             =~laEgVcPair    EQU     #00180C2
 4122             =~laEgVcSngl    EQU     #00160C2
 4123             =~laEgVcUrhs    EQU     #00170C2
 4124             =~laEgVecC      EQU     #001D0C2
 4125             =~laEgVecR      EQU     #00150C2
 4126             =~laEgWilk2     EQU     #00100C2
 4127             =~laFPMUTE      EQU     #001F0C2
 4128             =~laFSCALE      EQU     #00210C2
 4129             =~laGPROW       EQU     #001B0C3
 4130             =~laINSROW      EQU     #001A0C3
 4131             =~laIV          EQU     #00550C2
 4132             =~laIVF         EQU     #00570C2
 4133             =~laIVc         EQU     #00560C2
 4134             =~laLSQ         EQU     #00220C2 ~_fp_
 4135             =~laLsdScale    EQU     #00590C2
 4136             =~laQ2hX        EQU     #002B0C2
 4137             =~laQRF         EQU     #00260C2
 4138             =~laQRSVecUp    EQU     #002E0C2
 4139             =~laQRmaxSV     EQU     #00300C2
 4140             =~laQRminSV     EQU     #002F0C2
 4141             =~laQRrank      EQU     #002D0C2
 4142             =~laQhA         EQU     #00270C2
 4143             =~laQhB         EQU     #00280C2
 4144             =~laRANK        EQU     #00360C2 ~_fp_
 4145             =~laRANM        EQU     #00000C3 ~_fp_
 4146             =~laRCI         EQU     #00050C3 ~_fp_
 4147             =~laRCIJ        EQU     #00060C3 ~_fp_
 4148             =~laROW>        EQU     #00150C3 ~_fp_
 4149             =~laRQF         EQU     #002A0C2
 4150             =~laRREF        EQU     #005B0C2 ~_fp_
 4151             =~laRSVF        EQU     #002C0C2
 4152             =~laRSWP        EQU     #00020C3 ~_fp_
 4153             =~laRSWP2       EQU     #00030C3
 4154             =~laRanInt      EQU     #00010C3 ~_fp_
 4155             =~laRedHere?    EQU     #005D0C2
 4156             =~laRedRow      EQU     #005C0C2
 4157             =~laRefineDT    EQU     #00520C2
 4158             =~laSCHUR       EQU     #00050C2 ~_fp_
 4159             =~laSETDIAG     EQU     #00290C2
 4160             =~laSNORM       EQU     #00340C2 ~_fp_
 4161             =~laSNORM%%     EQU     #00350C2
 4162             =~laSRAD        EQU     #00000C2 ~_fp_
 4163             =~laSV          EQU     #00530C2
 4164             =~laSVD         EQU     #00380C2 ~_fp_
 4165             =~laSVL         EQU     #00370C2 ~_fp_
 4166             =~laSVc         EQU     #00540C2
 4167             =~laScIntRnd    EQU     #005A0C2
 4168             =~laSchur2      EQU     #00140C2
 4169             =~laSvdAPPhV    EQU     #003C0C2
 4170             =~laSvdAPk      EQU     #003D0C2
 4171             =~laSvdBDQR     EQU     #003F0C2
 4172             =~laSvdBDirC    EQU     #00420C2
 4173             =~laSvdCROTL    EQU     #00490C2
 4174             =~laSvdCROTR    EQU     #00480C2
 4175             =~laSvdFDirC    EQU     #00410C2
 4176             =~laSvdGPROT    EQU     #003E0C2
 4177             =~laSvdGShft    EQU     #00430C2
 4178             =~laSvdLtUBD    EQU     #003A0C2
 4179             =~laSvdPSort    EQU     #004A0C2
 4180             =~laSvdPrep     EQU     #004B0C2
 4181             =~laSvdQR2x2    EQU     #00400C2
 4182             =~laSvdQRB      EQU     #00470C2
 4183             =~laSvdQRF      EQU     #00460C2
 4184             =~laSvdQRSB     EQU     #00450C2
 4185             =~laSvdQRSF     EQU     #00440C2
 4186             =~laSvdUBD      EQU     #00390C2
 4187             =~laSvdUQhQA    EQU     #003B0C2
 4188             =~laTRACE       EQU     #004C0C2 ~_fp_
 4189             =~laULHSVF      EQU     #00580C2
 4190             =~laUserLQ      EQU     #00240C2 ~_fp_
 4191             =~laUserLU      EQU     #00500C2 ~_fp_
 4192             =~laUserQR      EQU     #00230C2 ~_fp_
 4193             =~laVMAX%%      EQU     #00010C2
 4194             =~laVMAXJRP     EQU     #004F0C2
 4195             =~laVec-        EQU     #00080C3
 4196             =~lauserQR      EQU     #00250C2
 4197             =~lolatorre     EQU     #00160E8
 4198             =~lslatorre     EQU     #00150E8
 4199             =~m->DEFACOS    EQU     #00680F0
 4200             =~m->DEFACOSH   EQU     #006E0F0
 4201             =~m->DEFASIN    EQU     #00670F0
 4202             =~m->DEFASINH   EQU     #006D0F0
 4203             =~m->DEFATAN    EQU     #00690F0
 4204             =~m->DEFATANH   EQU     #006F0F0
 4205             =~m->DEFCOS     EQU     #00650F0
 4206             =~m->DEFCOSH    EQU     #006B0F0
 4207             =~m->DEFSIN     EQU     #00640F0
 4208             =~m->DEFSINH    EQU     #006A0F0
 4209             =~m->DEFTAN     EQU     #00660F0
 4210             =~m->DEFTANH    EQU     #006C0F0
 4211             =~m->TRG        EQU     #00630F0
 4212             =~m->[]<-*/     EQU     #005E0F0
 4213             =~m->[]<-+-     EQU     #005D0F0
 4214             =~m-[]*         EQU     #003F0F0
 4215             =~m-[]+         EQU     #00410F0
 4216             =~m-[]-         EQU     #00420F0
 4217             =~m-[]/         EQU     #00400F0
 4218             =~m-[]L         EQU     #003E0F0
 4219             =~m1/[]*        EQU     #003A0F0
 4220             =~m1/[]/        EQU     #003B0F0
 4221             =~m1/[]E        EQU     #003D0F0
 4222             =~m1/[]^        EQU     #003C0F0
 4223             =~m<->*         EQU     #00210F0
 4224             =~m<->+         EQU     #001F0F0
 4225             =~m<->-         EQU     #00200F0
 4226             =~m<->/         EQU     #00220F0
 4227             =~m<-A-+        EQU     #00230F0
 4228             =~m<-A--        EQU     #00240F0
 4229             =~m<-A/*        EQU     #00250F0
 4230             =~m<-A//        EQU     #00260F0
 4231             =~m<-A^*        EQU     #00270F0
 4232             =~m<-M*E        EQU     #00500F0
 4233             =~m<-M*^        EQU     #004E0F0
 4234             =~m<-M+*        EQU     #00490F0
 4235             =~m<-M+L        EQU     #00520F0
 4236             =~m<-M-*        EQU     #004A0F0
 4237             =~m<-M-L        EQU     #00530F0
 4238             =~m<-M/E        EQU     #00510F0
 4239             =~m<-M/^        EQU     #004F0F0
 4240             =~m<-T*/        EQU     #00580F0
 4241             =~m<-T+-        EQU     #00570F0
 4242             =~m<-T=         EQU     #001B0F0
 4243             =~m<-[*/        EQU     #005A0F0
 4244             =~m<-[+-        EQU     #00590F0
 4245             =~m<T>*         EQU     #00560F0
 4246             =~m<T>+         EQU     #00550F0
 4247             =~mA->*/        EQU     #002A0F0
 4248             =~mA->+-        EQU     #00280F0
 4249             =~mA->--        EQU     #00290F0
 4250             =~mA->//        EQU     #002B0F0
 4251             =~mA->^^        EQU     #002C0F0
 4252             =~mAFlq         EQU     #001C0F0
 4253             =~mAFqq         EQU     #001D0F0
 4254             =~mAFrq         EQU     #001E0F0
 4255             =~mCONJ[]       EQU     #005F0F0
 4256             =~mCOS+         EQU     #00710F0
 4257             =~mCOSH+        EQU     #00740F0
 4258             =~mD->/+        EQU     #002D0F0
 4259             =~mD->/-        EQU     #002E0F0
 4260             =~mD->E+        EQU     #00310F0
 4261             =~mD->E-        EQU     #00320F0
 4262             =~mD->L*        EQU     #00330F0
 4263             =~mD->L/        EQU     #00340F0
 4264             =~mD->^+        EQU     #002F0F0
 4265             =~mD->^-        EQU     #00300F0
 4266             =~mE[]^         EQU     #00450F0
 4267             =~mE^*          EQU     #00430F0
 4268             =~mE^/          EQU     #00440F0
 4269             =~mIM[]         EQU     #00610F0
 4270             =~mL*^          EQU     #00460F0
 4271             =~mL[]*         EQU     #00470F0
 4272             =~mL[]/         EQU     #00480F0
 4273             =~mM->op        EQU     #00540F0
 4274             =~mRE[]         EQU     #00600F0
 4275             =~mSIN+         EQU     #00700F0
 4276             =~mSINH+        EQU     #00730F0
 4277             =~mT->=         EQU     #001A0F0
 4278             =~mTAN+         EQU     #00720F0
 4279             =~mTANH+        EQU     #00750F0
 4280             =~m[]CHS*       EQU     #00350F0
 4281             =~m[]CHS/       EQU     #00360F0
 4282             =~m[]CHSL       EQU     #00370F0
 4283             =~m[]INVE       EQU     #00390F0
 4284             =~m[]INV^       EQU     #00380F0
 4285             =~m]->*/        EQU     #005C0F0
 4286             =~m]->+-        EQU     #005B0F0
 4287             =~metapolyz     EQU     #005E0AB
 4288             =~morerepl      EQU     #00240E8
 4289             =~moresub       EQU     #00230E8
 4290             =~mrepll        EQU     #00260E8
 4291             =~mrepll+       EQU     #00270E8
 4292             =~mrepln        EQU     #00250E8
 4293             =~msubll        EQU     #002A0E8
 4294             =~msubll+       EQU     #002B0E8
 4295             =~msubln        EQU     #00280E8
 4296             =~msubnl        EQU     #00290E8
 4297             =~msubnn        EQU     #002C0E8
 4298             =~nBOXWHISKER   EQU     #00070F1
 4299             =~nFUNCTION     EQU     #00000F1
 4300             =~nFUNCTOPIC    EQU     #000F0F1
 4301             =~nHISTOGRAM    EQU     #00050F1
 4302             =~nPARAMETRIC   EQU     #00030F1
 4303             =~nPARAMTOPIC   EQU     #00110F1
 4304             =~nPOLAR        EQU     #00020F1
 4305             =~nPOLARTOPIC   EQU     #00100F1
 4306             =~nPTYPE>PINF   EQU     #00220F1
 4307             =~nSCATTER      EQU     #00040F1
 4308             =~nSEQTOPIC     EQU     #00120F1
 4309             =~nSEQUENCE     EQU     #00060F1
 4310             =~nSOLVE        EQU     #00010F1
 4311             =~nSOLVETOPIC   EQU     #00140F1
 4312             =~nSTATTOPIC    EQU     #00130F1
 4313             =~ns*spec       EQU     #00660AB
 4314             =~ollatorre     EQU     #00170E8
 4315             =~ollatorre+    EQU     #00180E8
 4316             =~pcoef         EQU     #00040C0 ~_fp_
 4317             =~pcoefacc1     EQU     #00050C0
 4318             =~pcoefacc2     EQU     #00060C0
 4319             =~pdiv          EQU     #006C0AB
 4320             =~peval         EQU     #00030C0 ~_fp_
 4321             =~poly*         EQU     #00620AB
 4322             =~poly+         EQU     #00600AB
 4323             =~poly/         EQU     #006E0AB
 4324             =~poly^         EQU     #00680AB
 4325             =~poly^#        EQU     #006A0AB
 4326             =~polyneg       EQU     #00610AB
 4327             =~polyprep      EQU     #005F0AB
 4328             =~preFACT       EQU     #002A002
 4329             =~proot         EQU     #00010C0 ~_fp_
 4330             =~proot_c       EQU     #00000C0
 4331             =~proot_r       EQU     #00020C0
 4332             =~ptrargs       EQU     #00070E8 ~_fp_
 4333             =~rMAKEPCOPY    EQU     #00310C2
 4334             =~rPACKARRYD    EQU     #00320C2
 4335             =~resymb        EQU     #006D0AB
 4336             =~rpnAPPLY      EQU     #0081002
 4337             =~rpnDER        EQU     #007E002
 4338             =~rpnINTG       EQU     #007F002
 4339             =~rpnWHERE      EQU     #0080002
 4340             =~rpnXROOT      EQU     #0076002
 4341             =~runalias?     EQU     #002A0F1
 4342             =~seqid         EQU     #00050E8 ~_fp_
 4343             =~seqnargs      EQU     #000E0E8
 4344             =~sllatorre     EQU     #00140E8
 4345             =~sn*spec       EQU     #00650AB
 4346             =~ss*spec       EQU     #00670AB
 4347             =~topic_CAPLE   EQU     #003B0F1 partial match
 4348             =~topic_NONE    EQU     #00340F1
 4349             =~udfargs       EQU     #00090E8
 4350             =~view01_CAPL   EQU     #00360F1 partial match
 4351             =~view23_CAPL   EQU     #00370F1 partial match
 4352             =~view45_CAPL   EQU     #00380F1 partial match
 4353             =~view6_CAPLE   EQU     #00390F1 partial match
 4354             =~view7_CAPLE   EQU     #003A0F1 partial match
 4355             =~view_NONE     EQU     #00350F1
 4356             =~x#?           EQU     #0062002
 4357             =~x%            EQU     #003F002
 4358             =~x%CH          EQU     #0041002
 4359             =~x%T           EQU     #0040002
 4360             =~x'            EQU     #000E700
 4361             =~x*            EQU     #000D002
 4362             =~x+            EQU     #000A002
 4363             =~x-            EQU     #000C002
 4364             =~x->Q          EQU     #0085002
 4365             =~x->QPI        EQU     #0086002
 4366             =~x->TAG        EQU     #008A004 ~_fp_
 4367             =~x/            EQU     #000E002
 4368             =~x<            EQU     #0045002
 4369             =~x<<           EQU     #000C700
 4370             =~x<=?          EQU     #0063002
 4371             =~x=            EQU     #0001002
 4372             =~x==           EQU     #0047002
 4373             =~x>            EQU     #0046002
 4374             =~x>=?          EQU     #0064002
 4375             =~x>>           EQU     #000D700
 4376             =~x>ARRY        EQU     #003B004 ~_fp_
 4377             =~x>COL         EQU     #003F0AB
 4378             =~x>DIAG        EQU     #00410AB
 4379             =~x>DISPLAY     EQU     #0061004
 4380             =~x>GROB        EQU     #0065004
 4381             =~x>HMS         EQU     #0038002
 4382             =~x>LIST        EQU     #002D004
 4383             =~x>NUM         EQU     #0070002
 4384             =~x>PLOT        EQU     #0063004
 4385             =~x>ROW         EQU     #003D0AB
 4386             =~x>STR         EQU     #0033004
 4387             =~x>UNIT        EQU     #0017004
 4388             =~x>V2          EQU     #0044004
 4389             =~x>V3          EQU     #0045004
 4390             =~xABS          EQU     #0003002
 4391             =~xACOS         EQU     #001E002
 4392             =~xACOSH        EQU     #0021002
 4393             =~xACOT         EQU     #00350AB
 4394             =~xACSC         EQU     #00360AB
 4395             =~xALG->        EQU     #0004700
 4396             =~xALOG         EQU     #0026002
 4397             =~xAND          EQU     #005E002
 4398             =~xAPPLY        EQU     #0053002
 4399             =~xARC          EQU     #0066004
 4400             =~xARG          EQU     #0013002
 4401             =~xARRY>        EQU     #003C004
 4402             =~xASEC         EQU     #00370AB
 4403             =~xASIN         EQU     #001D002
 4404             =~xASINH        EQU     #0020002
 4405             =~xASN          EQU     #0086004
 4406             =~xASR          EQU     #000A004
 4407             =~xATAN         EQU     #001F002
 4408             =~xATANH        EQU     #0022002
 4409             =~xAUTO         EQU     #004B004
 4410             =~xAngle        EQU     #00E40F2
 4411             =~xAns          EQU     #00DB0F2
 4412             =~xArea         EQU     #01140F2
 4413             =~xAxes         EQU     #00E50F2
 4414             =~xB>R          EQU     #0014004
 4415             =~xBEEP         EQU     #006F002
 4416             =~xBLANK        EQU     #005C004
 4417             =~xBLANKGROB    EQU     #0064004
 4418             =~xBOX          EQU     #005B004
 4419             =~xBOXW         EQU     #00250AB
 4420             =~xBYTES        EQU     #0024004
 4421             =~xC>PX         EQU     #0052004
 4422             =~xC>R          EQU     #0032004
 4423             =~xCASE         EQU     #0012700
 4424             =~xCEIL         EQU     #002E002
 4425             =~xCENTR        EQU     #0048004
 4426             =~xCF           EQU     #0026004
 4427             =~xCHECK        EQU     #003D701
 4428             =~xCHOOSE       EQU     #004E0AB
 4429             =~xCHR          EQU     #0036004
 4430             =~xCLEAR        EQU     #0077004
 4431             =~xCLKADJ       EQU     #001F004
 4432             =~xCLLCD        EQU     #0073002
 4433             =~xCNRM         EQU     #003B002
 4434             =~xCOBWEB       EQU     #00230AB
 4435             =~xCOL+         EQU     #00460AB
 4436             =~xCOL-         EQU     #00450AB
 4437             =~xCOL>         EQU     #00400AB
 4438             =~xCOLCT        EQU     #008A002
 4439             =~xCOMB         EQU     #0043002
 4440             =~xCON          EQU     #003E004 ~_fp_
 4441             =~xCONCAT       EQU     #00170AB
 4442             =~xCOND         EQU     #00010AB
 4443             =~xCONJ         EQU     #0004002
 4444             =~xCONSTANTe    EQU     #0008002
 4445             =~xCONT         EQU     #0075002
 4446             =~xCONVERT      EQU     #0015004
 4447             =~xCORR         EQU     #00B00F2
 4448             =~xCOS          EQU     #0018002
 4449             =~xCOSH         EQU     #001B002
 4450             =~xCOT          EQU     #00320AB
 4451             =~xCOV          EQU     #00B10F2
 4452             =~xCROSS        EQU     #003E002
 4453             =~xCSC          EQU     #00340AB
 4454             =~xCSWP         EQU     #00480AB
 4455             =~xCUBICFIT     EQU     #002B0AB
 4456             =~xConnect      EQU     #00E70F2
 4457             =~xCoord        EQU     #00EE0F2
 4458             =~xD0           EQU     #006D0F2
 4459             =~xD1           EQU     #00640F2
 4460             =~xD2           EQU     #00650F2
 4461             =~xD3           EQU     #00660F2
 4462             =~xD4           EQU     #00670F2
 4463             =~xD5           EQU     #00680F2
 4464             =~xD6           EQU     #00690F2
 4465             =~xD7           EQU     #006A0F2
 4466             =~xD8           EQU     #006B0F2
 4467             =~xD9           EQU     #006C0F2
 4468             =~xD>R          EQU     #0036002
 4469             =~xDATE         EQU     #001B004
 4470             =~xDATE+        EQU     #0022004
 4471             =~xDDAYS        EQU     #0021004
 4472             =~xDECR         EQU     #0080004
 4473             =~xDELKEYS      EQU     #0088004
 4474             =~xDEPTH        EQU     #0071004
 4475             =~xDER          EQU     #004D002
 4476             =~xDET          EQU     #003C002
 4477             =~xDFLTNOTE     EQU     #00320F1
 4478             =~xDFLTPICT     EQU     #00330F1
 4479             =~xDIAG>        EQU     #00420AB
 4480             =~xDIR          EQU     #0014700
 4481             =~xDISP         EQU     #006E002
 4482             =~xDISPLAY>     EQU     #0060004
 4483             =~xDO           EQU     #0007700
 4484             =~xDOERR        EQU     #0067002
 4485             =~xDOLIST       EQU     #00590AB
 4486             =~xDOSUBS       EQU     #00540AB
 4487             =~xDOT          EQU     #003D002
 4488             =~xDRAX         EQU     #004C004
 4489             =~xDROP         EQU     #006D004
 4490             =~xDROP2        EQU     #006E004
 4491             =~xDROPN        EQU     #0072004
 4492             =~xDTAG         EQU     #008B004
 4493             =~xDUP          EQU     #006A004
 4494             =~xDUP2         EQU     #006B004
 4495             =~xDUPN         EQU     #0073004
 4496             =~xDate         EQU     #00E30F2
 4497             =~xDigits       EQU     #01030F2
 4498             =~xE            EQU     #00860F2
 4499             =~xEGV          EQU     #00070AB
 4500             =~xEGVL         EQU     #00080AB
 4501             =~xELSE         EQU     #0002700
 4502             =~xENDDO        EQU     #0010700
 4503             =~xENDSUB       EQU     #00560AB
 4504             =~xENDTIC       EQU     #0019700
 4505             =~xENG          EQU     #00200AB
 4506             =~xEQ>          EQU     #0039004
 4507             =~xERASE        EQU     #004F004
 4508             =~xERASEA       EQU     #0050004
 4509             =~xERR0         EQU     #0068002
 4510             =~xERRM         EQU     #006A002
 4511             =~xERRN         EQU     #0069002
 4512             =~xERRTHEN      EQU     #0011700
 4513             =~xEVAL         EQU     #006B002
 4514             =~xEXP          EQU     #0023002
 4515             =~xEXPAN        EQU     #008B002
 4516             =~xEXPFIT       EQU     #00280AB
 4517             =~xEXPM         EQU     #0028002
 4518             =~xExtremum     EQU     #01130F2
 4519             =~xF0           EQU     #00260F2
 4520             =~xF1           EQU     #00140F2
 4521             =~xF2           EQU     #00160F2
 4522             =~xF3           EQU     #00180F2
 4523             =~xF4           EQU     #001A0F2
 4524             =~xF5           EQU     #001C0F2
 4525             =~xF6           EQU     #001E0F2
 4526             =~xF7           EQU     #00200F2
 4527             =~xF8           EQU     #00220F2
 4528             =~xF9           EQU     #00240F2
 4529             =~xFACT         EQU     #0029002
 4530             =~xFC?          EQU     #0028004
 4531             =~xFC?C         EQU     #002A004
 4532             =~xFCNAPPLY     EQU     #0082002
 4533             =~xFIT          EQU     #00DC0F2
 4534             =~xFIX          EQU     #001E0AB
 4535             =~xFLOOR        EQU     #002D002
 4536             =~xFORMUNIT     EQU     #0089002
 4537             =~xFP           EQU     #002C002
 4538             =~xFRACTION     EQU     #00210AB
 4539             =~xFS?          EQU     #0027004
 4540             =~xFS?C         EQU     #0029004
 4541             =~xFUNCSYMB     EQU     #002B0F1
 4542             =~xFUNCTAB      EQU     #00080F1
 4543             =~xFUNCTION     EQU     #008F002
 4544             =~xFmList       EQU     #0058002
 4545             =~xFmMat        EQU     #0059002
 4546             =~xFormat       EQU     #01020F2
 4547             =~xGET          EQU     #0041004
 4548             =~xGETI         EQU     #0042004
 4549             =~xGOR          EQU     #005E004
 4550             =~xGRAPH        EQU     #0053004
 4551             =~xGXOR         EQU     #005F004
 4552             =~xGrid         EQU     #00E60F2
 4553             =~xH1           EQU     #006E0F2
 4554             =~xH2           EQU     #006F0F2
 4555             =~xH3           EQU     #00700F2
 4556             =~xH4           EQU     #00710F2
 4557             =~xH5           EQU     #00720F2
 4558             =~xHAngle       EQU     #00DD0F2
 4559             =~xHDigits      EQU     #00DF0F2
 4560             =~xHEAD         EQU     #00520AB
 4561             =~xHELP         EQU     #0044701
 4562             =~xHFormat      EQU     #00DE0F2
 4563             =~xHIST         EQU     #00240AB
 4564             =~xHMS+         EQU     #0077002
 4565             =~xHMS-         EQU     #0078002
 4566             =~xHMS>         EQU     #0039002
 4567             =~xHOME         EQU     #0023004
 4568             =~xHTick        EQU     #00F60F2
 4569             =~xHighRes      EQU     #00E80F2
 4570             =~xHisWidth     EQU     #01210F2
 4571             =~xHmax         EQU     #01230F2
 4572             =~xHmin         EQU     #01220F2
 4573             =~xHzoom        EQU     #00F80F2
 4574             =~xI            EQU     #008A0F2
 4575             =~xIDN          EQU     #0002004
 4576             =~xIF           EQU     #0000700
 4577             =~xIFEND        EQU     #0003700
 4578             =~xIFERR        EQU     #000B700
 4579             =~xIFT          EQU     #006C002
 4580             =~xIFTE         EQU     #0000002
 4581             =~xIM           EQU     #004B002
 4582             =~xINCR         EQU     #007F004
 4583             =~xINPUT        EQU     #0085004
 4584             =~xINTEGRAL     EQU     #004F002
 4585             =~xINV          EQU     #0012002
 4586             =~xIP           EQU     #002B002
 4587             =~xISOL         EQU     #005A002
 4588             =~xIerr         EQU     #00E10F2
 4589             =~xIndep        EQU     #00F30F2
 4590             =~xInvCursor    EQU     #00EB0F2
 4591             =~xIsect        EQU     #01120F2
 4592             =~xKEY          EQU     #0074002
 4593             =~xKILL         EQU     #0065002
 4594             =~xLABEL        EQU     #0054004
 4595             =~xLAST         EQU     #0071002
 4596             =~xLINE         EQU     #0059004
 4597             =~xLINFIT       EQU     #00260AB
 4598             =~xLININ        EQU     #00000AB
 4599             =~xLIST>        EQU     #0031004
 4600             =~xLN           EQU     #0024002
 4601             =~xLNP1         EQU     #0027002
 4602             =~xLOG          EQU     #0025002
 4603             =~xLOGFIT       EQU     #00270AB
 4604             =~xLOGISFIT     EQU     #002C0AB
 4605             =~xLQ           EQU     #000D0AB
 4606             =~xLSQ          EQU     #00060AB
 4607             =~xLU           EQU     #000B0AB
 4608             =~xLabels       EQU     #00EC0F2
 4609             =~xMANT         EQU     #0035002
 4610             =~xMATCHDN      EQU     #0088002
 4611             =~xMATCHUP      EQU     #0087002
 4612             =~xMAX          EQU     #0030002
 4613             =~xMAXR         EQU     #0006002
 4614             =~xMAXS         EQU     #00A50F2
 4615             =~xMEANS        EQU     #009D0F2
 4616             =~xMEANX        EQU     #00A90F2
 4617             =~xMEANY        EQU     #00AC0F2
 4618             =~xMEDIAN       EQU     #00A60F2
 4619             =~xMEM          EQU     #0084004
 4620             =~xMIN          EQU     #0031002
 4621             =~xMINR         EQU     #0007002
 4622             =~xMINS         EQU     #00A40F2
 4623             =~xMKMAT        EQU     #00310AB
 4624             =~xMOD          EQU     #0034002
 4625             =~xMSGBOX       EQU     #004F0AB
 4626             =~xNEG          EQU     #0002002
 4627             =~xNEGNEG       EQU     #000B002
 4628             =~xNEXT         EQU     #0016700
 4629             =~xNOT          EQU     #0060002
 4630             =~xNS           EQU     #00A30F2
 4631             =~xNSUB         EQU     #00550AB
 4632             =~xNUM          EQU     #0035004
 4633             =~xNmax         EQU     #011D0F2
 4634             =~xNmin         EQU     #011C0F2
 4635             =~xNoteText     EQU     #01040F2
 4636             =~xNumCol       EQU     #01000F2
 4637             =~xNumFont      EQU     #01010F2
 4638             =~xNumIndep     EQU     #00FD0F2
 4639             =~xNumRow       EQU     #00FF0F2
 4640             =~xNumStart     EQU     #00FA0F2
 4641             =~xNumStep      EQU     #00FB0F2
 4642             =~xNumType      EQU     #00FC0F2
 4643             =~xNumZoom      EQU     #00FE0F2
 4644             =~xOBJ>         EQU     #003A004 ~_fp_
 4645             =~xOFF          EQU     #0066002
 4646             =~xOR           EQU     #005F002
 4647             =~xOVER         EQU     #0070004
 4648             =~xPARAMETRIC   EQU     #0091002
 4649             =~xPARAMSYMB    EQU     #002D0F1
 4650             =~xPARAMTAB     EQU     #000A0F1
 4651             =~xPCOEF        EQU     #00110AB
 4652             =~xPDIM         EQU     #004E004
 4653             =~xPERM         EQU     #0044002
 4654             =~xPEVAL        EQU     #00120AB
 4655             =~xPI           EQU     #0005002
 4656             =~xPICK         EQU     #0074004
 4657             =~xPICT         EQU     #005D004
 4658             =~xPINIT        EQU     #003F701
 4659             =~xPIX?         EQU     #0058004
 4660             =~xPIXOFF       EQU     #0057004
 4661             =~xPIXON        EQU     #0056004
 4662             =~xPLOT>        EQU     #0062004
 4663             =~xPMAX         EQU     #0047004
 4664             =~xPMIN         EQU     #0046004
 4665             =~xPOLAR        EQU     #0090002
 4666             =~xPOLARSYMB    EQU     #002C0F1
 4667             =~xPOLARTAB     EQU     #00090F1
 4668             =~xPOLYFORM     EQU     #00390AB
 4669             =~xPOWERFIT     EQU     #00290AB
 4670             =~xPREDIV       EQU     #0057002
 4671             =~xPREDX        EQU     #0005004
 4672             =~xPREDY        EQU     #0004004
 4673             =~xPROOT        EQU     #00100AB
 4674             =~xPSDEV        EQU     #00A20F2
 4675             =~xPURGE        EQU     #0083004
 4676             =~xPUT          EQU     #003F004
 4677             =~xPUTI         EQU     #0040004
 4678             =~xPVARS        EQU     #00A00F2
 4679             =~xPVIEW        EQU     #0055004
 4680             =~xPX>C         EQU     #0051004
 4681             =~xPage         EQU     #01050F2
 4682             =~xPageNum      EQU     #01060F2
 4683             =~xPoly         EQU     #005A0AB
 4684             =~xQ1           EQU     #00A70F2
 4685             =~xQ3           EQU     #00A80F2
 4686             =~xQR           EQU     #000C0AB
 4687             =~xQUAD         EQU     #005B002
 4688             =~xQUADFIT      EQU     #002A0AB
 4689             =~xQUOTE        EQU     #0052002
 4690             =~xR0           EQU     #00620F2
 4691             =~xR1           EQU     #00500F2
 4692             =~xR2           EQU     #00520F2
 4693             =~xR3           EQU     #00540F2
 4694             =~xR4           EQU     #00560F2
 4695             =~xR5           EQU     #00580F2
 4696             =~xR6           EQU     #005A0F2
 4697             =~xR7           EQU     #005C0F2
 4698             =~xR8           EQU     #005E0F2
 4699             =~xR9           EQU     #00600F2
 4700             =~xR>B          EQU     #0013004
 4701             =~xR>C          EQU     #002E004
 4702             =~xR>D          EQU     #0037002
 4703             =~xRAND         EQU     #0042002
 4704             =~xRANK         EQU     #00050AB
 4705             =~xRANM         EQU     #003C0AB
 4706             =~xRCI          EQU     #00490AB
 4707             =~xRCIJ         EQU     #004A0AB
 4708             =~xRCL          EQU     #0081004
 4709             =~xRCLF         EQU     #002B004
 4710             =~xRCLKEYS      EQU     #0089004
 4711             =~xRDM          EQU     #003D004
 4712             =~xRDZ          EQU     #007A002
 4713             =~xRE           EQU     #004A002
 4714             =~xREADNOTE     EQU     #003C0F1
 4715             =~xREADPICT     EQU     #003D0F1
 4716             =~xRECURSE      EQU     #00380AB
 4717             =~xRELERR       EQU     #00B20F2
 4718             =~xREPEAT       EQU     #0006700
 4719             =~xREPL         EQU     #0030004
 4720             =~xREVLIST      EQU     #00180AB
 4721             =~xRL           EQU     #000B004
 4722             =~xRLB          EQU     #000C004
 4723             =~xRND          EQU     #0032002
 4724             =~xRNRM         EQU     #003A002
 4725             =~xROLL         EQU     #0075004
 4726             =~xROLLD        EQU     #0076004
 4727             =~xROOT         EQU     #004E002
 4728             =~xROT          EQU     #006F004
 4729             =~xROW+         EQU     #00440AB
 4730             =~xROW-         EQU     #00430AB
 4731             =~xROW>         EQU     #003E0AB
 4732             =~xRPN->        EQU     #0018700
 4733             =~xRR           EQU     #000D004
 4734             =~xRRB          EQU     #000E004
 4735             =~xRREF         EQU     #000F0AB
 4736             =~xRSD          EQU     #0079002
 4737             =~xRSWP         EQU     #00470AB
 4738             =~xRULES        EQU     #008C002
 4739             =~xRadixMark    EQU     #00E00F2
 4740             =~xRecenter     EQU     #00EA0F2
 4741             =~xRoot         EQU     #01110F2
 4742             =~xS1           EQU     #00730F2
 4743             =~xS1fit        EQU     #01290F2
 4744             =~xS1mark       EQU     #01240F2
 4745             =~xS2           EQU     #00740F2
 4746             =~xS2fit        EQU     #012A0F2
 4747             =~xS2mark       EQU     #01250F2
 4748             =~xS3           EQU     #00750F2
 4749             =~xS3fit        EQU     #012B0F2
 4750             =~xS3mark       EQU     #01260F2
 4751             =~xS4           EQU     #00760F2
 4752             =~xS4fit        EQU     #012C0F2
 4753             =~xS4mark       EQU     #01270F2
 4754             =~xS5           EQU     #00770F2
 4755             =~xS5fit        EQU     #012D0F2
 4756             =~xS5mark       EQU     #01280F2
 4757             =~xSAME         EQU     #005D002
 4758             =~xSCALE        EQU     #004D004
 4759             =~xSCHUR        EQU     #000E0AB
 4760             =~xSCI          EQU     #001F0AB
 4761             =~xSCONJ        EQU     #007A004
 4762             =~xSEC          EQU     #00330AB
 4763             =~xSEQ          EQU     #00130AB
 4764             =~xSEQSYMB      EQU     #002E0F1
 4765             =~xSEQTAB       EQU     #000B0F1
 4766             =~xSETDATE      EQU     #001D004
 4767             =~xSETTIME      EQU     #001E004
 4768             =~xSF           EQU     #0025004
 4769             =~xSHOW         EQU     #008E002
 4770             =~xSIGN         EQU     #0014002
 4771             =~xSILENT'      EQU     #0017700
 4772             =~xSIN          EQU     #0017002
 4773             =~xSINH         EQU     #001A002
 4774             =~xSINV         EQU     #0078004
 4775             =~xSL           EQU     #000F004
 4776             =~xSLB          EQU     #0010004
 4777             =~xSNEG         EQU     #0079004
 4778             =~xSNRM         EQU     #00040AB
 4779             =~xSOLVESYMB    EQU     #00310F1
 4780             =~xSOLVETAB     EQU     #000E0F1
 4781             =~xSORT         EQU     #00190AB
 4782             =~xSQ           EQU     #0016002
 4783             =~xSQRT         EQU     #0015002
 4784             =~xSR           EQU     #0011004
 4785             =~xSRAD         EQU     #00030AB
 4786             =~xSRB          EQU     #0012004
 4787             =~xSSDEV        EQU     #00A10F2
 4788             =~xSTAIRSTEP    EQU     #00220AB
 4789             =~xSTART        EQU     #0015700
 4790             =~xSTARTVAR     EQU     #0009700
 4791             =~xSTAT2SYMB    EQU     #00300F1
 4792             =~xSTAT2TAB     EQU     #000D0F1
 4793             =~xSTATSYMB     EQU     #002F0F1
 4794             =~xSTATTAB      EQU     #000C0F1
 4795             =~xSTD          EQU     #001D0AB
 4796             =~xSTEP         EQU     #000A700
 4797             =~xSTO          EQU     #0082004
 4798             =~xSTO*         EQU     #007E004
 4799             =~xSTO+         EQU     #007B004
 4800             =~xSTO-         EQU     #007C004
 4801             =~xSTO/         EQU     #007D004
 4802             =~xSTOF         EQU     #002C004
 4803             =~xSTOKEYS      EQU     #0087004
 4804             =~xSTR>         EQU     #0034004
 4805             =~xSTREAM       EQU     #00570AB
 4806             =~xSUB          EQU     #002F004
 4807             =~xSUM          EQU     #0050002
 4808             =~xSVARS        EQU     #009F0F2
 4809             =~xSVD          EQU     #00090AB
 4810             =~xSVL          EQU     #000A0AB
 4811             =~xSWAP         EQU     #006C004
 4812             =~xSX           EQU     #00AA0F2
 4813             =~xSX2          EQU     #00AB0F2
 4814             =~xSXY          EQU     #00AF0F2
 4815             =~xSY           EQU     #00AD0F2
 4816             =~xSY2          EQU     #00AE0F2
 4817             =~xSYSEVAL      EQU     #006D002
 4818             =~xSeqPlot      EQU     #011E0F2
 4819             =~xSimult       EQU     #00E90F2
 4820             =~xSlope        EQU     #01150F2
 4821             =~xStat1Var     EQU     #002E0AB
 4822             =~xStat2Var     EQU     #002F0AB
 4823             =~xStatMode     EQU     #011F0F2
 4824             =~xStatPlot     EQU     #01200F2
 4825             =~xTAIL         EQU     #00530AB
 4826             =~xTAN          EQU     #0019002
 4827             =~xTANH         EQU     #001C002
 4828             =~xTAYLR        EQU     #005C002
 4829             =~xTEXT         EQU     #0067004
 4830             =~xTHEN         EQU     #0001700
 4831             =~xTHENCASE     EQU     #0013700
 4832             =~xTIME         EQU     #001A004
 4833             =~xTLINE        EQU     #005A004
 4834             =~xTOTS         EQU     #009E0F2
 4835             =~xTRACE        EQU     #00020AB
 4836             =~xTRN          EQU     #0003004
 4837             =~xTRNC         EQU     #0033002
 4838             =~xTSTR         EQU     #0020004
 4839             =~xTStep        EQU     #01180F2
 4840             =~xTYPE         EQU     #0037004
 4841             =~xThetaMax     EQU     #011A0F2
 4842             =~xThetaMin     EQU     #01190F2
 4843             =~xThetaStep    EQU     #011B0F2
 4844             =~xTime         EQU     #00E20F2
 4845             =~xTmax         EQU     #01170F2
 4846             =~xTmin         EQU     #01160F2
 4847             =~xTracing      EQU     #00ED0F2
 4848             =~xU0           EQU     #00120F2
 4849             =~xU1           EQU     #00000F2
 4850             =~xU2           EQU     #00020F2
 4851             =~xU3           EQU     #00040F2
 4852             =~xU4           EQU     #00060F2
 4853             =~xU5           EQU     #00080F2
 4854             =~xU6           EQU     #000A0F2
 4855             =~xU7           EQU     #000C0F2
 4856             =~xU8           EQU     #000E0F2
 4857             =~xU9           EQU     #00100F2
 4858             =~xUBASE        EQU     #0018004
 4859             =~xUFACT        EQU     #0019004
 4860             =~xUNCHECK      EQU     #003E701
 4861             =~xUNTIL        EQU     #0008700
 4862             =~xUSERFIT      EQU     #002D0AB
 4863             =~xUTPC         EQU     #0006004
 4864             =~xUTPF         EQU     #0008004
 4865             =~xUTPN         EQU     #0007004
 4866             =~xUTPT         EQU     #0009004
 4867             =~xUVAL         EQU     #0016004
 4868             =~xUndefined    EQU     #001E0F1
 4869             =~xV>           EQU     #0043004
 4870             =~xVERSION      EQU     #003A0AB
 4871             =~xVTYPE        EQU     #0038004
 4872             =~xVTick        EQU     #00F70F2
 4873             =~xVzoom        EQU     #00F90F2
 4874             =~xWAIT         EQU     #0072002
 4875             =~xWHERE        EQU     #0051002
 4876             =~xWHILE        EQU     #0005700
 4877             =~xWHILEEND     EQU     #000F700
 4878             =~xWSLOG        EQU     #001C004
 4879             =~xX0           EQU     #004C0F2
 4880             =~xX1           EQU     #00280F2
 4881             =~xX2           EQU     #002C0F2
 4882             =~xX3           EQU     #00300F2
 4883             =~xX4           EQU     #00340F2
 4884             =~xX5           EQU     #00380F2
 4885             =~xX6           EQU     #003C0F2
 4886             =~xX7           EQU     #00400F2
 4887             =~xX8           EQU     #00440F2
 4888             =~xX9           EQU     #00480F2
 4889             =~xXOR          EQU     #0061002
 4890             =~xXPON         EQU     #002F002
 4891             =~xXRECV        EQU     #00510AB
 4892             =~xXRNG         EQU     #0068004
 4893             =~xXROOT        EQU     #0010002
 4894             =~xXSEND        EQU     #00500AB
 4895             =~xXcross       EQU     #00F40F2
 4896             =~xXmax         EQU     #00F00F2
 4897             =~xXmin         EQU     #00EF0F2
 4898             =~xY0           EQU     #004E0F2
 4899             =~xY1           EQU     #002A0F2
 4900             =~xY2           EQU     #002E0F2
 4901             =~xY3           EQU     #00320F2
 4902             =~xY4           EQU     #00360F2
 4903             =~xY5           EQU     #003A0F2
 4904             =~xY6           EQU     #003E0F2
 4905             =~xY7           EQU     #00420F2
 4906             =~xY8           EQU     #00460F2
 4907             =~xY9           EQU     #004A0F2
 4908             =~xYRNG         EQU     #0069004
 4909             =~xYcross       EQU     #00F50F2
 4910             =~xYmax         EQU     #00F20F2
 4911             =~xYmin         EQU     #00F10F2
 4912             =~x\85LIST      EQU     #00150AB
 4913             =~x\9BLIST      EQU     #00140AB
 4914             =~x\9CLIST      EQU     #00160AB
 4915             =~x^            EQU     #000F002
 4916             =~xa            EQU     #00820F2
 4917             =~xb            EQU     #00830F2
 4918             =~xc            EQU     #00840F2
 4919             =~xd            EQU     #00850F2
 4920             =~xf            EQU     #00870F2
 4921             =~xg            EQU     #00880F2
 4922             =~xg0           EQU     #00D10F2
 4923             =~xg1           EQU     #00D20F2
 4924             =~xg2           EQU     #00D30F2
 4925             =~xg3           EQU     #00D40F2
 4926             =~xg4           EQU     #00D50F2
 4927             =~xg5           EQU     #00D60F2
 4928             =~xg6           EQU     #00D70F2
 4929             =~xg7           EQU     #00D80F2
 4930             =~xg8           EQU     #00D90F2
 4931             =~xg9           EQU     #00DA0F2
 4932             =~xh            EQU     #00890F2
 4933             =~xi            EQU     #0009002
 4934             =~xj            EQU     #008B0F2
 4935             =~xk            EQU     #008C0F2
 4936             =~xl            EQU     #008D0F2
 4937             =~xl0           EQU     #00C70F2
 4938             =~xl1           EQU     #00C80F2
 4939             =~xl2           EQU     #00C90F2
 4940             =~xl3           EQU     #00CA0F2
 4941             =~xl4           EQU     #00CB0F2
 4942             =~xl5           EQU     #00CC0F2
 4943             =~xl6           EQU     #00CD0F2
 4944             =~xl7           EQU     #00CE0F2
 4945             =~xl8           EQU     #00CF0F2
 4946             =~xl9           EQU     #00D00F2
 4947             =~xm            EQU     #008E0F2
 4948             =~xm0           EQU     #00BD0F2
 4949             =~xm1           EQU     #00BE0F2
 4950             =~xm2           EQU     #00BF0F2
 4951             =~xm3           EQU     #00C00F2
 4952             =~xm4           EQU     #00C10F2
 4953             =~xm5           EQU     #00C20F2
 4954             =~xm6           EQU     #00C30F2
 4955             =~xm7           EQU     #00C40F2
 4956             =~xm8           EQU     #00C50F2
 4957             =~xm9           EQU     #00C60F2
 4958             =~xn            EQU     #008F0F2
 4959             =~xn1           EQU     #007D0F2
 4960             =~xn2           EQU     #007E0F2
 4961             =~xn3           EQU     #007F0F2
 4962             =~xn4           EQU     #00800F2
 4963             =~xn5           EQU     #00810F2
 4964             =~xo            EQU     #00900F2
 4965             =~xp            EQU     #00910F2
 4966             =~xq            EQU     #00920F2
 4967             =~xr            EQU     #00930F2
 4968             =~xs            EQU     #00940F2
 4969             =~xs1           EQU     #00780F2
 4970             =~xs2           EQU     #00790F2
 4971             =~xs3           EQU     #007A0F2
 4972             =~xs4           EQU     #007B0F2
 4973             =~xs5           EQU     #007C0F2
 4974             =~xt            EQU     #00950F2
 4975             =~xtheta        EQU     #009C0F2
 4976             =~xu            EQU     #00960F2
 4977             =~xv            EQU     #00970F2
 4978             =~xw            EQU     #00980F2
 4979             =~xx            EQU     #00990F2
 4980             =~xx>DISPLAY    EQU     #0014701
 4981             =~xx>GROB       EQU     #0017701
 4982             =~xx>PLOT       EQU     #0016701
 4983             =~xxARC         EQU     #0018701
 4984             =~xxBEEP        EQU     #0003701
 4985             =~xxBOX         EQU     #000F701
 4986             =~xxBREAK       EQU     #001D701
 4987             =~xxCHOOSE      EQU     #0041701
 4988             =~xxCOL+        EQU     #0023701
 4989             =~xxCOL-        EQU     #0022701
 4990             =~xxCSWP        EQU     #0025701
 4991             =~xxDEG         EQU     #001A0AB
 4992             =~xxDEMO        EQU     #0038701
 4993             =~xxDISP        EQU     #0002701
 4994             =~xxDISPLAY>    EQU     #0013701
 4995             =~xxDO1VSTATS   EQU     #0031701
 4996             =~xxDO2VSTATS   EQU     #0034701
 4997             =~xxERASE       EQU     #0009701
 4998             =~xxERASEPLOT   EQU     #000A701
 4999             =~xxFREEZE      EQU     #001F701
 5000             =~xxGETKEY      EQU     #0042701
 5001             =~xxGOR         EQU     #0010701
 5002             =~xxGRAD        EQU     #001C0AB
 5003             =~xxGROBNOT     EQU     #0012701
 5004             =~xxGXOR        EQU     #0011701
 5005             =~xxHELP        EQU     #0043701
 5006             =~xxINPUT       EQU     #001C701
 5007             =~xxITERATE     EQU     #00300AB
 5008             =~xxLIBEVAL     EQU     #002D701
 5009             =~xxLINE        EQU     #000D701
 5010             =~xxMATEDIT     EQU     #002A701
 5011             =~xxMEM         EQU     #0039701
 5012             =~xxMKGROB      EQU     #002B701
 5013             =~xxMSGBOX      EQU     #0040701
 5014             =~xxPIXOFF      EQU     #000C701
 5015             =~xxPIXON       EQU     #000B701
 5016             =~xxPLOT>       EQU     #0015701
 5017             =~xxPOS         EQU     #0001004
 5018             =~xxPRDISPLAY   EQU     #001B701
 5019             =~xxPRSTC       EQU     #0019701
 5020             =~xxPRVAR       EQU     #001A701
 5021             =~xxRAD         EQU     #001B0AB
 5022             =~xxRANM        EQU     #0036701
 5023             =~xxRCI         EQU     #0026701
 5024             =~xxRCIJ        EQU     #0027701
 5025             =~xxRDM         EQU     #0008701
 5026             =~xxRDZ         EQU     #0005701
 5027             =~xxREPL        EQU     #0007701
 5028             =~xxROW+        EQU     #0021701
 5029             =~xxROW-        EQU     #0020701
 5030             =~xxRSWP        EQU     #0024701
 5031             =~xxRULES       EQU     #003A701
 5032             =~xxRUNPGM      EQU     #0029701
 5033             =~xxSELECT      EQU     #0035701
 5034             =~xxSETDEPEND   EQU     #0033701
 5035             =~xxSETFREQ     EQU     #0030701
 5036             =~xxSETINDEP    EQU     #0032701
 5037             =~xxSETSAMPLE   EQU     #002F701
 5038             =~xxSETVIEWS    EQU     #003C701
 5039             =~xxSIZE        EQU     #0000004
 5040             =~xxSTOP        EQU     #001E701
 5041             =~xxSUB         EQU     #0006701
 5042             =~xxSYSEVAL     EQU     #002E701
 5043             =~xxTLINE       EQU     #000E701
 5044             =~xxTO          EQU     #0028701
 5045             =~xxTSTR        EQU     #0001701
 5046             =~xxVERSION     EQU     #0037701
 5047             =~xxWAIT        EQU     #0004701
 5048             =~xxWSLOG       EQU     #0000701
 5049             =~xxZEROGROB    EQU     #002C701
 5050             =~xy            EQU     #009A0F2
 5051             =~xz            EQU     #009B0F2
 5052             =~xz0           EQU     #00B30F2
 5053             =~xz1           EQU     #00B40F2
 5054             =~xz2           EQU     #00B50F2
 5055             =~xz3           EQU     #00B60F2
 5056             =~xz4           EQU     #00B70F2
 5057             =~xz5           EQU     #00B80F2
 5058             =~xz6           EQU     #00B90F2
 5059             =~xz7           EQU     #00BA0F2
 5060             =~xz8           EQU     #00BB0F2
 5061             =~xz9           EQU     #00BC0F2
 5062             =~{$}>{id}      EQU     #001D0E8
 5063             =~{$}>{lam}     EQU     #001E0E8
 5064             =~{id}>{$}      EQU     #001B0E8
 5065             =~{lam}>{$}     EQU     #001C0E8
 5066             =GETKEY*        EQU     #264C6
 5067             =CtlAlarm!      EQU     #26A01
 5068             =DoCAlarmKey    EQU     #269E8
 5069             =H/W>KeyCode    EQU     #23F90
 5070             =SavPtrTime*    EQU     #0131D
 5071             =~topic_CAPLET  EQU     #003B0F1
 5072             =~view01_CAPLET EQU     #00360F1
 5073             =~view23_CAPLET EQU     #00370F1
 5074             =~view45_CAPLET EQU     #00380F1
 5075             =~view6_CAPLET  EQU     #00390F1 partial match
 5076             =~view7_CAPLET  EQU     #003A0F1 partial match
 5077             =P{}N           EQU     #16747
 5078             =EQcaseDROP     EQU     #14ED5
 5079             =SetSomeRow     EQU     #26E61
 5080             =Disp5x7        EQU     #3F6FA
 5081             =DummyVarProc   EQU     #28A2C
 5082
 5083
 5084             * RPL
 5085             *|| Resuming file hpgccaplet.s at line 9
 5086             *|| Reading from =Common.h
 5087
 5088             *|| Reading from =Head39.h
 5089             * ASSEMBLE
 5090                     CLRLIST ALL
 5091             * RPL
 5092
 5093
 5094             * RPL
 5095             * insure RPL-mode exit
 5096
 5097             * ( Rad
 5098
 5099             * ( %2PI
 5100             * ( %PI/24
 5101
 5102
 5103
 5104
 5105             * ( 1=1Var, 2=2Var Statistic
 5106             * ( 1=Histogram, 2=BoxWhisker
 5107
 5108             * RPL
 5109             * insure RPL-mode exit
 5110
 5111             * ASSEMBLE
 5112             DefSysF64-33 EQU        #00000002
 5113             DefSysF32-01 EQU        #04010FF0
 5114             DefSysF65-96 EQU        #42000000       Just Algebraic Mode is On by Default
 5115             DefSysF97-128 EQU       #00000000
 5116             * RPL
 5117
 5118
 5119             * ( solution mode
 5120             * ( constants mode
 5121             * ( results mode
 5122             * ( careful evaluation mode
 5123
 5124             * ( binary integer wordsize
 5125             * must start on nibble boundary
 5126             * ( binary integer base
 5127             * must follow "fnBinWordS6"
 5128
 5129             * ( financial BEGIN/END mode
 5130             * ( complex number and vector
 5131             * mode
 5132             * ( angle mode
 5133             * must start on a nibble boundary
 5134             * ( complex 2D mode
 5135             * ( underflow action
 5136             * ( overflow action
 5137             * ( infinite result action
 5138             * ( underflow-negative indicator
 5139             * ( underflow-positive indicator
 5140             * ( overflow indicator
 5141             * ( infinite result indicator
 5142             * ( symbolic-comples decompilation
 5143             * ( simultaneous plot mode
 5144             * ( axis drawing plot mode
 5145             * ( plot both LHS & RHS even if LHS is ID
 5146             * ( connect points mode
 5147             * ( graphics cursor type mode
 5148             * ( I/O device
 5149             * ( print device
 5150             * ( I/O data format
 5151             * ( variable overwrite mode
 5152             * ( double-space print mode
 5153             * ( suppress auto CR mode
 5154             * ( suppress I/O status messages
 5155
 5156
 5157             * ( clock display mode
 5158             * ( clock display format
 5159             * ( date format
 5160             * ( reschedule unacknowledged
 5161             * repeat alarms mode
 5162             * ( delete acknowledged non-repeat
 5163             * alarms mode
 5164
 5165             * ( number of decimal digits
 5166             * must start on nibble boundary
 5167             * ( number display format
 5168             * must start on nibble boundary
 5169             * ( radix mark
 5170             * ( multi-line display mode
 5171             * ( show precedence mode
 5172             * ( zero out tiny matrix elements
 5173
 5174             * ( last arguments mode
 5175             * ( error beep mode
 5176             * ( alarm beep mode
 5177             * ( verbose display mode
 5178             * ( variable name only mode
 5179             * ( 3-way alpha mode
 5180             * ( 3-way user keys mode
 5181             * ( user keys mode
 5182             * ( special parser mode
 5183             * ( index wraparound indicator
 5184
 5185
 5186             * ASSEMBLE
 5187             SolutionsFl  EQU 1
 5188             ConstantsFl  EQU 2
 5189             ResultsFl    EQU 3
 5190             CarefulFl    EQU 4
 5191
 5192             BinWordSFl1  EQU 5      must start on a nibble boundary
 5193             BinWordSBCt  EQU 6      number of bits
 5194             BinBaseFl1   EQU 11     must follow "BinWordSFl6"
 5195             BinBaseBCt   EQU 2      number of bits
 5196
 5197             ComVecDiFl1  EQU 15
 5198             ComVecDiBCt  EQU 2      number of bits
 5199             AngleFl1     EQU 17     must start on a nibble boundary
 5200             AngleBCt     EQU 2      number of bits
 5201             Complex2DFl  EQU 19
 5202             UnderfActFl  EQU 20
 5203             OverfActFl   EQU 21
 5204             InfResActFl  EQU 22
 5205             UnderfNegFl  EQU 23
 5206             UnderfPosFl  EQU 24
 5207             OverflowFl   EQU 25
 5208             InfResultFl  EQU 26
 5209
 5210             FunctPlotFl  EQU 30
 5211             ConnectPtFl  EQU 31
 5212             GCursorFl    EQU 32
 5213             IODeviceFl   EQU 33
 5214             PrintDevFl   EQU 34
 5215             IODataFmtFl  EQU 35
 5216             OverwriteFl  EQU 36
 5217             DblSpaceFl   EQU 37
 5218             NoAutoCRFl   EQU 38
 5219             NoIOStsMsgFl EQU 39
 5220
 5221             ClockOnFl    EQU 40
 5222             ClockFmtFl   EQU 41
 5223             DateFmtFl    EQU 42
 5224             ResRepAlmFl  EQU 43
 5225             DelNRAlmFl   EQU 44
 5226
 5227             NumDigsFl1   EQU 45     must start on a nibble boundary
 5228             NumDigsBCt   EQU 4      number of bits
 5229             NumDispFl1   EQU 49     must start on a nibble boundary
 5230             NumDispBCt   EQU 2      number of bits
 5231             RadixFl      EQU 51
 5232             MultiDispFl  EQU 52
 5233             ShowPrecFl   EQU 53
 5234
 5235             LastArgsFl   EQU 55
 5236             ErrorBeepFl  EQU 56
 5237             AlarmBeepFl  EQU 57
 5238             VerboseFl    EQU 58
 5239             FastEqViewFl EQU 59
 5240             TriAlphaFl   EQU 60
 5241             TriUserFl    EQU 61
 5242             UserKeysFl   EQU 62
 5243             NoParseFl    EQU 63
 5244             IndexWrapFl  EQU 64
 5245
 5246
 5247
 5248             AlarmBeepNib EQU ((AlarmBeepFl)-1)/4
 5249             AlarmBeepBit EQU ((AlarmBeepFl)-1)%4
 5250
 5251             AngleNib     EQU ((AngleFl1)-1)/4
 5252             AngleBit1    EQU ((AngleFl1)-1)%4
 5253             AngleBit2    EQU (AngleBit1)+1
 5254
 5255             BinBaseNib   EQU ((BinBaseFl1)-1)/4
 5256             BinBaseBit1  EQU ((BinBaseFl1)-1)%4
 5257
 5258             BinWordSNib  EQU ((BinWordSFl1)-1)/4
 5259             BinWordSBit1 EQU ((BinWordSFl1)-1)%4
 5260
 5261             CarefulNib   EQU ((CarefulFl)-1)/4
 5262             CarefulBit   EQU ((CarefulFl)-1)%4
 5263
 5264             ClockFmtNib  EQU ((ClockFmtFl)-1)/4
 5265             ClockFmtBit  EQU ((ClockFmtFl)-1)%4
 5266
 5267             ClockOnNib   EQU ((ClockOnFl)-1)/4
 5268             ClockOnBit   EQU ((ClockOnFl)-1)%4
 5269
 5270             Complex2DNib EQU ((Complex2DFl)-1)/4
 5271             Complex2DBit EQU ((Complex2DFl)-1)%4
 5272
 5273             ComVecDiNib  EQU ((ComVecDiFl1)-1)/4
 5274             ComVecDiBit1 EQU ((ComVecDiFl1)-1)%4
 5275
 5276             ConnectPtNib EQU ((ConnectPtFl)-1)/4
 5277             ConnectPtBit EQU ((ConnectPtFl)-1)%4
 5278
 5279             ConstantsNib EQU ((ConstantsFl)-1)/4
 5280             ConstantsBit EQU ((ConstantsFl)-1)%4
 5281
 5282             DateFmtNib   EQU ((DateFmtFl)-1)/4
 5283             DateFmtBit   EQU ((DateFmtFl)-1)%4
 5284
 5285             DblSpaceNib  EQU ((DblSpaceFl)-1)/4
 5286             DblSpaceBit  EQU ((DblSpaceFl)-1)%4
 5287
 5288             DelNRAlmNib  EQU ((DelNRAlmFl)-1)/4
 5289             DelNRAlmBit  EQU ((DelNRAlmFl)-1)%4
 5290
 5291             ErrorBeepNib EQU ((ErrorBeepFl)-1)/4
 5292             ErrorBeepBit EQU ((ErrorBeepFl)-1)%4
 5293
 5294             FastEViewNib EQU ((FastEqViewFl)-1)/4
 5295             FastEViewBit EQU ((FastEqViewFl)-1)%4
 5296
 5297             FunctPlotNib EQU ((FunctPlotFl)-1)/4
 5298             FunctPlotBit EQU ((FunctPlotFl)-1)%4
 5299
 5300             GCursorNib   EQU ((GCursorFl)-1)/4
 5301             GCursorBit   EQU ((GCursorFl)-1)%4
 5302
 5303             IndexWrapNib EQU ((IndexWrapFl)-1)/4
 5304             IndexWrapBit EQU ((IndexWrapFl)-1)%4
 5305
 5306             InfResActNib EQU ((InfResActFl)-1)/4
 5307             InfResActBit EQU ((InfResActFl)-1)%4
 5308
 5309             InfResultNib EQU ((InfResultFl)-1)/4
 5310             InfResultBit EQU ((InfResultFl)-1)%4
 5311
 5312             IODataFmtNib EQU ((IODataFmtFl)-1)/4
 5313             IODataFmtBit EQU ((IODataFmtFl)-1)%4
 5314
 5315             IODeviceNib  EQU ((IODeviceFl)-1)/4
 5316             IODeviceBit  EQU ((IODeviceFl)-1)%4
 5317
 5318             LastArgsNib  EQU ((LastArgsFl)-1)/4
 5319             LastArgsBit  EQU ((LastArgsFl)-1)%4
 5320
 5321             VerboseNib   EQU ((VerboseFl)-1)/4
 5322             VerboseBit   EQU ((VerboseFl)-1)%4
 5323
 5324             MultiDispNib EQU ((MultiDispFl)-1)/4
 5325             MultiDispBit EQU ((MultiDispFl)-1)%4
 5326
 5327             NoAutoCRNib  EQU ((NoAutoCRFl)-1)/4
 5328             NoAutoCRBit  EQU ((NoAutoCRFl)-1)%4
 5329
 5330             NoIOStMsgNib EQU ((NoIOStsMsgFl)-1)/4
 5331             NoIOStMsgBit EQU ((NoIOStsMsgFl)-1)%4
 5332
 5333             NoParseNib   EQU ((NoParseFl)-1)/4
 5334             NoParseBit   EQU ((NoParseFl)-1)%4
 5335
 5336             NumDigsNib   EQU ((NumDigsFl1)-1)/4
 5337             NumDigsBit1  EQU ((NumDigsFl1)-1)%4
 5338
 5339             NumDispNib   EQU ((NumDispFl1)-1)/4
 5340             NumDispBit1  EQU ((NumDispFl1)-1)%4
 5341
 5342             OverfActNib  EQU ((OverfActFl)-1)/4
 5343             OverfActBit  EQU ((OverfActFl)-1)%4
 5344
 5345             OverflowNib  EQU ((OverflowFl)-1)/4
 5346             OverflowBit  EQU ((OverflowFl)-1)%4
 5347
 5348             OverwriteNib EQU ((OverwriteFl)-1)/4
 5349             OverwriteBit EQU ((OverwriteFl)-1)%4
 5350
 5351             PrintDevNib  EQU ((PrintDevFl)-1)/4
 5352             PrintDevBit  EQU ((PrintDevFl)-1)%4
 5353
 5354             RadixNib     EQU ((RadixFl)-1)/4
 5355             RadixBit     EQU ((RadixFl)-1)%4
 5356
 5357             ResRepAlmNib EQU ((ResRepAlmFl)-1)/4
 5358             ResRepAlmBit EQU ((ResRepAlmFl)-1)%4
 5359
 5360             ResultsNib   EQU ((ResultsFl)-1)/4
 5361             ResultsBit   EQU ((ResultsFl)-1)%4
 5362
 5363             ShowPrecNib  EQU ((ShowPrecFl)-1)/4
 5364             ShowPrecBit  EQU ((ShowPrecFl)-1)%4
 5365
 5366             SolutionsNib EQU ((SolutionsFl)-1)/4
 5367             SolutionsBit EQU ((SolutionsFl)-1)%4
 5368
 5369             TriAlphaNib  EQU ((TriAlphaFl)-1)/4
 5370             TriAlphaBit  EQU ((TriAlphaFl)-1)%4
 5371
 5372             TriUserNib   EQU ((TriUserFl)-1)/4
 5373             TriUserBit   EQU ((TriUserFl)-1)%4
 5374
 5375             UnderfActNib EQU ((UnderfActFl)-1)/4
 5376             UnderfActBit EQU ((UnderfActFl)-1)%4
 5377
 5378             UnderfNegNib EQU ((UnderfNegFl)-1)/4
 5379             UnderfNegBit EQU ((UnderfNegFl)-1)%4
 5380
 5381             UnderfPosNib EQU ((UnderfPosFl)-1)/4
 5382             UnderfPosBit EQU ((UnderfPosFl)-1)%4
 5383
 5384             UserKeysNib  EQU ((UserKeysFl)-1)/4
 5385             UserKeysBit  EQU ((UserKeysFl)-1)%4
 5386
 5387             * RPL
 5388             * RPL
 5389             * insure RPL-mode exit
 5390
 5391
 5392             * ASSEMBLE
 5393
 5394
 5395             nonALG EQU 8                    not-allowed-in-algebraics flag
 5396             hasHELP EQU 4                   has-help-data flag
 5397             hasPROMPTM EQU 4                same as above
 5398             hasALIAS EQU 2                  has-algebraic-alias flag
 5399             hasPDATA EQU 1                  has-parse-data flag
 5400
 5401
 5402             hasDER EQU 8                    has-derivative flag
 5403             hasINV EQU 4                    has-inverse flag
 5404             hasCOLCT EQU 2                  has-COLCT-data flag
 5405             hasEXPND EQU 1                  has-EXPND-data flag
 5406
 5407
 5408             hasFORM EQU 8                   has-FORM-menu flag
 5409             hasINTG EQU 4                   has-Integral-data flag
 5410             hasWHERE EQU 2                  has-WHERE-code flag
 5411             hasVUNS EQU 1                   has-veryunsymin-code flag
 5412
 5413
 5414             pdEX EQU #0             general expression
 5415             pdOP EQU #1             operator
 5416             pdQE EQU #2             quoted expression
 5417             pdQN EQU #3             quoted name
 5418             pdLP EQU #4             left parenthesis
 5419             pdRP EQU #5             right parenthesis
 5420             pdCM EQU #6             comma (non-radix)
 5421             pdEQ EQU #7             equal-sign separator
 5422             pdOS0 EQU #8            optional repeat 0
 5423             pdOS1 EQU #9            optional repeat 1
 5424             pdOS2 EQU #A            optional repeat 2
 5425             pdOS3 EQU #B            optional repeat 3
 5426             pdOS4 EQU #C            optional repeat 4
 5427             pdOS5 EQU #D            optional repeat 5
 5428             pdOS6 EQU #E            optional repeat 6
 5429             pdOS7 EQU #F            optional repeat 7
 5430
 5431             * RPL
 5432
 5433
 5434
 5435
 5436
 5437
 5438             * RPL
 5439             * insure RPL-mode exit
 5440
 5441
 5442
 5443
 5444
 5445
 5446
 5447             * unused key
 5448             * unused key
 5449
 5450
 5451
 5452
 5453
 5454
 5455
 5456
 5457
 5458
 5459
 5460
 5461
 5462
 5463
 5464
 5465
 5466
 5467
 5468
 5469
 5470
 5471             * RPL
 5472             * insure RPL-mode exit
 5473
 5474             * RPL
 5475             * insure RPL-mode exit
 5476
 5477
 5478
 5479
 5480
 5481
 5482
 5483
 5484
 5485             * ( for internal use only
 5486
 5487
 5488
 5489
 5490
 5491
 5492
 5493
 5494
 5495
 5496             * ( decimal 67
 5497             * ( decimal 86
 5498             * ( decimal 82
 5499             * ( decimal 85
 5500             * ( decimal 101
 5501             * ( decimal 97
 5502             * ( decimal 100
 5503             * ( decimal 113
 5504             * ( decimal 112
 5505
 5506             * ( check width
 5507             * ( field character width
 5508
 5509             * ( decimal 67
 5510             * ( decimal 85
 5511             * ( decimal 97
 5512
 5513
 5514
 5515
 5516
 5517
 5518
 5519
 5520
 5521
 5522
 5523
 5524
 5525
 5526
 5527
 5528
 5529             * RPL
 5530             * insure RPL-mode exit
 5531
 5532             * ( decimal 66
 5533             * ( decimal 67
 5534             * ( decimal 69
 5535             * ( decimal 82
 5536             * ( decimal 83
 5537             * ( decimal 84
 5538             * ( decimal 85
 5539             * ( decimal 86
 5540             * ( decimal 87
 5541             * ( decimal 97
 5542             * ( decimal 98
 5543             * ( decimal 101
 5544
 5545
 5546             * ( norm-view default visible row count
 5547             * ( default first row X location
 5548             * ( default first row Y location
 5549             * ( default row width
 5550             * ( default row height
 5551
 5552             * ( max-view width
 5553             * ( max-view height
 5554             * ( max-view default visible row count
 5555
 5556             * ( prompt area height
 5557
 5558             * ( more-up/down icon width
 5559             * ( more-up/down icon height
 5560
 5561
 5562
 5563
 5564
 5565             * ( max_var_num - min_var_num + 1
 5566             * ( number of stack args saved
 5567
 5568
 5569
 5570
 5571
 5572             * RPL
 5573             * insure RPL-mode exit
 5574
 5575             * RPL
 5576             * insure RPL-mode exit
 5577             * ASSEMBLE
 5578             * RPL
 5579
 5580
 5581
 5582
 5583
 5584
 5585
 5586             * RPL
 5587             * RPL
 5588             * insure RPL-mode exit
 5589             * RPL
 5590
 5591
 5592             * RPL
 5593             * insure RPL-mode exit
 5594
 5595
 5596
 5597
 5598
 5599
 5600
 5601
 5602
 5603
 5604
 5605
 5606
 5607
 5608
 5609
 5610
 5611
 5612
 5613
 5614
 5615
 5616
 5617
 5618
 5619
 5620
 5621
 5622
 5623
 5624
 5625
 5626
 5627
 5628
 5629
 5630
 5631
 5632
 5633
 5634
 5635
 5636
 5637
 5638
 5639
 5640
 5641
 5642
 5643
 5644
 5645
 5646
 5647
 5648
 5649
 5650
 5651
 5652
 5653
 5654
 5655
 5656
 5657
 5658
 5659
 5660
 5661
 5662
 5663
 5664
 5665
 5666
 5667
 5668
 5669
 5670
 5671             * ( maximum total number of variables
 5672             * possible for the 1-column solve layout
 5673             *
 5674             * RPL
 5675             * insure RPL-mode exit
 5676
 5677
 5678
 5679
 5680
 5681
 5682
 5683
 5684
 5685
 5686
 5687
 5688
 5689
 5690
 5691
 5692
 5693
 5694
 5695
 5696
 5697             * RPL
 5698             * insure RPL-mode exit
 5699
 5700
 5701             * ASSEMBLE
 5702             SubTypeChrBase  EQU 65 ( "A"--must match first define )
 5703             * RPL
 5704
 5705
 5706
 5707
 5708
 5709
 5710
 5711
 5712
 5713             * RPL
 5714             * insure RPL-mode exit
 5715
 5716
 5717
 5718
 5719
 5720
 5721
 5722
 5723
 5724
 5725
 5726
 5727
 5728
 5729
 5730
 5731
 5732
 5733
 5734
 5735
 5736             * RPL
 5737             * insure RPL-mode exit
 5738
 5739
 5740             * ASSEMBLE
 5742             * RPL
 5743             * RPL
 5744             * insure RPL-mode exit
 5745
 5746
 5747
 5748
 5749
 5750
 5751
 5752
 5753
 5754
 5755
 5756
 5757
 5758             * RPL
 5759             * insure RPL-mode exit
 5760
 5761
 5762
 5763
 5764
 5765
 5766
 5767             * ( set for informations
 5768             * ( set for step by step mode on
 5769             * ( internal use: true if VXXL success
 5770             * ( set for no gcd computations
 5771             * ( set for complex mode
 5772             * ( internal use:       LN->-INV[-LN]]
 5773             * ( set for approx mode
 5774             * ( set for TSIMP call inside SERIES
 5775             * ( internal use:       modular computation
 5776             * ( internal use:       testing remainder=0
 5777             * ( set to allow numeric factorization
 5778             * ( set for large matrices
 5779             * ( set: don't simplify inside non rational operation
 5780             * ( set to see i as an irrquad c=-1
 5781             * ( set to disable linearity simplif.
 5782             * ( set for increasing power x+1 -> 1+x
 5783             * ( internal use:       sqrt not as irrquad
 5784             * ( set if sin are prefered to cos
 5785             * ( set for menu as choosebox
 5786             * ( set if xINT is not simplified
 5787             * ( set if non rigourous mode
 5788             * ( set to allow silent mode switch
 5789             * ( set if xLN returns LN[ABS[]]
 5790
 5791
 5792             * ASSEMBLE
 5793
 5794             MultiLineFl     EQU     65
 5795             MultiLineNib    EQU     ((MultiLineFl)-1)/4
 5796             MultiLineBit    EQU     ((MultiLineFl)-1)%4
 5797             MultiLineStringsFl      EQU     66
 5798             MultiLineStringsNib     EQU     ((MultiLineStringsFl)-1)/4
 5799             MultiLineStringsBit     EQU     ((MultiLineStringsFl)-1)%4
 5800             DigitalClockFl  EQU     67
 5801             DigitalClockNib EQU     ((DigitalClockFl)-1)/4
 5802             DigitalClockBit EQU     ((DigitalClockFl)-1)%4
 5803             CmdAutoIndentFl EQU     68
 5804             CmdAutoIndentNib        EQU     ((CmdAutoIndentFl)-1)/4
 5805             CmdAutoIndentBit        EQU     ((CmdAutoIndentFl)-1)%4
 5806             FullScreenEditFl        EQU     69
 5807             FullScreenEditNib       EQU     ((FullScreenEditFl)-1)/4
 5808             FullScreenEditBit       EQU     ((FullScreenEditFl)-1)%4
 5809             MultiLine2GROBFl        EQU     70
 5810             MultiLine2GROBNib       EQU     ((MultiLine2GROBFl)-1)/4
 5811             MultiLine2GROBBit       EQU     ((MultiLine2GROBFl)-1)%4
 5812             DesasmWithAdrFl EQU     71
 5813             DesasmWithAdrNib        EQU     ((DesasmWithAdrFl)-1)/4
 5814             DesasmWithAdrBit        EQU     ((DesasmWithAdrFl)-1)%4
 5815             BigFontStackFl  EQU     72
 5816             BigFontStackNib EQU     ((BigFontStackFl)-1)/4
 5817             BigFontStackBit EQU     ((BigFontStackFl)-1)%4
 5818             BigFontCmdFl    EQU     73
 5819             BigFontCmdNib   EQU     ((BigFontCmdFl)-1)/4
 5820             BigFontCmdBit   EQU     ((BigFontCmdFl)-1)%4
 5821             RightJustifiedStackFl   EQU     74
 5822             RightJustifiedStackNib  EQU     ((RightJustifiedStackFl)-1)/4
 5823             RightJustifiedStackBit  EQU     ((RightJustifiedStackFl)-1)%4
 5824             KeystrokeBeepFl EQU     75
 5825             KeystrokeBeepNib        EQU     ((KeystrokeBeepFl)-1)/4
 5826             KeystrokeBeepBit        EQU     ((KeystrokeBeepFl)-1)%4
 5827             FilerConfirmationFl     EQU     76
 5828             FilerConfirmationNib    EQU     ((FilerConfirmationFl)-1)/4
 5829             FilerConfirmationBit    EQU     ((FilerConfirmationFl)-1)%4
 5830             FilerConfirmFl  EQU     77
 5831             FilerConfirmNib EQU     ((FilerConfirmFl)-1)/4
 5832             FilerConfirmBit EQU     ((FilerConfirmFl)-1)%4
 5833             KernelParamFl   EQU     78
 5834             KernelParamNib  EQU     ((KernelParamFl)-1)/4
 5835             KernelParamBit  EQU     ((KernelParamFl)-1)%4
 5836             PrettyPrintFl   EQU     79
 5837             PrettyPrintNib  EQU     ((PrettyPrintFl)-1)/4
 5838             PrettyPrintBit  EQU     ((PrettyPrintFl)-1)%4
 5839             SmallFontEQWStackFl     EQU     80
 5840             SmallFontEQWStackNib    EQU     ((SmallFontEQWStackFl)-1)/4
 5841             SmallFontEQWStackBit    EQU     ((SmallFontEQWStackFl)-1)%4
 5842             SmallFontEQWGrobFl      EQU     81
 5843             SmallFontEQWGrobNib     EQU     ((SmallFontEQWGrobFl)-1)/4
 5844             SmallFontEQWGrobBit     EQU     ((SmallFontEQWGrobFl)-1)%4
 5845             SmallFontEQWEditFl      EQU     82
 5846             SmallFontEQWEditNib     EQU     ((SmallFontEQWEditFl)-1)/4
 5847             SmallFontEQWEditBit     EQU     ((SmallFontEQWEditFl)-1)%4
 5848             GrobDisplayFl   EQU     83
 5849             GrobDisplayNib  EQU     ((GrobDisplayFl)-1)/4
 5850             GrobDisplayBit  EQU     ((GrobDisplayFl)-1)%4
 5851             MKSmallFontMenuFl       EQU     84
 5852             MKSmallFontMenuNib      EQU     ((MKSmallFontMenuFl)-1)/4
 5853             MKSmallFontMenuBit      EQU     ((MKSmallFontMenuFl)-1)%4
 5854             SystemRPLStackFl        EQU     85
 5855             SystemRPLStackNib       EQU     ((SystemRPLStackFl)-1)/4
 5856             SystemRPLStackBit       EQU     ((SystemRPLStackFl)-1)%4
 5857             MASDDecompilerFl        EQU     86
 5858             MASDDecompilerNib       EQU     ((MASDDecompilerFl)-1)/4
 5859             MASDDecompilerBit       EQU     ((MASDDecompilerFl)-1)%4
 5860             RecursiveStackFl        EQU     87
 5861             RecursiveStackNib       EQU     ((RecursiveStackFl)-1)/4
 5862             RecursiveStackBit       EQU     ((RecursiveStackFl)-1)%4
 5863             RecursiveEditFl EQU     88
 5864             RecursiveEditNib        EQU     ((RecursiveEditFl)-1)/4
 5865             RecursiveEditBit        EQU     ((RecursiveEditFl)-1)%4
 5866             AddressesCLEFl  EQU     89
 5867             AddressesCLENib EQU     ((AddressesCLEFl)-1)/4
 5868             AddressesCLEBit EQU     ((AddressesCLEFl)-1)%4
 5869             SmallFontChooseFl       EQU     90
 5870             SmallFontChooseNib      EQU     ((SmallFontChooseFl)-1)/4
 5871             SmallFontChooseBit      EQU     ((SmallFontChooseFl)-1)%4
 5872             ArrayOnlyFl     EQU     91
 5873             ArrayOnlyNib    EQU     ((ArrayOnlyFl)-1)/4
 5874             ArrayOnlyBit    EQU     ((ArrayOnlyFl)-1)%4
 5875             MLMASDModeFl    EQU     92
 5876             MLMASDModeNib   EQU     ((MLMASDModeFl)-1)/4
 5877             MLMASDModeBit   EQU     ((MLMASDModeFl)-1)%4
 5878             ErableHeaderFl  EQU     93
 5879             ErableHeaderNib EQU     ((ErableHeaderFl)-1)/4
 5880             ErableHeaderBit EQU     ((ErableHeaderFl)-1)%4
 5881             AutoSaveFl      EQU     94
 5882             AutoSaveNib     EQU     ((AutoSaveFl)-1)/4
 5883             AutoSaveBit     EQU     ((AutoSaveFl)-1)%4
 5884             AlgebraicModeFl EQU     95
 5885             AlgebraicModeNib        EQU     ((AlgebraicModeFl)-1)/4
 5886             AlgebraicModeBit        EQU     ((AlgebraicModeFl)-1)%4
 5887             MenuOnFl        EQU     96
 5888             MenuOnNib       EQU     ((MenuOnFl)-1)/4
 5889             MenuOnBit       EQU     ((MenuOnFl)-1)%4
 5890             VerticalListFl  EQU     97
 5891             VerticalListNib EQU     ((VerticalListFl)-1)/4
 5892             VerticalListBit EQU     ((VerticalListFl)-1)%4
 5893             VerticalVectorFl        EQU     98
 5894             VerticalVectorNib       EQU     ((VerticalVectorFl)-1)/4
 5895             VerticalVectorBit       EQU     ((VerticalVectorFl)-1)%4
 5896
 5897
 5898             ComplexFl       EQU     103
 5899             ComplexNib      EQU     ((ComplexFl)-1)/4
 5900             ComplexBit      EQU     ((ComplexFl)-1)%4
 5901
 5902
 5903             ExactModeFl     EQU     105
 5904             ExactModeNib    EQU     ((ExactModeFl)-1)/4
 5905             ExactModeBit    EQU     ((ExactModeFl)-1)%4
 5906
 5907
 5908             * RPL
 5909
 5910
 5911
 5912             *|| Resuming file =Common.h at line 3
 5913
 5914             * ASSEMBLE
 5915
 5916                      LISTM
 5917
 5918
 5919
 5920             Dir_Head MACRO
 5921                      NIBASC \HP39BinB\
 5922                      CON(2)  $1            length of name
 5923                      NIBASC \$2\           name
 5924             DirStart CON(5) =DORRP
 5925                      CON(3) #$3            attached rompart id
 5926                      REL(5) DirEnd         link to last object in directory
 5927                      CON(5) 0
 5928             L1       CON(2) 0              last link
 5929                      ENDM
 5930
 5931
 5932
 5933             Lib_Head MACRO
 5934                      NIBASC \HP39BinH\
 5935                      CON(2) $1
 5936                      NIBASC \$2\
 5937                      ENDM
 5938
 5939
 5940             Vfield   MACRO
 5941                      CON(5) (*)-($1)
 5942             $2       CON(2) 0
 5943                      ENDM
 5944
 5945
 5946             Cfield   MACRO
 5947                      CON(5) (*)-($1)
 5948             $2       CON(2) 0
 5949             =$3      EQU    (*)-(DirStart)
 5950                      ENDM
 5951
 5952
 5953             HELPONLY MACRO
 5954                      CON(1)  (nonALG)+1*(hasHELP)+0*(hasALIAS)+0*(hasPDATA)
 5955                      CON(6)  =~$1
 5956                      ENDM
 5957
 5958             Link     MACRO
 5959                      CON(5) ($1)-(DirStart)
 5960                      ENDM
 5961
 5962             * RPL
 5963
 5964
 5965
 5966             * ASSEMBLE
 5967
 5968             altROMID        EQU   #6FD
 5969
 5970             =~altFUNCTOPIC  EQU   (altROMID)+4096*0
 5971             =~altPOLARTOPIC EQU   (altROMID)+4096*1
 5972             =~altPARAMTOPIC EQU   (altROMID)+4096*2
 5973             =~altSEQTOPIC   EQU   (altROMID)+4096*3
 5974             =~altSTATTOPIC  EQU   (altROMID)+4096*4
 5975             =~altSOLVETOPIC EQU   (altROMID)+4096*5
 5976
 5977             * RPL
 5978
 5979
 5980
 5981
 5982
 5983
 5984
 5985
 5986
 5987
 5988
 5989
 5990
 5991
 5992
 5993
 5994
 5995
 5996             *|| Resuming file hpgccaplet.s at line 10
 5997
 5998
 5999
 6000             * ASSEMBLE
 6001             * File  hpgccaplet.s    18
 6002             =~xPrRUN        EQU     #113+4096*0
 6003             * File  hpgccaplet.s    19
 6004             =~xShSPLASH     EQU     #113+4096*1
 6005             * File  hpgccaplet.s    20
 6006             =~xHpgccABOUT   EQU     #113+4096*2
 6007             * File  hpgccaplet.s    21
 6008             * RPL
 6009             * File  hpgccaplet.s    22
 6010
 6011             * File  hpgccaplet.s    23
 6012             * File  hpgccaplet.s    24
 6013             * File  hpgccaplet.s    25
 6014             * File  hpgccaplet.s    26
 6015
 6016             * File  hpgccaplet.s    27
 6017
 6018             * File  hpgccaplet.s    28
 6019
 6020             * File  hpgccaplet.s    29
 6021             * ASSEMBLE
 6022             * File  hpgccaplet.s    30
 6023 00000               Dir_Head 11,HPGCC Aplet,113
 6024             * File  hpgccaplet.s    31
 6025
 6026             * File  hpgccaplet.s    32
 6027             * RPL
 6028             * File  hpgccaplet.s    33
 6029
 6030             * File  hpgccaplet.s    34
 6031 0003C 47A20         CON(5)  =DOLIST
 6032 00041 29E20         CON(5)  =DOROMP
 6033 00046 1F0B3         CON(6)  =~topic_CAPLET
            0
 6034 0004C 29E20         CON(5)  =DOROMP
 6035 00051 1F063         CON(6)  =~view01_CAPLET
            0
 6036 00057 29E20         CON(5)  =DOROMP
 6037 0005C 1F073         CON(6)  =~view23_CAPLET
            0
 6038 00062 29E20         CON(5)  =DOROMP
 6039 00067 1F083         CON(6)  =~view45_CAPLET
            0
 6040 0006D 29E20         CON(5)  =DOROMP
 6041 00072 1F0C3         CON(6)  =~xREADNOTE
            0
 6042 00078 29E20         CON(5)  =DOROMP
 6043 0007D 1F0D3         CON(6)  =~xREADPICT
            0
 6044 00083 B2130         CON(5)  =SEMI
 6045             * File  hpgccaplet.s    35
 6046
 6047             * File  hpgccaplet.s    36
 6048
 6049             * File  hpgccaplet.s    37
 6050             *|| Reading from =Sharedvar.h
 6051
 6052             * ASSEMBLE
 6053 00088               Cfield  L1,L2,Xmin
 6054             * RPL
 6055 0008F 33920         CON(5)  =DOREAL
 6056 00094 000           NIBHEX  000
 6057 00097 00000         NIBHEX  000000000056
            00000
            56
 6058 000A3 9             NIBHEX  9
 6059             * File  =Sharedvar.h    7
 6060
 6061             * File  =Sharedvar.h    8
 6062             * ASSEMBLE
 6063 000A4               Cfield  L2,L3,Xmax
 6064             * RPL
 6065 000AB 33920         CON(5)  =DOREAL
 6066 000B0 000           NIBHEX  000
 6067 000B3 00000         NIBHEX  000000000056
            00000
            56
 6068 000BF 0             NIBHEX  0
 6069             * File  =Sharedvar.h    12
 6070
 6071             * File  =Sharedvar.h    13
 6072             * ASSEMBLE
 6073 000C0               Cfield  L3,L4,Ymin
 6074             * RPL
 6075 000C7 33920         CON(5)  =DOREAL
 6076 000CC 000           NIBHEX  000
 6077 000CF 00000         NIBHEX  000000000013
            00000
            13
 6078 000DB 9             NIBHEX  9
 6079             * File  =Sharedvar.h    17
 6080
 6081             * File  =Sharedvar.h    18
 6082             * ASSEMBLE
 6083 000DC               Cfield  L4,L5,Ymax
 6084             * RPL
 6085 000E3 33920         CON(5)  =DOREAL
 6086 000E8 000           NIBHEX  000
 6087 000EB 00000         NIBHEX  000000000023
            00000
            23
 6088 000F7 0             NIBHEX  0
 6089             * File  =Sharedvar.h    22
 6090
 6091             * File  =Sharedvar.h    23
 6092             * ASSEMBLE
 6093 000F8               Cfield  L5,L6,Xmin2
 6094             * RPL
 6095 000FF 33920         CON(5)  =DOREAL
 6096 00104 000           NIBHEX  000
 6097 00107 00000         NIBHEX  000000000056
            00000
            56
 6098 00113 9             NIBHEX  9
 6099
 6100             * ASSEMBLE
 6101 00114               Cfield  L6,L7,Xmax2
 6102             * RPL
 6103 0011B 33920         CON(5)  =DOREAL
 6104 00120 000           NIBHEX  000
 6105 00123 00000         NIBHEX  000000000056
            00000
            56
 6106 0012F 0             NIBHEX  0
 6107
 6108             * ASSEMBLE
 6109 00130               Cfield  L7,L8,Ymin2
 6110             * RPL
 6111 00137 33920         CON(5)  =DOREAL
 6112 0013C 000           NIBHEX  000
 6113 0013F 00000         NIBHEX  000000000013
            00000
            13
 6114 0014B 9             NIBHEX  9
 6115
 6116             * ASSEMBLE
 6117 0014C               Cfield  L8,L9,Ymax2
 6118             * RPL
 6119 00153 33920         CON(5)  =DOREAL
 6120 00158 000           NIBHEX  000
 6121 0015B 00000         NIBHEX  000000000023
            00000
            23
 6122 00167 0             NIBHEX  0
 6123
 6124             * ASSEMBLE
 6125 00168               Cfield  L9,L10,HTick
 6126             * RPL
 6127 0016F 33920         CON(5)  =DOREAL
 6128 00174 000           NIBHEX  000
 6129 00177 00000         NIBHEX  000000000001
            00000
            01
 6130 00183 0             NIBHEX  0
 6131             * File  =Sharedvar.h    47
 6132
 6133             * File  =Sharedvar.h    48
 6134             * ASSEMBLE
 6135 00184               Cfield  L10,L11,VTick
 6136             * RPL
 6137 0018B 33920         CON(5)  =DOREAL
 6138 00190 000           NIBHEX  000
 6139 00193 00000         NIBHEX  000000000001
            00000
            01
 6140 0019F 0             NIBHEX  0
 6141             * File  =Sharedvar.h    52
 6142
 6143             * File  =Sharedvar.h    53
 6144             * ASSEMBLE
 6145 001A0               Cfield  L11,L12,HZoom
 6146             * RPL
 6147 001A7 33920         CON(5)  =DOREAL
 6148 001AC 000           NIBHEX  000
 6149 001AF 00000         NIBHEX  000000000004
            00000
            04
 6150 001BB 0             NIBHEX  0
 6151             * File  =Sharedvar.h    57
 6152
 6153             * File  =Sharedvar.h    58
 6154             * ASSEMBLE
 6155 001BC               Cfield  L12,L13,VZoom
 6156             * RPL
 6157 001C3 33920         CON(5)  =DOREAL
 6158 001C8 000           NIBHEX  000
 6159 001CB 00000         NIBHEX  000000000004
            00000
            04
 6160 001D7 0             NIBHEX  0
 6161             * File  =Sharedvar.h    62
 6162
 6163             * File  =Sharedvar.h    63
 6164             * ASSEMBLE
 6165 001D8               Cfield  L13,L14,Angle
 6166             * RPL
 6167 001DF 11920         CON(5)  =DOBINT
 6168 001E4 20000         CON(5)  #2
 6169             * File  =Sharedvar.h    67
 6170
 6171             * File  =Sharedvar.h    68
 6172             * ASSEMBLE
 6173 001E9               Cfield  L14,L15,LastX
 6174             * RPL
 6175 001F0 33920         CON(5)  =DOREAL
 6176 001F5 000           NIBHEX  000
 6177 001F8 00000         NIBHEX  000000000000
            00000
            00
 6178 00204 0             NIBHEX  0
 6179
 6180             * ASSEMBLE
 6181 00205               Cfield  L15,L16,LastY
 6182             * RPL
 6183 0020C 33920         CON(5)  =DOREAL
 6184 00211 000           NIBHEX  000
 6185 00214 00000         NIBHEX  000000000000
            00000
            00
 6186 00220 0             NIBHEX  0
 6187
 6188             * ASSEMBLE
 6189 00221               Cfield  L16,L17,LastIndep
 6190             * RPL
 6191 00228 33920         CON(5)  =DOREAL
 6192 0022D 000           NIBHEX  000
 6193 00230 00000         NIBHEX  000000000000
            00000
            00
 6194 0023C 0             NIBHEX  0
 6195
 6196             * ASSEMBLE
 6197 0023D               Cfield  L17,L18,LastEq
 6198             * RPL
 6199 00244 11920         CON(5)  =DOBINT
 6200 00249 10000         CON(5)  #1
 6201
 6202             * ASSEMBLE
 6203 0024E               Cfield  L18,L19,PlotFlag
 6204             * RPL
 6205 00255 11920         CON(5)  =DOBINT
 6206 0025A 68100         CON(5)  #186
 6207
 6208
 6209             * ASSEMBLE
 6210 0025F               Cfield  L19,L20,Plot2Flg
 6211             * RPL
 6212 00266 11920         CON(5)  =DOBINT
 6213 0026B 10000         CON(5)  #1
 6214
 6215
 6216             * ASSEMBLE
 6217 00270               Cfield  L20,L21,PlotCKSUM
 6218             * RPL
 6219 00277 33920         CON(5)  =DOREAL
 6220 0027C 000           NIBHEX  000
 6221 0027F 00000         NIBHEX  000000000000
            00000
            00
 6222 0028B 0             NIBHEX  0
 6223
 6224             * ASSEMBLE
 6225 0028C               Cfield  L21,L22,SplitCKSUM
 6226             * RPL
 6227 00293 33920         CON(5)  =DOREAL
 6228 00298 000           NIBHEX  000
 6229 0029B 00000         NIBHEX  000000000000
            00000
            00
 6230 002A7 0             NIBHEX  0
 6231
 6232             * ASSEMBLE
 6233 002A8               Cfield  L22,L23,Split2CKSUM
 6234             * RPL
 6235 002AF 33920         CON(5)  =DOREAL
 6236 002B4 000           NIBHEX  000
 6237 002B7 00000         NIBHEX  000000000000
            00000
            00
 6238 002C3 0             NIBHEX  0
 6239
 6240             * ASSEMBLE
 6241 002C4               Cfield  L23,L24,TStart
 6242             * RPL
 6243 002CB 33920         CON(5)  =DOREAL
 6244 002D0 000           NIBHEX  000
 6245 002D3 00000         NIBHEX  000000000000
            00000
            00
 6246 002DF 0             NIBHEX  0
 6247             * File  =Sharedvar.h    130
 6248
 6249             * File  =Sharedvar.h    131
 6250             * ASSEMBLE
 6251 002E0               Cfield  L24,L25,TStep
 6252             * RPL
 6253 002E7 33920         CON(5)  =DOREAL
 6254 002EC 999           NIBHEX  999
 6255 002EF 00000         NIBHEX  000000000001
            00000
            01
 6256 002FB 0             NIBHEX  0
 6257             * File  =Sharedvar.h    135
 6258
 6259             * File  =Sharedvar.h    136
 6260             * ASSEMBLE
 6261 002FC               Cfield  L25,L26,TZoom
 6262             * RPL
 6263 00303 33920         CON(5)  =DOREAL
 6264 00308 000           NIBHEX  000
 6265 0030B 00000         NIBHEX  000000000004
            00000
            04
 6266 00317 0             NIBHEX  0
 6267             * File  =Sharedvar.h    140
 6268
 6269             ** Bit 0: Font
 6270             ** Bit 1: Building table
 6271             * File  =Sharedvar.h    143
 6272             * ASSEMBLE
 6273 00318               Cfield  L26,L27,TFlags
 6274             * RPL
 6275 0031F 11920         CON(5)  =DOBINT
 6276 00324 00000         CON(5)  0
 6277             * File  =Sharedvar.h    147
 6278
 6279             * File  =Sharedvar.h    148
 6280             * ASSEMBLE
 6281 00329               Cfield  L27,L28,Trow
 6282             * RPL
 6283 00330 11920         CON(5)  =DOBINT
 6284 00335 00000         CON(5)  0
 6285
 6286             * ASSEMBLE
 6287 0033A               Cfield  L28,L29,Tcol
 6288             * RPL
 6289 00341 11920         CON(5)  =DOBINT
 6290 00346 10000         CON(5)  1
 6291
 6292             * ASSEMBLE
 6293 0034B               Cfield  L29,L30,TCol1
 6294             * RPL
 6295 00352 11920         CON(5)  =DOBINT
 6296 00357 10000         CON(5)  1
 6297
 6298             * ASSEMBLE
 6299 0035C               Cfield  L30,L31,SplitRow
 6300             * RPL
 6301 00363 11920         CON(5)  =DOBINT
 6302 00368 30000         CON(5)  3
 6303
 6304             * ASSEMBLE
 6305 0036D               Cfield  L31,L32,BTRow1
 6306             * RPL
 6307 00374 11920         CON(5)  =DOBINT
 6308 00379 00000         CON(5)  0
 6309
 6310             * ASSEMBLE
 6311 0037E               Cfield  L32,L33,Format
 6312             * RPL
 6313 00385 11920         CON(5)  =DOBINT
 6314 0038A 10000         CON(5)  #1
 6315             * File  =Sharedvar.h    177
 6316
 6317             * File  =Sharedvar.h    178
 6318             * ASSEMBLE
 6319 0038F               Cfield  L33,L34,Digits
 6320             * RPL
 6321 00396 11920         CON(5)  =DOBINT
 6322 0039B 00000         CON(5)  #0
 6323             * File  =Sharedvar.h    182
 6324
 6325             *|| Resuming file hpgccaplet.s at line 37
 6326             * File  hpgccaplet.s    38
 6327
 6328             * File  hpgccaplet.s    39
 6329             * ASSEMBLE
 6330             * File  hpgccaplet.s    40
 6331 003A0               Vfield  L34,IntTable
 6332             * File  hpgccaplet.s    41
 6333 003A7 E4A20         CON(5)  =DOHSTR
 6334             * File  hpgccaplet.s    42
 6335 003AC 32000         REL(5)  endLink
 6336             * File  hpgccaplet.s    43
 6337 003B1               Link    _Main
 6338             * File  hpgccaplet.s    44
 6339 003B6               Link    _Entry
 6340             * File  hpgccaplet.s    45
 6341 003BB               Link    _Exit
 6342             * File  hpgccaplet.s    46
 6343 003C0               Link    _Action
 6344             * File  hpgccaplet.s    47
 6345 003C5               Link    _Reset
 6346             * File  hpgccaplet.s    48
 6347 003CA               Link    _About
 6348             *>>>    Add links to more routines here, they must
 6349             *       be paired w/ the defines just below
 6350             * File  hpgccaplet.s    51
 6351
 6352             * File  hpgccaplet.s    52
 6353 003CF       endLink
 6354             * File  hpgccaplet.s    53
 6355             * RPL
 6356             * File  hpgccaplet.s    54
 6357
 6358             * File  hpgccaplet.s    55
 6359             * File  hpgccaplet.s    56
 6360             * File  hpgccaplet.s    57
 6361             * File  hpgccaplet.s    58
 6362             * File  hpgccaplet.s    59
 6363             * File  hpgccaplet.s    60
 6364             * File  hpgccaplet.s    61
 6365
 6366             *>>>    Add defines for more routines here
 6367             *       INT_05..INT_09, INT_0A..INT_0F or BINT INT_NN
 6368             *       Use INT_10..INT_1F and INT_NN w/ care !
 6369             * Each entry should be in the form of:
 6370             * DEFINE LabelName      INT_xx
 6371             * File  hpgccaplet.s    67
 6372
 6373             * File  hpgccaplet.s    68
 6374             * ASSEMBLE
 6375             * File  hpgccaplet.s    69
 6376 003CF               Vfield  IntTable,DirVar
 6377             * File  hpgccaplet.s    70
 6378             * RPL
 6379             * File  hpgccaplet.s    71
 6380             * ASSEMBLE
 6381             * File  hpgccaplet.s    72
 6382 003D6 E4A20         CON(5)  =DOHSTR
 6383             * File  hpgccaplet.s    73
 6384 003DB BB200         REL(5)  endCode
 6385             * File  hpgccaplet.s    74
 6386             * RPL
 6387             * File  hpgccaplet.s    75
 6388
 6389             *
 6390             * DEFINES to get access to the saved parameters
 6391             *
 6392             * File  hpgccaplet.s    79
 6393             * File  hpgccaplet.s    80
 6394             * File  hpgccaplet.s    81
 6395             * File  hpgccaplet.s    82
 6396             * File  hpgccaplet.s    83
 6397             * File  hpgccaplet.s    84
 6398
 6399             * File  hpgccaplet.s    85
 6400
 6401             *
 6402             * Main code entry
 6403             *
 6404             * File  hpgccaplet.s    89
 6405 003E0       =_Main
 6406             * File  hpgccaplet.s    90
 6407 003E0 D9D20         CON(5)  =DOCOL
 6408             * File  hpgccaplet.s    91
 6409
 6410             *     StndCheck                 ( Default handler for the aplet )
 6411             * File  hpgccaplet.s    93
 6412
 6413             * REPLACED BY THE FOLLOWING TO KNOW WHICH VIEW THE USER ENTERED FROM
 6414             * File  hpgccaplet.s    95
 6415 003E5 47A20         CON(5)  =DOLIST
 6416 003EA 1AE11         CON(5)  =MINUSONE
 6417 003EF 47A20         CON(5)  =DOLIST
 6418 003F4 47A20         CON(5)  =DOLIST
 6419 003F9 C2A20         CON(5)  =DOCSTR
 6420 003FE F0000         CON(5)  15
 6421 00403 35471         NIBASC  \Start\
            62747
 6422 0040D D9D20         CON(5)  =DOCOL
 6423 00412 94040         CON(5)  =ZERO
 6424 00417 14683         CON(5)  =INT_00
 6425 0041C B2130         CON(5)  =SEMI
 6426 00421 B2130         CON(5)  =SEMI
 6427 00426 B2130         CON(5)  =SEMI
 6428 0042B BAE11         CON(5)  =MINUSTWO
 6429 00430 54383         CON(5)  =MiniVar
 6430 00435 5BE11         CON(5)  =MINUSTHREE
 6431 0043A C5670         CON(5)  =NOP
 6432 0043F FBE11         CON(5)  =MINUSFOUR
 6433 00444 C5670         CON(5)  =NOP
 6434 00449 9CE11         CON(5)  =MINUSFIVE
 6435 0044E C5670         CON(5)  =NOP
 6436 00453 B2130         CON(5)  =SEMI
 6437 00458 36783         CON(5)  =BinLookup
 6438 0045D C55D0         CON(5)  =case
 6439 00462 C5770         CON(5)  =EVAL
 6440             * File  hpgccaplet.s    96
 6441
 6442             * STORE THE VIEW NUMBER IN TOPICVAR2
 6443             * File  hpgccaplet.s    98
 6444
 6445             * File  hpgccaplet.s    99
 6446 00467 2AC21         CON(5)  =TopicVar2!
 6447             * File  hpgccaplet.s    100
 6448
 6449             * File  hpgccaplet.s    101
 6450
 6451             * File  hpgccaplet.s    102
 6452
 6453             ** For each view, the main code is supposed to return 8 arguments (similar to the HP48/49 ParOuterLoop):
 6454             ** Level: 8: View Entry handler (program)
 6455             **        7: View Exit handler (program)
 6456             **        6: Display handler (program)
 6457             **        5: Hard Key handler (program)
 6458             **        4: Flag to allow normal keys (TRUE or FALSE)
 6459             **        3: Menu Definition (list)
 6460             **        2: Initial Menu Page (System Binary)
 6461             **        1: Error handler (program)
 6462             *<SOURCE CODE END>
 6463             * File  hpgccaplet.s    113
 6464
 6465             * File  hpgccaplet.s    114
 6466 0046C 56670         CON(5)  ='
 6467 00471 64683         CON(5)  =INT_01
 6468             * view entry
 6469             * File  hpgccaplet.s    115
 6470 00476 56670         CON(5)  ='
 6471 0047B B4683         CON(5)  =INT_02
 6472             * view exit
 6473             * File  hpgccaplet.s    116
 6474
 6475             * File  hpgccaplet.s    117
 6476 00480 56670         CON(5)  ='
 6477             * view display
 6478             * File  hpgccaplet.s    118
 6479 00485 D9D20         CON(5)  =DOCOL
 6480             * File  hpgccaplet.s    119
 6481 0048A 18383         CON(5)  =EnsureMenuOff
 6482             * **Remove this line if you want the menu to be displayed
 6483             * File  hpgccaplet.s    120
 6484 0048F B2130         CON(5)  =SEMI
 6485             * File  hpgccaplet.s    121
 6486 00494 56670         CON(5)  ='
 6487             * view hard key handlers
 6488             * File  hpgccaplet.s    122
 6489 00499 D9D20         CON(5)  =DOCOL
 6490             * File  hpgccaplet.s    123
 6491 0049E 47A20         CON(5)  =DOLIST
 6492             * File  hpgccaplet.s    124
 6493 004A3 47A20         CON(5)  =DOLIST
 6494 004A8 74240         CON(5)  =BINT51
 6495 004AD D9D20         CON(5)  =DOCOL
 6496 004B2 84442         CON(5)  =TakeOver
 6497 004B7 05683         CON(5)  =INT_03
 6498 004BC B2130         CON(5)  =SEMI
 6499 004C1 B2130         CON(5)  =SEMI
 6500             * **ENTER will start your main code
 6501             * File  hpgccaplet.s    125
 6502 004C6 2AD50         CON(5)  =NULL{}
 6503             * File  hpgccaplet.s    126
 6504 004CB 2AD50         CON(5)  =NULL{}
 6505             * File  hpgccaplet.s    127
 6506 004D0 2AD50         CON(5)  =NULL{}
 6507             * File  hpgccaplet.s    128
 6508 004D5 2AD50         CON(5)  =NULL{}
 6509             * File  hpgccaplet.s    129
 6510 004DA 2AD50         CON(5)  =NULL{}
 6511             * File  hpgccaplet.s    130
 6512 004DF B2130         CON(5)  =SEMI
 6513             * File  hpgccaplet.s    131
 6514 004E4 35040         CON(5)  =ONE
 6515 004E9 97F63         CON(5)  =KeyFace
 6516             * File  hpgccaplet.s    132
 6517 004EE B2130         CON(5)  =SEMI
 6518             * File  hpgccaplet.s    133
 6519
 6520             * File  hpgccaplet.s    134
 6521 004F3 18A30         CON(5)  =TRUE
 6522             * **Allow normal keys**
 6523             * File  hpgccaplet.s    135
 6524
 6525             * File  hpgccaplet.s    136
 6526 004F8 47A20         CON(5)  =DOLIST
 6527             * **Initial menu**
 6528             * File  hpgccaplet.s    137
 6529 004FD 47A20         CON(5)  =DOLIST
 6530 00502 C2A20         CON(5)  =DOCSTR
 6531 00507 50000         CON(5)  5
 6532 0050C D9D20         CON(5)  =DOCOL
 6533 00511 84442         CON(5)  =TakeOver
 6534 00516 D2982         CON(5)  =LastBut3
 6535 0051B 86C50         CON(5)  =INNERCOMP
 6536 00520 368F0         CON(5)  =ROLLDROP
 6537 00525 44230         CON(5)  =DROP
 6538 0052A 29E20         CON(5)  =DOROMP
 6539 0052F 31110         CON(6)  =~xShSPLASH
            0
 6540 00535 B2130         CON(5)  =SEMI
 6541 0053A B2130         CON(5)  =SEMI
 6542             * File  hpgccaplet.s    138
 6543 0053F 97B92         CON(5)  =NullMenuKey
 6544             * File  hpgccaplet.s    139
 6545 00544 97B92         CON(5)  =NullMenuKey
 6546             * File  hpgccaplet.s    140
 6547 00549 97B92         CON(5)  =NullMenuKey
 6548             * File  hpgccaplet.s    141
 6549 0054E 97B92         CON(5)  =NullMenuKey
 6550             * File  hpgccaplet.s    142
 6551 00553 47A20         CON(5)  =DOLIST
 6552 00558 C2A20         CON(5)  =DOCSTR
 6553 0055D 50000         CON(5)  5
 6554 00562 D9D20         CON(5)  =DOCOL
 6555 00567 84442         CON(5)  =TakeOver
 6556 0056C A5683         CON(5)  =INT_05
 6557 00571 B2130         CON(5)  =SEMI
 6558 00576 B2130         CON(5)  =SEMI
 6559             * File  hpgccaplet.s    143
 6560 0057B B2130         CON(5)  =SEMI
 6561             * File  hpgccaplet.s    144
 6562
 6563             * File  hpgccaplet.s    145
 6564 00580 35040         CON(5)  =ONE
 6565             * **Initial menu page**
 6566             * File  hpgccaplet.s    146
 6567
 6568             * File  hpgccaplet.s    147
 6569 00585 56670         CON(5)  ='
 6570             * **Error object**
 6571             * File  hpgccaplet.s    148
 6572 0058A D9D20         CON(5)  =DOCOL
 6573 0058F 6D3F3         CON(5)  =TURNMENUON
 6574 00594 6C3F1         CON(5)  =RECLAIMDISP
 6575 00599 FC650         CON(5)  =ERRJMP
 6576 0059E B2130         CON(5)  =SEMI
 6577             * File  hpgccaplet.s    149
 6578 005A3 B2130         CON(5)  =SEMI
 6579             * File  hpgccaplet.s    150
 6580
 6581             * File  hpgccaplet.s    151
 6582 005A8       =_Entry
 6583             * File  hpgccaplet.s    152
 6584 005A8 D9D20         CON(5)  =DOCOL
 6585             * File  hpgccaplet.s    153
 6586
 6587             *   GET SAVED APLET DATA
 6588             * File  hpgccaplet.s    155
 6589
 6590             * File  hpgccaplet.s    156
 6591 005AD D2982         CON(5)  =LastBut3
 6592 005B2 F8040         CON(5)  =SEVEN
 6593 005B7 674F0         CON(5)  =NTHCOMPDROP
 6594             * File  hpgccaplet.s    157
 6595 005BC 1AC21         CON(5)  =TopicVar1!
 6596             * File  hpgccaplet.s    158
 6597
 6598             * File  hpgccaplet.s    159
 6599
 6600             *   CUSTOMIZABLE SPLASHSCREEN
 6601             * File  hpgccaplet.s    161
 6602
 6603             * File  hpgccaplet.s    162
 6604 005C1 D2982         CON(5)  =LastBut3
 6605 005C6 86C50         CON(5)  =INNERCOMP
 6606 005CB 368F0         CON(5)  =ROLLDROP
 6607 005D0 44230         CON(5)  =DROP
 6608             * File  hpgccaplet.s    163
 6609
 6610             * File  hpgccaplet.s    164
 6611 005D5 29E20         CON(5)  =DOROMP
 6612 005DA 31110         CON(6)  =~xShSPLASH
            0
 6613             * File  hpgccaplet.s    165
 6614
 6615             * File  hpgccaplet.s    166
 6616 005E0 B2130         CON(5)  =SEMI
 6617             * File  hpgccaplet.s    167
 6618
 6619             * File  hpgccaplet.s    168
 6620 005E5       =_Exit
 6621             * File  hpgccaplet.s    169
 6622 005E5 D9D20         CON(5)  =DOCOL
 6623             * File  hpgccaplet.s    170
 6624
 6625             *   SAVE APLET DATA AS PERMANENT
 6626             * File  hpgccaplet.s    172
 6627
 6628             * File  hpgccaplet.s    173
 6629 005EA D2982         CON(5)  =LastBut3
 6630             * File  hpgccaplet.s    174
 6631 005EF 86C50         CON(5)  =INNERCOMP
 6632             * File  hpgccaplet.s    175
 6633 005F4 CFC21         CON(5)  =TopicVar1@
 6634             * File  hpgccaplet.s    176
 6635 005F9 EECC0         CON(5)  =ROTDROPSWAP
 6636             * File  hpgccaplet.s    177
 6637 005FE 21C50         CON(5)  ={}N
 6638             * File  hpgccaplet.s    178
 6639 00603 D2982         CON(5)  =LastBut3
 6640 00608 9DE80         CON(5)  =REPLACE
 6641 0060D 44230         CON(5)  =DROP
 6642             * File  hpgccaplet.s    179
 6643
 6644             * File  hpgccaplet.s    180
 6645 00612 5E083         CON(5)  =LeaveGraphView
 6646             * File  hpgccaplet.s    181
 6647 00617 B2130         CON(5)  =SEMI
 6648             * File  hpgccaplet.s    182
 6649
 6650             * File  hpgccaplet.s    183
 6651 0061C       =_Action
 6652             * File  hpgccaplet.s    184
 6653 0061C D9D20         CON(5)  =DOCOL
 6654             * File  hpgccaplet.s    185
 6655
 6656             * PASS CURRENT VIEW NUMBER
 6657             * File  hpgccaplet.s    187
 6658
 6659             *  ( # may be:  ApLet entered by:       )
 6660             *  ( ZERO       plot view               )
 6661             *  ( ONE        plot setup view         )
 6662             *  ( TWO        numeric view            )
 6663             *  ( THREE      numeric setup view      )
 6664             *  ( FOUR       symbolic view           )
 6665             *  ( FIVE       symbolic. setup view    )
 6666             *  ( SIX        note view               )
 6667             *  ( SEVEN      sketch view             )
 6668             * File  hpgccaplet.s    197
 6669
 6670             * File  hpgccaplet.s    198
 6671 00621 DFC21         CON(5)  =TopicVar2@
 6672             * File  hpgccaplet.s    199
 6673
 6674             * File  hpgccaplet.s    200
 6675
 6676             * PASS SAVED DATA THROUGH STACK
 6677             * File  hpgccaplet.s    202
 6678 00626 CFC21         CON(5)  =TopicVar1@
 6679             * File  hpgccaplet.s    203
 6680
 6681             * File  hpgccaplet.s    204
 6682 0062B D2982         CON(5)  =LastBut3
 6683 00630 24850         CON(5)  =CARCOMP
 6684             * File  hpgccaplet.s    205
 6685
 6686             * File  hpgccaplet.s    206
 6687 00635 29E20         CON(5)  =DOROMP
 6688 0063A 31100         CON(6)  =~xPrRUN
            0
 6689             * File  hpgccaplet.s    207
 6690
 6691             * STORE POSSIBLY MODIFIED DATA
 6692             * File  hpgccaplet.s    209
 6693 00640 1AC21         CON(5)  =TopicVar1!
 6694             * File  hpgccaplet.s    210
 6695
 6696             * DROP THE VIEW NUMBER
 6697             * File  hpgccaplet.s    212
 6698
 6699             * File  hpgccaplet.s    213
 6700 00645 44230         CON(5)  =DROP
 6701             * File  hpgccaplet.s    214
 6702
 6703             * File  hpgccaplet.s    215
 6704 0064A B2130         CON(5)  =SEMI
 6705             * File  hpgccaplet.s    216
 6706
 6707             * File  hpgccaplet.s    217
 6708
 6709             * File  hpgccaplet.s    218
 6710 0064F       =_Reset
 6711             * File  hpgccaplet.s    219
 6712
 6713             * ADD/REMOVE THE NOP BELOW TO KEEP THE BYTE-ALIGNMENT
 6714             * File  hpgccaplet.s    221
 6715 0064F D9D20         CON(5)  =DOCOL
 6716             * File  hpgccaplet.s    222
 6717
 6718             * File  hpgccaplet.s    223
 6719 00654 D2982         CON(5)  =LastBut3
 6720             * File  hpgccaplet.s    224
 6721 00659 86C50         CON(5)  =INNERCOMP
 6722             * File  hpgccaplet.s    225
 6723 0065E 2AD50         CON(5)  =NULL{}
 6724             * File  hpgccaplet.s    226
 6725 00663 EECC0         CON(5)  =ROTDROPSWAP
 6726             * File  hpgccaplet.s    227
 6727 00668 21C50         CON(5)  ={}N
 6728             * File  hpgccaplet.s    228
 6729 0066D D2982         CON(5)  =LastBut3
 6730 00672 9DE80         CON(5)  =REPLACE
 6731 00677 44230         CON(5)  =DROP
 6732             * File  hpgccaplet.s    229
 6733
 6734             * File  hpgccaplet.s    230
 6735 0067C B2130         CON(5)  =SEMI
 6736             * File  hpgccaplet.s    231
 6737
 6738             * File  hpgccaplet.s    232
 6739 00681       =_About
 6740             * File  hpgccaplet.s    233
 6741 00681 D9D20         CON(5)  =DOCOL
 6742             * File  hpgccaplet.s    234
 6743
 6744             * File  hpgccaplet.s    235
 6745 00686 29E20         CON(5)  =DOROMP
 6746 0068B 31120         CON(6)  =~xHpgccABOUT
            0
 6747             * File  hpgccaplet.s    236
 6748
 6749             * File  hpgccaplet.s    237
 6750 00691 B2130         CON(5)  =SEMI
 6751             * File  hpgccaplet.s    238
 6752
 6753             * File  hpgccaplet.s    239
 6754             * ASSEMBLE
 6755             * File  hpgccaplet.s    240
 6756 00696       endCode
 6757             * File  hpgccaplet.s    241
 6758             * RPL
 6759             * File  hpgccaplet.s    242
 6760
 6761             * File  hpgccaplet.s    243
 6762
 6763             *****************************************************************************
 6764             *               PARAMETER
 6765             *****************************************************************************
 6766             * File  hpgccaplet.s    247
 6767
 6768             * File  hpgccaplet.s    248
 6769             * ASSEMBLE
 6770             * File  hpgccaplet.s    249
 6771 00696               Vfield DirVar,DirCode
 6772             * File  hpgccaplet.s    250
 6773             * RPL
 6774             * File  hpgccaplet.s    251
 6775 0069D 47A20         CON(5)  =DOLIST
 6776             * File  hpgccaplet.s    252
 6777 006A2 C2A20         CON(5)  =DOCSTR
 6778 006A7 32000         CON(5)  35
 6779 006AC 1425D         NIBASC  \ARMCODE HERE!!!\
            434F4
            44540284542554121212

 6780             * File  hpgccaplet.s    253
 6781 006CA C2A20         CON(5)  =DOCSTR
 6782 006CF 50000         CON(5)  5
 6783             * File  hpgccaplet.s    254
 6784 006D4 C2A20         CON(5)  =DOCSTR
 6785 006D9 50000         CON(5)  5
 6786             * File  hpgccaplet.s    255
 6787 006DE E1B20         CON(5)  =DOGROB
 6788 006E3 11000         CON(5)  17
 6789 006E8 10000         NIBHEX  100001000000
            10000
            00
 6790             * File  hpgccaplet.s    256
 6791 006F4 11920         CON(5)  =DOBINT
 6792 006F9 00000         CON(5)  0
 6793             * File  hpgccaplet.s    257
 6794 006FE 11920         CON(5)  =DOBINT
 6795 00703 00000         CON(5)  0
 6796             * APPLICATION CUSTOM DATA HERE
 6797             * File  hpgccaplet.s    259
 6798 00708 47A20         CON(5)  =DOLIST
 6799 0070D B2130         CON(5)  =SEMI
 6800             * File  hpgccaplet.s    260
 6801 00712 B2130         CON(5)  =SEMI
 6802             * File  hpgccaplet.s    261
 6803
 6804             * File  hpgccaplet.s    262
 6805             * ASSEMBLE
 6806             * File  hpgccaplet.s    263
 6807 00717               Vfield DirCode,DirAlt
 6808             * File  hpgccaplet.s    264
 6809             * RPL
 6810             * File  hpgccaplet.s    265
 6811 0071E 47A20         CON(5)  =DOLIST
 6812 00723 B2130         CON(5)  =SEMI
 6813             * File  hpgccaplet.s    266
 6814
 6815             * File  hpgccaplet.s    267
 6816             * ASSEMBLE
 6817             * File  hpgccaplet.s    268
 6818 00728               Vfield DirAlt,DirNot
 6819             * File  hpgccaplet.s    269
 6820             * RPL
 6821             * File  hpgccaplet.s    270
 6822 0072F C2A20         CON(5)  =DOCSTR
 6823 00734 50000         CON(5)  5
 6824             * File  hpgccaplet.s    271
 6825
 6826             * File  hpgccaplet.s    272
 6827             * ASSEMBLE
 6828             * File  hpgccaplet.s    273
 6829 00739               Vfield DirNot,DirEnd
 6830             * File  hpgccaplet.s    274
 6831             * RPL
 6832             * File  hpgccaplet.s    275
 6833 00740 47A20         CON(5)  =DOLIST
 6834 00745 B2130         CON(5)  =SEMI
Saturn Assembler    HPGCC Aplet Template               Mon Jun 27 16:00:01 2022
V3.0.8 (12/06/2002)   Symbol Table                       hpgccaplet.c   Page    2

=!!append$                         Abs   57163 #0000DF4B -    14
=!*triand                          Abs   50520 #0000C558 -    15
=!>ARRAY                           Abs   80626 #00013AF2 -    16
=!MATTRNnc                         Abs  260071 #0003F7E7 -    17
=!REDIMTEMP                        Abs  260107 #0003F80B -    18
=!REDIMUSER                        Abs  260108 #0003F80C -    19
=!append$                          Abs   57121 #0000DF21 -    20
=!append$SWAP                      Abs   63497 #0000F809 -    21
=#*                                Abs   16146 #00003F12 -    22
=#*OVF                             Abs   80403 #00013A13 -    23
=#+                                Abs   15804 #00003DBC -    24
=#+#2-                             Abs  260100 #0003F804 -    25
=#+DUP                             Abs   58192 #0000E350 -    26
=#+OVER                            Abs   63794 #0000F932 -    27
=#+PICK                            Abs   53104 #0000CF70 -    28
=#+ROLL                            Abs   53302 #0000D036 -    29
=#+SWAP                            Abs   63192 #0000F6D8 -    30
=#+UNROLL                          Abs   53398 #0000D096 -    31
=#-                                Abs   15840 #00003DE0 -    32
=#-#2/                             Abs   57510 #0000E0A6 -    33
=#-OVER                            Abs   63814 #0000F946 -    34
=#-PICK                            Abs   53086 #0000CF5E -    35
=#-ROLL                            Abs   53284 #0000D024 -    36
=#-SWAP                            Abs   63212 #0000F6EC -    37
=#-UNROLL                          Abs   53380 #0000D084 -    38
=#/                                Abs   16199 #00003F47 -    39
=#0<>                              Abs   15559 #00003CC7 -    40
=#0=                               Abs   15526 #00003CA6 -    41
=#0=?SEMI                          Abs   54753 #0000D5E1 -    42
=#0=?SKIP                          Abs   64546 #0000FC22 -    43
=#0=ITE                            Abs   67332 #00010704 -    44
=#0=UNTIL                          Abs   62642 #0000F4B2 -    45
=#0=case                           Abs   54367 #0000D45F -    46
=#1+                               Abs   15855 #00003DEF -    47
=#1+'                              Abs   66122 #0001024A -    48
=#1+LAST$                          Abs   64361 #0000FB69 -    49
=#1+NDROP                          Abs   63567 #0000F84F -    50
=#1+PICK                           Abs   53135 #0000CF8F -    51
=#1+ROLL                           Abs   53323 #0000D04B -    52
=#1+SWAP                           Abs   63232 #0000F700 -    53
=#1+UNROLL                         Abs   53419 #0000D0AB -    54
=#1+_ONE_DO                        Abs   31668 #00007BB4 -    55
=#1-                               Abs   15886 #00003E0E -    56
=#1-1SWAP                          Abs   63272 #0000F728 -    57
=#1-ROT                            Abs   63674 #0000F8BA -    58
=#1-SUB$                           Abs   64301 #0000FB2D -    59
=#1-{}N                            Abs   64141 #0000FA8D -    60
=#1<>                              Abs   56929 #0000DE61 -    61
=#1=                               Abs   56914 #0000DE52 -    62
=#1=?SKIP                          Abs   64587 #0000FC4B -    63
=#1=case                           Abs   66977 #000105A1 -    64
=#2*                               Abs   15983 #00003E6F -    65
=#2+                               Abs   15917 #00003E2D -    66
=#2+PICK                           Abs   53162 #0000CFAA -    67
=#2+ROLL                           Abs   53360 #0000D070 -    68
=#2+UNROLL                         Abs   53437 #0000D0BD -    69
=#2-                               Abs   15950 #00003E4E -    70
=#2/                               Abs   16014 #00003E8E -    71
=#2<>                              Abs   65447 #0000FFA7 -    72
=#2=                               Abs   56901 #0000DE45 -    73
=#3+                               Abs   57681 #0000E151 -    74
=#3+PICK                           Abs   53182 #0000CFBE -    75
=#3-                               Abs   57651 #0000E133 -    76
=#3=                               Abs   56884 #0000DE34 -    77
=#4+                               Abs   57686 #0000E156 -    78
=#4+PICK                           Abs   53197 #0000CFCD -    79
=#5+                               Abs   57691 #0000E15B -    80
=#5=                               Abs   65427 #0000FF93 -    81
=#8+                               Abs   57706 #0000E16A -    82
=#<                                Abs   15588 #00003CE4 -    83
=#<3                               Abs   65362 #0000FF52 -    84
=#<=                               Abs  225537 #00037101 -    85
=#<>                               Abs   15694 #00003D4E -    86
=#<>case                           Abs   66997 #000105B5 -    87
=#<ITE                             Abs   67352 #00010718 -    88
=#<case                            Abs   66957 #0001058D -    89
=#=                                Abs   15641 #00003D19 -    90
=#=?SKIP                           Abs   64612 #0000FC64 -    91
=#=ITE                             Abs   62727 #0000F507 -    92
=#=Lookup                          Abs   88840 #00015B08 -    93
=#=POSCOMP                         Abs   67782 #000108C6 -    94
=#=case                            Abs   54325 #0000D435 -    95
=#=casedrop                        Abs   54428 #0000D49C -    96
=#=casedrpfls                      Abs   65087 #0000FE3F -    97
=#>                                Abs   15747 #00003D83 -    98
=#>$                               Abs  137772 #00021A2C -    99
=#>1                               Abs   65487 #0000FFCF -   100
=#>2case                           Abs   67017 #000105C9 -   101
=#>=                               Abs  225512 #000370E8 -   102
=#>?SKIP                           Abs   64657 #0000FC91 -   103
=#>CHR                             Abs   25134 #0000622E -   104
=#>HXS                             Abs   24965 #00006185 -   105
=#>ITE                             Abs   67372 #0001072C -   106
=#>ROMPTR                          Abs   34669 #0000876D -   107
=#>case                            Abs   67042 #000105E2 -   108
=#AND                              Abs   16097 #00003EE1 -   109
=#CAlarmErr                        Abs   73347 #00011E83 -   110
=#DIV                              Abs  225436 #0003709C -   111
=#EXITERR                          Abs   73367 #00011E97 -   112
=#Error:                           Abs   72807 #00011C67 -   113
=#MAX                              Abs   57457 #0000E071 -   114
=#MIN                              Abs   57445 #0000E065 -   115
=#MOD                              Abs  225475 #000370C3 -   116
=#NEG                              Abs  225415 #00037087 -   117
=#NOT                              Abs   16049 #00003EB1 -   118
=#NoRoomForSt                      Abs   72787 #00011C53 -   119
=#ODD                              Abs  225558 #00037116 -   120
=#OR                               Abs   16080 #00003ED0 -   121
=#ObTypeBase                       Abs   72737 #00011C21 -   122
=#SyntaxErr                        Abs   72727 #00011C17 -   123
=#THREESEVEN                       Abs   17007 #0000426F -   124
=#Warning:NL                       Abs   72797 #00011C5D -   125
=#XOR                              Abs   16114 #00003EF2 -   126
=#_102                             Abs   72717 #00011C0D -   127
=#_123                             Abs   72767 #00011C3F -   128
=#_124                             Abs   72777 #00011C49 -   129
=#_205                             Abs   72937 #00011CE9 -   130
=#_258_d                           Abs   72717 #00011C0D -   131
=#_291_d                           Abs   72767 #00011C3F -   132
=#_292_d                           Abs   72777 #00011C49 -   133
=#_517_d                           Abs   72937 #00011CE9 -   134
=$>BIGGROB                         Abs  122238 #0001DD7E -   135
=$>GROB                            Abs  122251 #0001DD8B -   136
=$>ID                              Abs   25294 #000062CE -   137
=$>grob                            Abs  122796 #0001DFAC -   138
=$DER                              Abs   74960 #000124D0 -   139
=$_''                              Abs   68977 #00010D71 -   140
=$_2DQ                             Abs   69019 #00010D9B -   141
=$_::                              Abs   68991 #00010D7F -   142
=$_<<>>                            Abs   68935 #00010D47 -   143
=$_ECHO                            Abs   69033 #00010DA9 -   144
=$_EXIT                            Abs   69051 #00010DBB -   145
=$_GRAD                            Abs   69113 #00010DF9 -   146
=$_LRParens                        Abs   69005 #00010D8D -   147
=$_R<<                             Abs   68887 #00010D17 -   148
=$_R<Z                             Abs   68903 #00010D27 -   149
=$_RAD                             Abs   69097 #00010DE9 -   150
=$_Undefined                       Abs   69069 #00010DCD -   151
=$_XYZ                             Abs   68919 #00010D37 -   152
=$_{}                              Abs   68949 #00010D55 -   153
=$jADJMEM                          Abs   62080 #0000F280 -   154
=$jAINRTN                          Abs   62087 #0000F287 -   155
=$jAllowIntr                       Abs   62094 #0000F28E -   156
=$jBITMAP                          Abs   62101 #0000F295 -   157
=$jCINRTN                          Abs   62122 #0000F2AA -   158
=$jCREATETEMP                      Abs   62129 #0000F2B1 -   159
=$jChkLowBat                       Abs   62108 #0000F29C -   160
=$jD0=DSKTOP                       Abs   62136 #0000F2B8 -   161
=$jD1=DSKTOP                       Abs   62143 #0000F2BF -   162
=$jDOGARBAGE                       Abs   62164 #0000F2D4 -   163
=$jDOMEMERR                        Abs   62171 #0000F2DB -   164
=$jDebounce                        Abs   62150 #0000F2C6 -   165
=$jDupAndThen                      Abs   62178 #0000F2E2 -   166
=$jECUSER                          Abs   62192 #0000F2F0 -   167
=$jErrjmp                          Abs   62185 #0000F2E9 -   168
=$jGARBAGECOL                      Abs   62199 #0000F2F7 -   169
=$jGETPIX                          Abs   62206 #0000F2FE -   170
=$jGETPIX3                         Abs   62213 #0000F305 -   171
=$jGETPTR                          Abs   62220 #0000F30C -   172
=$jGETPTRLOOP                      Abs   62227 #0000F313 -   173
=$jGETTEMP                         Abs   62234 #0000F31A -   174
=$jGPMEMERR                        Abs   62241 #0000F321 -   175
=$jGPOvrWrFLp                      Abs   62248 #0000F328 -   176
=$jGPOvrWrTLp                      Abs   62262 #0000F336 -   177
=$jMAKE$                           Abs   62290 #0000F352 -   178
=$jMAKE$N                          Abs   62297 #0000F359 -   179
=$jMOVEDOWN                        Abs   62318 #0000F36E -   180
=$jMOVEDSD                         Abs   62325 #0000F375 -   181
=$jMOVEDSU                         Abs   62332 #0000F37C -   182
=$jMOVERSD                         Abs   62339 #0000F383 -   183
=$jMOVERSU                         Abs   62346 #0000F38A -   184
=$jMOVEUP                          Abs   62353 #0000F391 -   185
=$jMUL#                            Abs   62360 #0000F398 -   186
=$jOvrWrF/TLp                      Abs   62367 #0000F39F -   187
=$jOvrWrFLoop                      Abs   62374 #0000F3A6 -   188
=$jOvrWrT/FLp                      Abs   62381 #0000F3AD -   189
=$jOvrWrTLoop                      Abs   62388 #0000F3B4 -   190
=$jPOP#                            Abs   62402 #0000F3C2 -   191
=$jPOP1%                           Abs   62416 #0000F3D0 -   192
=$jPOP2#                           Abs   62409 #0000F3C9 -   193
=$jPOP2%                           Abs   62423 #0000F3D7 -   194
=$jPUSH#                           Abs   62430 #0000F3DE -   195
=$jPUSH#ALOOP                      Abs   62444 #0000F3EC -   196
=$jPUSH#LOOP                       Abs   62451 #0000F3F3 -   197
=$jPUSH%                           Abs   62458 #0000F3FA -   198
=$jPUSH%LOOP                       Abs   62465 #0000F401 -   199
=$jPUSH2#                          Abs   62437 #0000F3E5 -   200
=$jPUSHA                           Abs   62472 #0000F408 -   201
=$jPshF/TLoop                      Abs   62479 #0000F40F -   202
=$jPshT/FLoop                      Abs   62486 #0000F416 -   203
=$jPushFLoop                       Abs   62500 #0000F424 -   204
=$jPushTLoop                       Abs   62493 #0000F41D -   205
=$jSAVPTR                          Abs   62507 #0000F42B -   206
=$jSKIPBODY                        Abs   62521 #0000F439 -   207
=$jSKIPOB                          Abs   62514 #0000F432 -   208
=$jWIPEOUT                         Abs   62528 #0000F440 -   209
=$jWindowXY                        Abs   62535 #0000F447 -   210
=$jcorner                          Abs   62115 #0000F2A3 -   211
=$jmakebeep                        Abs   62304 #0000F360 -   212
=$jmakegrob                        Abs   62311 #0000F367 -   213
=$jpixon2                          Abs   62395 #0000F3BB -   214
=%%-1                              Abs   91707 #0001663B -   215
=%%.1                              Abs   74113 #00012181 -   216
=%%.5                              Abs   74139 #0001219B -   217
=%%/>%                             Abs   66557 #000103FD -   218
=%%0                               Abs   73957 #000120E5 -   219
=%%1                               Abs   73983 #000120FF -   220
=%%10                              Abs   74165 #000121B5 -   221
=%%2                               Abs   74009 #00012119 -   222
=%%3                               Abs   74035 #00012133 -   223
=%%4                               Abs   74061 #0001214D -   224
=%%5                               Abs   74087 #00012167 -   225
=%%>%                              Abs  111595 #0001B3EB -   226
=%%PI                              Abs   73847 #00012077 -   227
=%*                                Abs  112861 #0001B8DD -   228
=%+                                Abs  112789 #0001B895 -   229
=%-                                Abs  112802 #0001B8A2 -   230
=%-.5                              Abs   74233 #000121F9 -   231
=%-1                               Abs   73637 #00011FA5 -   232
=%-2                               Abs   73658 #00011FBA -   233
=%-3                               Abs   73679 #00011FCF -   234
=%-4                               Abs   73700 #00011FE4 -   235
=%-5                               Abs   73721 #00011FF9 -   236
=%-6                               Abs   73742 #0001200E -   237
=%-7                               Abs   73763 #00012023 -   238
=%-8                               Abs   73784 #00012038 -   239
=%-9                               Abs   73805 #0001204D -   240
=%-MAXREAL                         Abs   73894 #000120A6 -   241
=%-MINREAL                         Abs   73936 #000120D0 -   242
=%.5                               Abs   74212 #000121E4 -   243
=%/                                Abs  112927 #0001B91F -   244
=%0                                Abs   73427 #00011ED3 -   245
=%0<                               Abs  112217 #0001B659 -   246
=%0<>                              Abs  112368 #0001B6F0 -   247
=%0=                               Abs  112268 #0001B68C -   248
=%0>                               Abs  112314 #0001B6BA -   249
=%0>=                              Abs  112408 #0001B718 -   250
=%0AllTOLVars                      Abs   76016 #000128F0 -   251
=%0AllTopicVs                      Abs   75957 #000128B5 -   252
=%0TOLVarSet                       Abs   76280 #000129F8 -   253
=%1                                Abs   73448 #00011EE8 -   254
=%10                               Abs   74254 #0001220E -   255
=%15                               Abs   74359 #00012277 -   256
=%180                              Abs   74632 #00012388 -   257
=%2                                Abs   73469 #00011EFD -   258
=%200                              Abs   74653 #0001239D -   259
=%25                               Abs   74569 #00012349 -   260
=%3                                Abs   73490 #00011F12 -   261
=%360                              Abs   74674 #000123B2 -   262
=%4                                Abs   73511 #00011F27 -   263
=%400                              Abs   74695 #000123C7 -   264
=%5                                Abs   73532 #00011F3C -   265
=%6                                Abs   73553 #00011F51 -   266
=%7                                Abs   73574 #00011F66 -   267
=%8                                Abs   73595 #00011F7B -   268
=%9                                Abs   73616 #00011F90 -   269
=%<                                Abs  112530 #0001B792 -   270
=%<=                               Abs  112599 #0001B7D7 -   271
=%<>                               Abs  112621 #0001B7ED -   272
=%=                                Abs  112610 #0001B7E2 -   273
=%>                                Abs  112555 #0001B7AB -   274
=%>%%                              Abs  111612 #0001B3FC -   275
=%>%%SWAP                          Abs   63337 #0000F769 -   276
=%>=                               Abs  112577 #0001B7C1 -   277
=%>C%                              Abs   25646 #0000642E -   278
=%>HMS                             Abs  112020 #0001B594 -   279
=%ABS                              Abs  112673 #0001B821 -   280
=%ABSCOERCE                        Abs   78385 #00013231 -   281
=%ACOS                             Abs  113682 #0001BC12 -   282
=%ACOSH                            Abs  113972 #0001BD34 -   283
=%ALOG                             Abs  113371 #0001BADB -   284
=%ANGLE                            Abs  113753 #0001BC59 -   285
=%ASIN                             Abs  113634 #0001BBE2 -   286
=%ASINH                            Abs  113953 #0001BD21 -   287
=%ATAN                             Abs  113730 #0001BC42 -   288
=%ATANH                            Abs  113991 #0001BD47 -   289
=%CEIL                             Abs  114324 #0001BE94 -   290
=%CH                               Abs  112977 #0001B951 -   291
=%CHS                              Abs  112705 #0001B841 -   292
=%COMB                             Abs  114051 #0001BD83 -   293
=%COS                              Abs  113505 #0001BB61 -   294
=%COSH                             Abs  113915 #0001BCFB -   295
=%D>R                              Abs  111939 #0001B543 -   296
=%EXP                              Abs  113232 #0001BA50 -   297
=%EXPM1                            Abs  113251 #0001BA63 -   298
=%EXPONENT                         Abs  114010 #0001BD5A -   299
=%FACT                             Abs  114661 #0001BFE5 -   300
=%FLOOR                            Abs  114343 #0001BEA7 -   301
=%FP                               Abs  114286 #0001BE6E -   302
=%HMS+                             Abs  112065 #0001B5C1 -   303
=%HMS-                             Abs  112105 #0001B5E9 -   304
=%HMS>                             Abs  112045 #0001B5AD -   305
=%IP                               Abs  114305 #0001BE81 -   306
=%LN                               Abs  113295 #0001BA8F -   307
=%LNP1                             Abs  113352 #0001BAC8 -   308
=%LOG                              Abs  113314 #0001BAA2 -   309
=%MANTISSA                         Abs  112721 #0001B851 -   310
=%MAX                              Abs  112150 #0001B616 -   311
=%MAXREAL                          Abs   73873 #00012091 -   312
=%MAXorder                         Abs   63067 #0000F65B -   313
=%MIN                              Abs  112175 #0001B62F -   314
=%MINREAL                          Abs   73915 #000120BB -   315
=%MOD                              Abs  113405 #0001BAFD -   316
=%NFACT                            Abs  114029 #0001BD6D -   317
=%NROOT                            Abs  113058 #0001B9A2 -   318
=%OF                               Abs  112874 #0001B8EA -   319
=%PERM                             Abs  114070 #0001BD96 -   320
=%PI                               Abs   73826 #00012062 -   321
=%POL>%REC                         Abs  115676 #0001C3DC -   322
=%R>D                              Abs  111990 #0001B576 -   323
=%RAN                              Abs  114403 #0001BEE3 -   324
=%RANDOMIZE                        Abs  114533 #0001BF65 -   325
=%REC>%POL                         Abs  115631 #0001C3AF -   326
=%SGN                              Abs  112632 #0001B7F8 -   327
=%SIN                              Abs  113424 #0001BB10 -   328
=%SINH                             Abs  113871 #0001BCCF -   329
=%SPH>%REC                         Abs  115731 #0001C413 -   330
=%SQRT                             Abs  113194 #0001BA2A -   331
=%T                                Abs  112940 #0001B92C -   332
=%TAN                              Abs  113586 #0001BBB2 -   333
=%TANH                             Abs  113934 #0001BD0E -   334
=%^                                Abs  113041 #0001B991 -   335
=%e                                Abs   74191 #000121CF -   336
=&$                                Abs   22855 #00005947 -   337
=&$SWAP                            Abs   67557 #000107E5 -   338
=&&                                Abs  258174 #0003F07E -   339
=&COMP                             Abs   22995 #000059D3 -   340
='                                 Abs   30309 #00007665 -   341  6466  6470
                                        6476  6486  6569
='DROPFALSE                        Abs  159283 #00026E33 -   342
='DoBadKey                         Abs  147274 #00023F4A -   343
='DoBadKeyT                        Abs  147294 #00023F5E -   344
='ERRJMP                           Abs   64061 #0000FA3D -   345
='LAMLNAMESTO                      Abs   66237 #000102BD -   346
='NOP                              Abs   64421 #0000FBA5 -   347
='R                                Abs   30393 #000076B9 -   348
='R'R                              Abs   66142 #0001025E -   349
='REVAL                            Abs   30516 #00007734 -   350
='RRDROP                           Abs   66172 #0001027C -   351
='RSWP1+                           Abs   85652 #00014E94 -   352
='Rapndit                          Abs   85385 #00014D89 -   353
='xDER                             Abs   66537 #000103E9 -   354
='xDEREQ                           Abs   66262 #000102D6 -   355
=+LOOP                             Abs   31614 #00007B7E -   356
=0LASTOWDOB!                       Abs  144039 #000232A7 -   357
=10GETLAM                          Abs   53705 #0000D1C9 -   358
=10PICK                            Abs   53249 #0000D001 -   359
=10PUTLAM                          Abs   53700 #0000D1C4 -   360
=10UNROLL                          Abs   64014 #0000FA0E -   361
=11GETLAM                          Abs   53715 #0000D1D3 -   362
=11PUTLAM                          Abs   53710 #0000D1CE -   363
=12GETLAM                          Abs   53725 #0000D1DD -   364
=12PUTLAM                          Abs   53720 #0000D1D8 -   365
=13GETLAM                          Abs   53735 #0000D1E7 -   366
=13PUTLAM                          Abs   53730 #0000D1E2 -   367
=14GETLAM                          Abs   53745 #0000D1F1 -   368
=14PUTLAM                          Abs   53740 #0000D1EC -   369
=14SPACES$                         Abs   74910 #0001249E -   370
=15GETLAM                          Abs   53755 #0000D1FB -   371
=15PUTLAM                          Abs   53750 #0000D1F6 -   372
=16GETLAM                          Abs   53765 #0000D205 -   373
=16PUTLAM                          Abs   53760 #0000D200 -   374
=17GETLAM                          Abs   53775 #0000D20F -   375
=17PUTLAM                          Abs   53770 #0000D20A -   376
=18GETLAM                          Abs   53785 #0000D219 -   377
=18PUTLAM                          Abs   53780 #0000D214 -   378
=19GETLAM                          Abs   53795 #0000D223 -   379
=19PUTLAM                          Abs   53790 #0000D21E -   380
=1ABNDSWAP                         Abs   63117 #0000F68D -   381
=1GETABND                          Abs   64942 #0000FDAE -   382
=1GETLAM                           Abs   53615 #0000D16F -   383
=1GETLAM#0=                        Abs   67742 #0001089E -   384
=1GETSWAP                          Abs   63457 #0000F7E1 -   385
=1GETapndcpl                       Abs  258703 #0003F28F -   386
=1LAMBIND                          Abs   64967 #0000FDC7 -   387
=1NULLLAM{}                        Abs   68086 #000109F6 -   388
=1PUTLAM                           Abs   53610 #0000D16A -   389
=1_#1-SUB                          Abs   64321 #0000FB41 -   390
=1_#1-SUB$                         Abs   64321 #0000FB41 -   391
=1getcxt!                          Abs   76360 #00012A48 -   392
=2#0=OR                            Abs   65292 #0000FF0C -   393
=2'RCOLARPITE                      Abs   54962 #0000D6B2 -   394
=20GETLAM                          Abs   53805 #0000D22D -   395
=20PUTLAM                          Abs   53800 #0000D228 -   396
=21GETLAM                          Abs   53815 #0000D237 -   397
=21PUTLAM                          Abs   53810 #0000D232 -   398
=22GETLAM                          Abs   53825 #0000D241 -   399
=22PUTLAM                          Abs   53820 #0000D23C -   400
=2ARRY                             Abs   17137 #000042F1 -   401
=2CDispList                        Abs  259570 #0003F5F2 -   402
=2CKeyOK                           Abs  259571 #0003F5F3 -   403
=2Col?Case2Col                     Abs   85822 #00014F3E -   404
=2ColChoose                        Abs  259497 #0003F5A9 -   405
=2DROP                             Abs   12888 #00003258 -   406
=2DROP00                           Abs   57593 #0000E0F9 -   407
=2DROPFALSE                        Abs   62542 #0000F44E -   408
=2DUP                              Abs   12716 #000031AC -   409
=2DUP#+                            Abs   65507 #0000FFE3 -   410
=2DUP#<                            Abs   58390 #0000E416 -   411
=2DUP#=                            Abs   58416 #0000E430 -   412
=2DUP#>                            Abs   58444 #0000E44C -   413
=2DUP5ROLL                         Abs   66747 #000104BB -   414
=2DUPEQ                            Abs   65232 #0000FED0 -   415
=2EXT                              Abs   18837 #00004995 -   416
=2GETEVAL                          Abs   64461 #0000FBCD -   417
=2GETLAM                           Abs   53625 #0000D179 -   418
=2GROB                             Abs   18497 #00004841 -   419
=2HXS                              Abs   18327 #00004797 -   420
=2LIST                             Abs   17307 #0000439B -   421
=2OVER                             Abs   67637 #00010835 -   422
=2Ob>Seco                          Abs   67702 #00010876 -   423
=2PUTLAM                           Abs   53620 #0000D174 -   424
=2RDROP                            Abs   53050 #0000CF3A -   425
=2STR                              Abs   16967 #00004247 -   426
=2SWAP                             Abs   56187 #0000DB7B -   427
=3ARRY                             Abs   72977 #00011D11 -   428
=3DROP                             Abs   52523 #0000CD2B -   429
=3GETLAM                           Abs   53635 #0000D183 -   430
=3PICK                             Abs   53214 #0000CFDE -   431
=3PICK#+                           Abs   65567 #0001001F -   432
=3PICK3PICK                        Abs   66787 #000104E3 -   433
=3PICKOVER                         Abs   63894 #0000F996 -   434
=3PICKSWAP                         Abs   63417 #0000F7B9 -   435
=3PUTLAM                           Abs   53630 #0000D17E -   436
=3RDROP                            Abs   53068 #0000CF4C -   437
=3REAL                             Abs   72757 #00011C35 -   438
=3SYM                              Abs   73287 #00011E47 -   439
=3UNROLL                           Abs   52612 #0000CD84 -   440
=4DROP                             Abs   52528 #0000CD30 -   441
=4GETLAM                           Abs   53645 #0000D18D -   442
=4PICK                             Abs   53219 #0000CFE3 -   443
=4PICK#+                           Abs   65587 #00010033 -   444
=4PICK#+SWAP                       Abs   63167 #0000F6BF -   445
=4PICK+SWAP                        Abs   63167 #0000F6BF -   446
=4PICKOVER                         Abs   63914 #0000F9AA -   447
=4PICKSWAP                         Abs   63437 #0000F7CD -   448
=4PUTLAM                           Abs   53640 #0000D188 -   449
=4ROLL                             Abs   52627 #0000CD93 -   450
=4ROLLOVER                         Abs   63874 #0000F982 -   451
=4ROLLROT                          Abs   63714 #0000F8E2 -   452
=4ROLLSWAP                         Abs   63397 #0000F7A5 -   453
=4UNROLL                           Abs   52874 #0000CE8A -   454
=4UNROLL3DROP                      Abs   53032 #0000CF28 -   455
=4UNROLLDUP                        Abs   62947 #0000F5E3 -   456
=4UNROLLROT                        Abs   63734 #0000F8F6 -   457
=5DROP                             Abs   52533 #0000CD35 -   458
=5GETLAM                           Abs   53655 #0000D197 -   459
=5PICK                             Abs   53224 #0000CFE8 -   460
=5PUTLAM                           Abs   53650 #0000D192 -   461
=5ROLL                             Abs   52656 #0000CDB0 -   462
=5UNROLL                           Abs   52912 #0000CEB0 -   463
=6DROP                             Abs   52545 #0000CD41 -   464
=6GETLAM                           Abs   53665 #0000D1A1 -   465
=6PICK                             Abs   53229 #0000CFED -   466
=6PUTLAM                           Abs   53660 #0000D19C -   467
=6ROLL                             Abs   52698 #0000CDDA -   468
=6UNROLL                           Abs   52966 #0000CEE6 -   469
=7DROP                             Abs   52557 #0000CD4D -   470
=7GETLAM                           Abs   53675 #0000D1AB -   471
=7PICK                             Abs   53234 #0000CFF2 -   472
=7PUTLAM                           Abs   53670 #0000D1A6 -   473
=7ROLL                             Abs   52803 #0000CE43 -   474
=7UNROLL                           Abs   62622 #0000F49E -   475
=8GETLAM                           Abs   53685 #0000D1B5 -   476
=8PICK                             Abs   53239 #0000CFF7 -   477
=8PUTLAM                           Abs   53680 #0000D1B0 -   478
=8ROLL                             Abs   52756 #0000CE14 -   479
=8UNROLL                           Abs   63994 #0000F9FA -   480
=9GETLAM                           Abs   53695 #0000D1BF -   481
=9PICK                             Abs   53244 #0000CFFC -   482
=9PUTLAM                           Abs   53690 #0000D1BA -   483
=9ROLL                             Abs   52849 #0000CE71 -   484
=::N                               Abs   23550 #00005BFE -   485
=::NEVAL                           Abs   64441 #0000FBB9 -   486
=>H$                               Abs   23055 #00005A0F -   487
=>HCOMP                            Abs   23162 #00005A7A -   488
=>R                                Abs   30584 #00007778 -   489
=>T$                               Abs   23202 #00005AA2 -   490
=>TCOMP                            Abs   23214 #00005AAE -   491
=?>ROMPTR                          Abs   58844 #0000E5DC -   492
=?ATTNQUIT                         Abs  158129 #000269B1 -   493
=?AdjFocusPos                      Abs  259572 #0003F5F4 -   494
=?CARCOMP                          Abs   64101 #0000FA65 -   495
=?CaseKeyDef                       Abs  147464 #00024008 -   496
=?CaseRomptr@                      Abs  147514 #0002403A -   497
=?DispMenu                         Abs   69131 #00010E0B -   498
=?DispMoreU/D                      Abs  259573 #0003F5F5 -   499
=?ExitThisTop                      Abs  220687 #00035E0F -   500
=?FixFieldKeys                     Abs  259574 #0003F5F6 -   501
=?GetFObTypes                      Abs  259575 #0003F5F7 -   502
=?GetMsg                           Abs   89065 #00015BE9 -   503
=?NoTaskSwDef                      Abs  147559 #00024067 -   504
=?Ob>Seco                          Abs   67657 #00010849 -   505
=?ROMPTR>                          Abs   58879 #0000E5FF -   506
=?SEMI                             Abs   54788 #0000D604 -   507
=?SEMIDROP                         Abs   65892 #00010164 -   508
=?SKIP                             Abs   30979 #00007903 -   509
=?SKIPSWAP                         Abs   63097 #0000F679 -   510
=?SWAP                             Abs   63477 #0000F7F5 -   511
=?SWAPDROP                         Abs   63542 #0000F836 -   512
=@                                 Abs   33235 #000081D3 -   513
=@LAM                              Abs   32999 #000080E7 -   514
=ABND                              Abs   31856 #00007C70 -   515
=ABORT                             Abs   22178 #000056A2 -   516
=ABSCOERCE                         Abs   78390 #00013236 -   517
=ABUFF                             Abs  125295 #0001E96F -   518
=AGAIN                             Abs   31108 #00007984 -   519
=AND                               Abs   15174 #00003B46 -   520
=ANDITE                            Abs   67292 #000106DC -   521
=ANDNOTcase                        Abs   67162 #0001065A -   522
=ANDcase                           Abs   66917 #00010565 -   523
=APPEND_SPACE                      Abs   62602 #0000F48A -   524
=ARRYCMP                           Abs   17117 #000042DD -   525
=ARRYID                            Abs   17157 #00004305 -   526
=ARRYLIST                          Abs   17147 #000042FB -   527
=ARRYLISTCMP                       Abs   72997 #00011D25 -   528
=ARRYLISTREAL                      Abs   72987 #00011D1B -   529
=ARRYREAL                          Abs   17107 #000042D3 -   530
=ARRYREALCMP                       Abs   72967 #00011D07 -   531
=ARRYREALREAL                      Abs   72957 #00011CFD -   532
=ARRYSYM                           Abs   17197 #0000432D -   533
=ARSIZE                            Abs   94690 #000171E2 -   534
=ATTN?                             Abs  157587 #00026793 -   535
=ATTNERR                           Abs   73137 #00011DB1 -   536
=ATTNFLGCLR                        Abs   22561 #00005821 -   537
=AddEq$                            Abs  259576 #0003F5F8 -   538
 AddressesCLEBit                   Abs       0 #00000000 -  5868
 AddressesCLEFl                    Abs      89 #00000059 -  5866  5867  5868
 AddressesCLENib                   Abs      22 #00000016 -  5867
=AlDrawMenu                        Abs  191704 #0002ECD8 -   539
 AlarmBeepBit                      Abs       0 #00000000 -  5249
 AlarmBeepFl                       Abs      57 #00000039 -  5237  5248  5249
 AlarmBeepNib                      Abs      14 #0000000E -  5248
 AlgebraicModeBit                  Abs       2 #00000002 -  5886
 AlgebraicModeFl                   Abs      95 #0000005F -  5884  5885  5886
 AlgebraicModeNib                  Abs      23 #00000017 -  5885
=AllowPRLCD                        Abs  258704 #0003F290 -   540
=AllowPrlcdCl                      Abs  258705 #0003F291 -   541
=Angle                             Abs     439 #000001B7 -  6165
=Angle@                            Abs  159875 #00027083 -   542
 AngleBCt                          Abs       2 #00000002 -  5200
 AngleBit1                         Abs       0 #00000000 -  5252  5253
 AngleBit2                         Abs       1 #00000001 -  5253
=AngleField                        Abs  259577 #0003F5F9 -   543
 AngleFl1                          Abs      17 #00000011 -  5199  5251  5252
=AngleLabel                        Abs  259578 #0003F5FA -   544
 AngleNib                          Abs       4 #00000004 -  5251
=AnyDABad?                         Abs  222153 #000363C9 -   545
=ApName$>Id                        Abs  259579 #0003F5FB -   546
=ApNameId>$                        Abs  259580 #0003F5FC -   547
=ApNameId>Id                       Abs  259581 #0003F5FD -   548
=AppDir+Offs                       Abs  166009 #00028879 -   549
=Area@                             Abs  160655 #0002738F -   550
 ArrayOnlyBit                      Abs       2 #00000002 -  5874
 ArrayOnlyFl                       Abs      91 #0000005B -  5872  5873  5874
 ArrayOnlyNib                      Abs      22 #00000016 -  5873
=AttnPOSCOMP                       Abs   60782 #0000ED6E -   551
 AutoSaveBit                       Abs       1 #00000001 -  5883
 AutoSaveFl                        Abs      94 #0000005E -  5881  5882  5883
 AutoSaveNib                       Abs      23 #00000017 -  5882
=BAK>HOME                          Abs   40880 #00009FB0 -   552
=BAK>OB                            Abs   40357 #00009DA5 -   553
=BAKNAME                           Abs   35564 #00008AEC -   554
=BEGIN                             Abs   31099 #0000797B -   555
=BIND                              Abs   31913 #00007CA9 -   556
=BINT0                             Abs   16457 #00004049 -   557
=BINT1                             Abs   16467 #00004053 -   558
=BINT10                            Abs   16557 #000040AD -   559
=BINT100                           Abs   17457 #00004431 -   560
=BINT101                           Abs   17467 #0000443B -   561
=BINT102                           Abs   17477 #00004445 -   562
=BINT103                           Abs   17487 #0000444F -   563
=BINT104                           Abs   17497 #00004459 -   564
=BINT105                           Abs   17507 #00004463 -   565
=BINT106                           Abs   17517 #0000446D -   566
=BINT107                           Abs   17527 #00004477 -   567
=BINT108                           Abs   17537 #00004481 -   568
=BINT109                           Abs   17547 #0000448B -   569
=BINT11                            Abs   16567 #000040B7 -   570
=BINT110                           Abs   17557 #00004495 -   571
=BINT111                           Abs   17567 #0000449F -   572
=BINT112                           Abs   17577 #000044A9 -   573
=BINT113                           Abs   17587 #000044B3 -   574
=BINT114                           Abs   17597 #000044BD -   575
=BINT115                           Abs   17607 #000044C7 -   576
=BINT116                           Abs   17617 #000044D1 -   577
=BINT117                           Abs   17627 #000044DB -   578
=BINT118                           Abs   17637 #000044E5 -   579
=BINT119                           Abs   17647 #000044EF -   580
=BINT12                            Abs   16577 #000040C1 -   581
=BINT120                           Abs   17657 #000044F9 -   582
=BINT121                           Abs   17667 #00004503 -   583
=BINT122                           Abs   17677 #0000450D -   584
=BINT123                           Abs   17687 #00004517 -   585
=BINT124                           Abs   17697 #00004521 -   586
=BINT125                           Abs   17707 #0000452B -   587
=BINT126                           Abs   17717 #00004535 -   588
=BINT127                           Abs   17727 #0000453F -   589
=BINT128                           Abs   17737 #00004549 -   590
=BINT129                           Abs   17747 #00004553 -   591
=BINT13                            Abs   16587 #000040CB -   592
=BINT130                           Abs   17757 #0000455D -   593
=BINT131                           Abs   17767 #00004567 -   594
=BINT132                           Abs   17777 #00004571 -   595
=BINT133                           Abs   17787 #0000457B -   596
=BINT134                           Abs   17797 #00004585 -   597
=BINT135                           Abs   17807 #0000458F -   598
=BINT136                           Abs   17817 #00004599 -   599
=BINT137                           Abs   17827 #000045A3 -   600
=BINT138                           Abs   17837 #000045AD -   601
=BINT139                           Abs   17847 #000045B7 -   602
=BINT14                            Abs   16597 #000040D5 -   603
=BINT140                           Abs   17857 #000045C1 -   604
=BINT141                           Abs   17867 #000045CB -   605
=BINT142                           Abs   17877 #000045D5 -   606
=BINT143                           Abs   17887 #000045DF -   607
=BINT144                           Abs   17897 #000045E9 -   608
=BINT145                           Abs   17907 #000045F3 -   609
=BINT146                           Abs   17917 #000045FD -   610
=BINT147                           Abs   17927 #00004607 -   611
=BINT148                           Abs   17937 #00004611 -   612
=BINT149                           Abs   17947 #0000461B -   613
=BINT15                            Abs   16607 #000040DF -   614
=BINT150                           Abs   17957 #00004625 -   615
=BINT151                           Abs   17967 #0000462F -   616
=BINT152                           Abs   17977 #00004639 -   617
=BINT153                           Abs   17987 #00004643 -   618
=BINT154                           Abs   17997 #0000464D -   619
=BINT155                           Abs   18007 #00004657 -   620
=BINT156                           Abs   18017 #00004661 -   621
=BINT157                           Abs   18027 #0000466B -   622
=BINT158                           Abs   18037 #00004675 -   623
=BINT159                           Abs   18047 #0000467F -   624
=BINT16                            Abs   16617 #000040E9 -   625
=BINT160                           Abs   18057 #00004689 -   626
=BINT161                           Abs   18067 #00004693 -   627
=BINT162                           Abs   18077 #0000469D -   628
=BINT163                           Abs   18087 #000046A7 -   629
=BINT164                           Abs   18097 #000046B1 -   630
=BINT165                           Abs   18107 #000046BB -   631
=BINT166                           Abs   18117 #000046C5 -   632
=BINT167                           Abs   18127 #000046CF -   633
=BINT168                           Abs   18137 #000046D9 -   634
=BINT169                           Abs   18147 #000046E3 -   635
=BINT17                            Abs   16627 #000040F3 -   636
=BINT170                           Abs   18157 #000046ED -   637
=BINT171                           Abs   18167 #000046F7 -   638
=BINT172                           Abs   18177 #00004701 -   639
=BINT173                           Abs   18187 #0000470B -   640
=BINT174                           Abs   18197 #00004715 -   641
=BINT175                           Abs   18207 #0000471F -   642
=BINT176                           Abs   18217 #00004729 -   643
=BINT177                           Abs   18227 #00004733 -   644
=BINT178                           Abs   18237 #0000473D -   645
=BINT179                           Abs   18247 #00004747 -   646
=BINT18                            Abs   16637 #000040FD -   647
=BINT180                           Abs   18257 #00004751 -   648
=BINT181                           Abs   18267 #0000475B -   649
=BINT182                           Abs   18277 #00004765 -   650
=BINT183                           Abs   18287 #0000476F -   651
=BINT184                           Abs   18297 #00004779 -   652
=BINT185                           Abs   18307 #00004783 -   653
=BINT186                           Abs   18317 #0000478D -   654
=BINT187                           Abs   18327 #00004797 -   655
=BINT188                           Abs   18337 #000047A1 -   656
=BINT189                           Abs   18347 #000047AB -   657
=BINT19                            Abs   16647 #00004107 -   658
=BINT190                           Abs   18357 #000047B5 -   659
=BINT191                           Abs   18367 #000047BF -   660
=BINT192                           Abs   18377 #000047C9 -   661
=BINT193                           Abs   18387 #000047D3 -   662
=BINT194                           Abs   18397 #000047DD -   663
=BINT195                           Abs   18407 #000047E7 -   664
=BINT196                           Abs   18417 #000047F1 -   665
=BINT197                           Abs   18427 #000047FB -   666
=BINT198                           Abs   18437 #00004805 -   667
=BINT199                           Abs   18447 #0000480F -   668
=BINT2                             Abs   16477 #0000405D -   669
=BINT20                            Abs   16657 #00004111 -   670
=BINT200                           Abs   18457 #00004819 -   671
=BINT201                           Abs   18467 #00004823 -   672
=BINT202                           Abs   18477 #0000482D -   673
=BINT203                           Abs   18487 #00004837 -   674
=BINT204                           Abs   18497 #00004841 -   675
=BINT205                           Abs   18507 #0000484B -   676
=BINT206                           Abs   18517 #00004855 -   677
=BINT207                           Abs   18527 #0000485F -   678
=BINT208                           Abs   18537 #00004869 -   679
=BINT209                           Abs   18547 #00004873 -   680
=BINT21                            Abs   16667 #0000411B -   681
=BINT210                           Abs   18557 #0000487D -   682
=BINT211                           Abs   18567 #00004887 -   683
=BINT212                           Abs   18577 #00004891 -   684
=BINT213                           Abs   18587 #0000489B -   685
=BINT214                           Abs   18597 #000048A5 -   686
=BINT215                           Abs   18607 #000048AF -   687
=BINT216                           Abs   18617 #000048B9 -   688
=BINT217                           Abs   18627 #000048C3 -   689
=BINT218                           Abs   18637 #000048CD -   690
=BINT219                           Abs   18647 #000048D7 -   691
=BINT22                            Abs   16677 #00004125 -   692
=BINT220                           Abs   18657 #000048E1 -   693
=BINT221                           Abs   18667 #000048EB -   694
=BINT222                           Abs   18677 #000048F5 -   695
=BINT223                           Abs   18687 #000048FF -   696
=BINT224                           Abs   18697 #00004909 -   697
=BINT225                           Abs   18707 #00004913 -   698
=BINT226                           Abs   18717 #0000491D -   699
=BINT227                           Abs   18727 #00004927 -   700
=BINT228                           Abs   18737 #00004931 -   701
=BINT229                           Abs   18747 #0000493B -   702
=BINT23                            Abs   16687 #0000412F -   703
=BINT230                           Abs   18757 #00004945 -   704
=BINT231                           Abs   18767 #0000494F -   705
=BINT232                           Abs   18777 #00004959 -   706
=BINT233                           Abs   18787 #00004963 -   707
=BINT234                           Abs   18797 #0000496D -   708
=BINT235                           Abs   18807 #00004977 -   709
=BINT236                           Abs   18817 #00004981 -   710
=BINT237                           Abs   18827 #0000498B -   711
=BINT238                           Abs   18837 #00004995 -   712
=BINT239                           Abs   18847 #0000499F -   713
=BINT24                            Abs   16697 #00004139 -   714
=BINT240                           Abs   18857 #000049A9 -   715
=BINT241                           Abs   18867 #000049B3 -   716
=BINT242                           Abs   18877 #000049BD -   717
=BINT243                           Abs   18887 #000049C7 -   718
=BINT244                           Abs   18897 #000049D1 -   719
=BINT245                           Abs   18907 #000049DB -   720
=BINT246                           Abs   18917 #000049E5 -   721
=BINT247                           Abs   18927 #000049EF -   722
=BINT248                           Abs   18937 #000049F9 -   723
=BINT249                           Abs   18947 #00004A03 -   724
=BINT25                            Abs   16707 #00004143 -   725
=BINT250                           Abs   18957 #00004A0D -   726
=BINT251                           Abs   18967 #00004A17 -   727
=BINT252                           Abs   18977 #00004A21 -   728
=BINT253                           Abs   18987 #00004A2B -   729
=BINT254                           Abs   18997 #00004A35 -   730
=BINT255                           Abs   19007 #00004A3F -   731
=BINT255d                          Abs   19007 #00004A3F -   732
=BINT256                           Abs   19017 #00004A49 -   733
=BINT26                            Abs   16717 #0000414D -   734
=BINT27                            Abs   16727 #00004157 -   735
=BINT28                            Abs   16737 #00004161 -   736
=BINT29                            Abs   16747 #0000416B -   737
=BINT3                             Abs   16487 #00004067 -   738
=BINT30                            Abs   16757 #00004175 -   739
=BINT31                            Abs   16767 #0000417F -   740
=BINT32                            Abs   16777 #00004189 -   741
=BINT33                            Abs   16787 #00004193 -   742
=BINT34                            Abs   16797 #0000419D -   743
=BINT35                            Abs   16807 #000041A7 -   744
=BINT36                            Abs   16817 #000041B1 -   745
=BINT37                            Abs   16827 #000041BB -   746
=BINT38                            Abs   16837 #000041C5 -   747
=BINT39                            Abs   16847 #000041CF -   748
=BINT3Fh                           Abs   17087 #000042BF -   749
=BINT4                             Abs   16497 #00004071 -   750
=BINT40                            Abs   16857 #000041D9 -   751
=BINT40h                           Abs   17097 #000042C9 -   752
=BINT41                            Abs   16867 #000041E3 -   753
=BINT42                            Abs   16877 #000041ED -   754
=BINT43                            Abs   16887 #000041F7 -   755
=BINT44                            Abs   16897 #00004201 -   756
=BINT45                            Abs   16907 #0000420B -   757
=BINT46                            Abs   16917 #00004215 -   758
=BINT47                            Abs   16927 #0000421F -   759
=BINT48                            Abs   16937 #00004229 -   760
=BINT49                            Abs   16947 #00004233 -   761
=BINT5                             Abs   16507 #0000407B -   762
=BINT50                            Abs   16957 #0000423D -   763
=BINT51                            Abs   16967 #00004247 -   764  6494
=BINT52                            Abs   16977 #00004251 -   765
=BINT53                            Abs   16987 #0000425B -   766
=BINT54                            Abs   16997 #00004265 -   767
=BINT55                            Abs   17007 #0000426F -   768
=BINT56                            Abs   17017 #00004279 -   769
=BINT57                            Abs   17027 #00004283 -   770
=BINT58                            Abs   17037 #0000428D -   771
=BINT59                            Abs   17047 #00004297 -   772
=BINT6                             Abs   16517 #00004085 -   773
=BINT60                            Abs   17057 #000042A1 -   774
=BINT61                            Abs   17067 #000042AB -   775
=BINT62                            Abs   17077 #000042B5 -   776
=BINT63                            Abs   17087 #000042BF -   777
=BINT64                            Abs   17097 #000042C9 -   778
=BINT65                            Abs   17107 #000042D3 -   779
=BINT66                            Abs   17117 #000042DD -   780
=BINT67                            Abs   17127 #000042E7 -   781
=BINT68                            Abs   17137 #000042F1 -   782
=BINT69                            Abs   17147 #000042FB -   783
=BINT7                             Abs   16527 #0000408F -   784
=BINT70                            Abs   17157 #00004305 -   785
=BINT71                            Abs   17167 #0000430F -   786
=BINT72                            Abs   17177 #00004319 -   787
=BINT73                            Abs   17187 #00004323 -   788
=BINT74                            Abs   17197 #0000432D -   789
=BINT75                            Abs   17207 #00004337 -   790
=BINT76                            Abs   17217 #00004341 -   791
=BINT77                            Abs   17227 #0000434B -   792
=BINT78                            Abs   17237 #00004355 -   793
=BINT79                            Abs   17247 #0000435F -   794
=BINT8                             Abs   16537 #00004099 -   795
=BINT80                            Abs   17257 #00004369 -   796
=BINT80h                           Abs   17737 #00004549 -   797
=BINT81                            Abs   17267 #00004373 -   798
=BINT82                            Abs   17277 #0000437D -   799
=BINT83                            Abs   17287 #00004387 -   800
=BINT84                            Abs   17297 #00004391 -   801
=BINT85                            Abs   17307 #0000439B -   802
=BINT86                            Abs   17317 #000043A5 -   803
=BINT87                            Abs   17327 #000043AF -   804
=BINT88                            Abs   17337 #000043B9 -   805
=BINT89                            Abs   17347 #000043C3 -   806
=BINT9                             Abs   16547 #000040A3 -   807
=BINT90                            Abs   17357 #000043CD -   808
=BINT91                            Abs   17367 #000043D7 -   809
=BINT92                            Abs   17377 #000043E1 -   810
=BINT93                            Abs   17387 #000043EB -   811
=BINT94                            Abs   17397 #000043F5 -   812
=BINT95                            Abs   17407 #000043FF -   813
=BINT96                            Abs   17417 #00004409 -   814
=BINT97                            Abs   17427 #00004413 -   815
=BINT98                            Abs   17437 #0000441D -   816
=BINT99                            Abs   17447 #00004427 -   817
=BINTC0h                           Abs   18377 #000047C9 -   818
=BINT_114d                         Abs   17597 #000044BD -   819
=BINT_115d                         Abs   17607 #000044C7 -   820
=BINT_116d                         Abs   17617 #000044D1 -   821
=BINT_117d                         Abs   17627 #000044DB -   822
=BINT_122d                         Abs   17677 #0000450D -   823
=BINT_128d                         Abs   17737 #00004549 -   824
=BINT_130d                         Abs   17757 #0000455D -   825
=BINT_131d                         Abs   17767 #00004567 -   826
=BINT_263d                         Abs   72737 #00011C21 -   827
=BINT_305d                         Abs   72787 #00011C53 -   828
=BINT_306d                         Abs   72797 #00011C5D -   829
=BINT_307d                         Abs   72807 #00011C67 -   830
=BINT_65d                          Abs   17107 #000042D3 -   831
=BINT_91d                          Abs   17367 #000043D7 -   832
=BINT_96d                          Abs   17417 #00004409 -   833
=BLANKIT                           Abs  125433 #0001E9F9 -   834
=BREAK                             Abs  258706 #0003F292 -   835
=BTRow1                            Abs     844 #0000034C -  6305
=BTRow1@                           Abs  160235 #000271EB -   836
=BadIfEdit                         Abs  144480 #00023460 -   837
 BigFontCmdBit                     Abs       0 #00000000 -  5820
 BigFontCmdFl                      Abs      73 #00000049 -  5818  5819  5820
 BigFontCmdNib                     Abs      18 #00000012 -  5819
 BigFontStackBit                   Abs       3 #00000003 -  5817
 BigFontStackFl                    Abs      72 #00000048 -  5815  5816  5817
 BigFontStackNib                   Abs      17 #00000011 -  5816
 BinBaseBCt                        Abs       2 #00000002 -  5195
 BinBaseBit1                       Abs       2 #00000002 -  5256
 BinBaseFl1                        Abs      11 #0000000B -  5194  5255  5256
 BinBaseNib                        Abs       2 #00000002 -  5255
=BinLookup                         Abs  231267 #00038763 -   838  6437
 BinWordSBCt                       Abs       6 #00000006 -  5193
 BinWordSBit1                      Abs       0 #00000000 -  5259
 BinWordSFl1                       Abs       5 #00000005 -  5192  5258  5259
 BinWordSNib                       Abs       1 #00000001 -  5258
=BlankClient                       Abs  259582 #0003F5FE -   839
=BlankHelp                         Abs  259632 #0003F630 -   840
=Box/StdLabel                      Abs  144580 #000234C4 -   841
=Bubble                            Abs  259825 #0003F6F1 -   842
=C%>%                              Abs   25904 #00006530 -   843
=CACHE                             Abs   55395 #0000D863 -   844
=CALCCXT!                          Abs   75414 #00012696 -   845
=CALCCXT@                          Abs   75430 #000126A6 -   846
=CAND                              Abs  231137 #000386E1 -   847
=CAR$                              Abs   22694 #000058A6 -   848
=CARCOMP                           Abs   22594 #00005842 -   849  6683
=CDR$                              Abs   22821 #00005925 -   850
=CDRCOMP                           Abs   22796 #0000590C -   851
=CHANGETYPE                        Abs   25196 #0000626C -   852
=CHECKHEIGHT                       Abs  259569 #0003F5F1 -   853
=CHECKKEY                          Abs   20370 #00004F92 -   854
=CHECKPICT                         Abs  258847 #0003F31F -   855
=CHR>#                             Abs   25098 #0000620A -   856
=CHR>$                             Abs   68061 #000109DD -   857
=CHR_#                             Abs   68152 #00010A38 -   858
=CHR_'                             Abs   68138 #00010A2A -   859
=CHR_*                             Abs   68159 #00010A3F -   860
=CHR_+                             Abs   68166 #00010A46 -   861
=CHR_,                             Abs   68173 #00010A4D -   862
=CHR_-                             Abs   68180 #00010A54 -   863
=CHR_->                            Abs   68670 #00010C3E -   864
=CHR_.                             Abs   68187 #00010A5B -   865
=CHR_...                           Abs   68131 #00010A23 -   866
=CHR_/                             Abs   68194 #00010A62 -   867
=CHR_0                             Abs   68201 #00010A69 -   868
=CHR_00                            Abs   68124 #00010A1C -   869
=CHR_1                             Abs   68208 #00010A70 -   870
=CHR_2                             Abs   68215 #00010A77 -   871
=CHR_3                             Abs   68222 #00010A7E -   872
=CHR_4                             Abs   68229 #00010A85 -   873
=CHR_5                             Abs   68236 #00010A8C -   874
=CHR_6                             Abs   68243 #00010A93 -   875
=CHR_7                             Abs   68250 #00010A9A -   876
=CHR_8                             Abs   68257 #00010AA1 -   877
=CHR_9                             Abs   68264 #00010AA8 -   878
=CHR_:                             Abs   68271 #00010AAF -   879
=CHR_;                             Abs   68278 #00010AB6 -   880
=CHR_<                             Abs   68285 #00010ABD -   881
=CHR_<<                            Abs   68677 #00010C45 -   882
=CHR_<=                            Abs   68789 #00010CB5 -   883
=CHR_<>                            Abs   68803 #00010CC3 -   884
=CHR_=                             Abs   68292 #00010AC4 -   885
=CHR_>                             Abs   68299 #00010ACB -   886
=CHR_>=                            Abs   68796 #00010CBC -   887
=CHR_>>                            Abs   68684 #00010C4C -   888
=CHR_A                             Abs   68306 #00010AD2 -   889
=CHR_Angle                         Abs   68691 #00010C53 -   890
=CHR_B                             Abs   68313 #00010AD9 -   891
=CHR_C                             Abs   68320 #00010AE0 -   892
=CHR_D                             Abs   68327 #00010AE7 -   893
=CHR_DblQuote                      Abs   68145 #00010A31 -   894
=CHR_Deriv                         Abs   68698 #00010C5A -   895
=CHR_E                             Abs   68334 #00010AEE -   896
=CHR_F                             Abs   68341 #00010AF5 -   897
=CHR_G                             Abs   68348 #00010AFC -   898
=CHR_H                             Abs   68355 #00010B03 -   899
=CHR_I                             Abs   68362 #00010B0A -   900
=CHR_Integral                      Abs   68705 #00010C61 -   901
=CHR_J                             Abs   68369 #00010B11 -   902
=CHR_K                             Abs   68376 #00010B18 -   903
=CHR_L                             Abs   68383 #00010B1F -   904
=CHR_LeftPar                       Abs   68712 #00010C68 -   905
=CHR_M                             Abs   68390 #00010B26 -   906
=CHR_N                             Abs   68397 #00010B2D -   907
=CHR_Newline                       Abs   68719 #00010C6F -   908
=CHR_O                             Abs   68404 #00010B34 -   909
=CHR_P                             Abs   68411 #00010B3B -   910
=CHR_Pi                            Abs   68726 #00010C76 -   911
=CHR_Q                             Abs   68418 #00010B42 -   912
=CHR_R                             Abs   68425 #00010B49 -   913
=CHR_RightPar                      Abs   68733 #00010C7D -   914
=CHR_S                             Abs   68432 #00010B50 -   915
=CHR_Sigma                         Abs   68740 #00010C84 -   916
=CHR_Space                         Abs   68747 #00010C8B -   917
=CHR_T                             Abs   68439 #00010B57 -   918
=CHR_U                             Abs   68446 #00010B5E -   919
=CHR_UndScore                      Abs   68754 #00010C92 -   920
=CHR_V                             Abs   68453 #00010B65 -   921
=CHR_W                             Abs   68460 #00010B6C -   922
=CHR_X                             Abs   68467 #00010B73 -   923
=CHR_Y                             Abs   68474 #00010B7A -   924
=CHR_Z                             Abs   68481 #00010B81 -   925
=CHR_[                             Abs   68761 #00010C99 -   926
=CHR_]                             Abs   68768 #00010CA0 -   927
=CHR_a                             Abs   68488 #00010B88 -   928
=CHR_b                             Abs   68495 #00010B8F -   929
=CHR_c                             Abs   68502 #00010B96 -   930
=CHR_d                             Abs   68509 #00010B9D -   931
=CHR_e                             Abs   68516 #00010BA4 -   932
=CHR_f                             Abs   68523 #00010BAB -   933
=CHR_g                             Abs   68530 #00010BB2 -   934
=CHR_h                             Abs   68537 #00010BB9 -   935
=CHR_i                             Abs   68544 #00010BC0 -   936
=CHR_j                             Abs   68551 #00010BC7 -   937
=CHR_k                             Abs   68558 #00010BCE -   938
=CHR_l                             Abs   68565 #00010BD5 -   939
=CHR_m                             Abs   68572 #00010BDC -   940
=CHR_n                             Abs   68579 #00010BE3 -   941
=CHR_o                             Abs   68586 #00010BEA -   942
=CHR_p                             Abs   68593 #00010BF1 -   943
=CHR_q                             Abs   68600 #00010BF8 -   944
=CHR_r                             Abs   68607 #00010BFF -   945
=CHR_s                             Abs   68614 #00010C06 -   946
=CHR_t                             Abs   68621 #00010C0D -   947
=CHR_u                             Abs   68628 #00010C14 -   948
=CHR_v                             Abs   68635 #00010C1B -   949
=CHR_w                             Abs   68642 #00010C22 -   950
=CHR_x                             Abs   68649 #00010C29 -   951
=CHR_y                             Abs   68656 #00010C30 -   952
=CHR_z                             Abs   68663 #00010C37 -   953
=CHR_{                             Abs   68775 #00010CA7 -   954
=CHR_}                             Abs   68782 #00010CAE -   955
=CK&DISPATCH0                      Abs   79219 #00013573 -   956
=CK&DISPATCH1                      Abs   79146 #0001352A -   957
=CK&DISPATCH2                      Abs   79234 #00013582 -   958
=CK0                               Abs   77598 #00012F1E -   959
=CK1&Dispatch                      Abs   78879 #0001341F -   960
=CK2&Dispatch                      Abs   78896 #00013430 -   961
=CK3&Dispatch                      Abs   78913 #00013441 -   962
=CK4&Dispatch                      Abs   78930 #00013452 -   963
=CK5&Dispatch                      Abs   78947 #00013463 -   964
=CKGROBFITS                        Abs  258848 #0003F320 -   965
=CKREAL                            Abs   59239 #0000E767 -   966
=CKREF                             Abs   91217 #00016451 -   967
=CLCD10                            Abs    8067 #00001F83 -   968
=CLKTICKS                          Abs  260007 #0003F7A7 -   969
=CLOSEUART                         Abs  258702 #0003F28E -   970
=CLRTOPICLAM                       Abs  259566 #0003F5EE -   971
=CMPOBOB                           Abs   72927 #00011CDF -   972
=COERCE                            Abs   78404 #00013244 -   973
=COERCEDUP                         Abs   62907 #0000F5BB -   974
=COERCESWAP                        Abs   63317 #0000F755 -   975
=COLA                              Abs   30634 #000077AA -   976
=COLACOLA                          Abs   58600 #0000E4E8 -   977
=COLARPITE                         Abs   54871 #0000D657 -   978
=COLASKIP                          Abs   64682 #0000FCAA -   979
=COLA_EVAL                         Abs   54838 #0000D636 -   980
=COLAcase                          Abs   58625 #0000E501 -   981
=COMPEVAL                          Abs   78859 #0001340B -   982
=COMPILEID                         Abs   34091 #0000852B -   983
=COMPROMID                         Abs   34096 #00008530 -   984
=CONTEXT!                          Abs   38414 #0000960E -   985
=CONTEXT@                          Abs   38496 #00009660 -   986
=COR                               Abs  231179 #0003870B -   987
=CREATE                            Abs   36764 #00008F9C -   988
=CREATEDIR                         Abs  143163 #00022F3B -   989
=CRLF$                             Abs   93254 #00016C46 -   990
=CalcDir+Offs                      Abs  165986 #00028862 -   991
 CarefulBit                        Abs       3 #00000003 -  5262
 CarefulFl                         Abs       4 #00000004 -  5190  5261  5262
 CarefulNib                        Abs       0 #00000000 -  5261
=CatNot                            Abs  164180 #00028154 -   992
=CatPgm                            Abs  164295 #000281C7 -   993
=CatThisCxt                        Abs  164190 #0002815E -   994
=ChangeFocus                       Abs  259583 #0003F5FF -   995
=Choose                            Abs  258852 #0003F324 -   996
=Choose&DoTask                     Abs  259587 #0003F603 -   997
=ChooseMenu0                       Abs  259584 #0003F600 -   998
=ChooseMenu1                       Abs  259585 #0003F601 -   999
=ChooseMenu2                       Abs  259586 #0003F602 -  1000
=ChooseSimple                      Abs  258853 #0003F325 -  1001
=ChooseVEntry                      Abs  259530 #0003F5CA -  1002
=ChooseVExit                       Abs  259531 #0003F5CB -  1003
=ChooseViewUI                      Abs  259532 #0003F5CC -  1004
=Ck&DecKeyLoc                      Abs  155512 #00025F78 -  1005
=ClearList0                        Abs  259588 #0003F604 -  1006
=ClearList1                        Abs  259589 #0003F605 -  1007
=ClearList2                        Abs  259590 #0003F606 -  1008
=ClearList3                        Abs  259591 #0003F607 -  1009
=ClearList4                        Abs  259592 #0003F608 -  1010
=ClearList5                        Abs  259593 #0003F609 -  1011
=ClearList6                        Abs  259594 #0003F60A -  1012
=ClearList7                        Abs  259595 #0003F60B -  1013
=ClearList8                        Abs  259596 #0003F60C -  1014
=ClearList9                        Abs  259597 #0003F60D -  1015
 ClockFmtBit                       Abs       0 #00000000 -  5265
 ClockFmtFl                        Abs      41 #00000029 -  5222  5264  5265
 ClockFmtNib                       Abs      10 #0000000A -  5264
 ClockOnBit                        Abs       3 #00000003 -  5268
 ClockOnFl                         Abs      40 #00000028 -  5221  5267  5268
 ClockOnNib                        Abs       9 #00000009 -  5267
=CloseUart                         Abs   94395 #000170BB -  1016
=ClrAllTOLVs                       Abs   75929 #00012899 -  1017
=ClrAllTVars                       Abs   75875 #00012863 -  1018
=ClrDA1Bad                         Abs  222730 #0003660A -  1019
=ClrDA1OK                          Abs  221773 #0003624D -  1020
=ClrDA2OK                          Abs  221848 #00036298 -  1021
=ClrDA2aBad                        Abs  222772 #00036634 -  1022
=ClrDA2aOK                         Abs  221798 #00036266 -  1023
=ClrDA2bBad                        Abs  222814 #0003665E -  1024
=ClrDA2bNoCh                       Abs  222646 #000365B6 -  1025
=ClrDA2bOK                         Abs  221823 #0003627F -  1026
=ClrDA3OK                          Abs  221868 #000362AC -  1027
=ClrInAplet                        Abs  259520 #0003F5C0 -  1028
=ClrListUtil                       Abs  259598 #0003F60E -  1029
=ClrSysFlag                        Abs  103383 #000193D7 -  1030
=ClrUserFlag                       Abs  103371 #000193CB -  1031
 CmdAutoIndentBit                  Abs       3 #00000003 -  5805
 CmdAutoIndentFl                   Abs      68 #00000044 -  5803  5804  5805
 CmdAutoIndentNib                  Abs      16 #00000010 -  5804
=CodePl>%rc.p                      Abs  155752 #00026068 -  1032
 ComVecDiBCt                       Abs       2 #00000002 -  5198
 ComVecDiBit1                      Abs       2 #00000002 -  5274
 ComVecDiFl1                       Abs      15 #0000000F -  5197  5273  5274
 ComVecDiNib                       Abs       3 #00000003 -  5273
 Complex2DBit                      Abs       2 #00000002 -  5271
 Complex2DFl                       Abs      19 #00000013 -  5201  5270  5271
 Complex2DNib                      Abs       4 #00000004 -  5270
 ComplexBit                        Abs       2 #00000002 -  5900
 ComplexFl                         Abs     103 #00000067 -  5898  5899  5900
 ComplexNib                        Abs      25 #00000019 -  5899
 ConnectPtBit                      Abs       2 #00000002 -  5277
 ConnectPtFl                       Abs      31 #0000001F -  5211  5276  5277
 ConnectPtNib                      Abs       7 #00000007 -  5276
=Connecting                        Abs   73327 #00011E6F -  1033
 ConstantsBit                      Abs       1 #00000001 -  5280
 ConstantsFl                       Abs       2 #00000002 -  5188  5279  5280
 ConstantsNib                      Abs       0 #00000000 -  5279
=Contxt+Offs                       Abs  166032 #00028890 -  1034
=CopyRegCOb                        Abs  189899 #0002E5CB -  1035
=CtlAlarm!                         Abs  158209 #00026A01 -  5067
=DA1Bad?                           Abs  222702 #000365EE -  1036
=DA1OK?                            Abs  221013 #00035F55 -  1037
=DA2OK?                            Abs  221253 #00036045 -  1038
=DA2aBad?                          Abs  222744 #00036618 -  1039
=DA2aLess1OK?                      Abs  221538 #00036162 -  1040
=DA2aOK?                           Abs  221093 #00035FA5 -  1041
=DA2bNoCh?                         Abs  222618 #0003659A -  1042
=DA2bOK?                           Abs  221173 #00035FF5 -  1043
=DA3OK?                            Abs  221278 #0003605E -  1044
=DA3OK?NOTIT                       Abs  221468 #0003611C -  1045
=DAsOK?                            Abs  221358 #000360AE -  1046
=DECOMP$                           Abs  134595 #00020DC3 -  1047
=DEPTH                             Abs   12620 #0000314C -  1048
=DIMLIMITS                         Abs   94702 #000171EE -  1049
=DISPN                             Abs  124673 #0001E701 -  1050
=DISPROW1                          Abs  124725 #0001E735 -  1051
=DISPROW2                          Abs  124741 #0001E745 -  1052
=DISPROW3                          Abs  124757 #0001E755 -  1053
=DISPROW4                          Abs  124773 #0001E765 -  1054
=DISPROW5                          Abs  124789 #0001E775 -  1055
=DISPROW6                          Abs  124805 #0001E785 -  1056
=DISPROW7                          Abs  124821 #0001E795 -  1057
=DISPROW8                          Abs  124837 #0001E7A5 -  1058
=DO                                Abs   31696 #00007BD0 -  1059
=DO#EXIT                           Abs  133550 #000209AE -  1060
=DO$EXIT                           Abs  133575 #000209C7 -  1061
=DO>STR                            Abs  132555 #000205CB -  1062
=DOARRY                            Abs   10728 #000029E8 -  1063
=DOBAK                             Abs   11106 #00002B62 -  1064
=DOBIND                            Abs   31933 #00007CBD -  1065
=DOBINT                            Abs   10513 #00002911 -  1066  6167  6199
                                        6205  6212  6275  6283  6289  6295  6301
                                        6307  6313  6321  6791  6794
=DOCHAR                            Abs   10687 #000029BF -  1067
=DOCLLCD                           Abs  258868 #0003F334 -  1068
=DOCMP                             Abs   10615 #00002977 -  1069
=DOCODE                            Abs   11724 #00002DCC -  1070
=DOCOL                             Abs   11677 #00002D9D -  1071  6407  6422
                                        6479  6489  6495  6532  6554  6572  6584
                                        6622  6653  6715  6741
=DOCSTR                            Abs   10796 #00002A2C -  1072  6419  6530
                                        6552  6777  6781  6784  6822
=DODISP                            Abs  132690 #00020652 -  1073
=DOECMP                            Abs   10653 #0000299D -  1074
=DOERASE                           Abs  258870 #0003F336 -  1075
=DOEREL                            Abs   10581 #00002955 -  1076
=DOEXT                             Abs   10970 #00002ADA -  1077
=DOEXT0                            Abs   11144 #00002B88 -  1078
=DOEXT1                            Abs   11178 #00002BAA -  1079
=DOEXT2                            Abs   11212 #00002BCC -  1080
=DOEXT3                            Abs   11246 #00002BEE -  1081
=DOEXT4                            Abs   11280 #00002C10 -  1082
=DOFINISH                          Abs  258707 #0003F293 -  1083
=DOFLASHP                          Abs   10101 #00002775 -  1084
=DOGROB                            Abs   11038 #00002B1E -  1085  6787
=DOHSTR                            Abs   10830 #00002A4E -  1086  6333  6382
=DOHXS                             Abs   10830 #00002A4E -  1087
=DOIDNT                            Abs   11848 #00002E48 -  1088
=DOINDIR                           Abs   68103 #00010A07 -  1089
=DOLAM                             Abs   11885 #00002E6D -  1090
=DOLCD>                            Abs  258872 #0003F338 -  1091
=DOLCD>g0                          Abs  259069 #0003F3FD -  1092
=DOLIB                             Abs   11072 #00002B40 -  1093
=DOLIST                            Abs   10868 #00002A74 -  1094  6031  6415
                                        6417  6418  6491  6493  6526  6529  6551
                                        6775  6798  6811  6833
=DOLNKARRY                         Abs   10762 #00002A0A -  1095
=DOREAL                            Abs   10547 #00002933 -  1096  6055  6065
                                        6075  6085  6095  6103  6111  6119  6127
                                        6137  6147  6157  6175  6183  6191  6219
                                        6227  6235  6243  6253  6263
=DOROMP                            Abs   11922 #00002E92 -  1097  6032  6034
                                        6036  6038  6040  6042  6538  6611  6687
                                        6745
=DOROOT                            Abs  259983 #0003F78F -  1098
=DORRP                             Abs   10902 #00002A96 -  1099  6023
=DOSHOWIT1                         Abs  259599 #0003F60F -  1100
=DOSHOWIT1C                        Abs  103124 #000192D4 -  1101
=DOSYMB                            Abs   10936 #00002AB8 -  1102
=DOTAG                             Abs   11004 #00002AFC -  1103
=DOWAIT                            Abs  239559 #0003A7C7 -  1104
=DROP                              Abs   12868 #00003244 -  1105  6537  6607
                                        6641  6700  6731
=DROP#1-                           Abs   65727 #000100BF -  1106
=DROP'                             Abs   65997 #000101CD -  1107
=DROPDUP                           Abs   58146 #0000E322 -  1108
=DROPFALSE                         Abs   56797 #0000DDDD -  1109
=DROPLOOP                          Abs   64862 #0000FD5E -  1110
=DROPNDROP                         Abs   67617 #00010821 -  1111
=DROPNULL$                         Abs   21840 #00005550 -  1112
=DROPONE                           Abs   58561 #0000E4C1 -  1113
=DROPOVER                          Abs   63754 #0000F90A -  1114
=DROPRDROP                         Abs   64481 #0000FBE1 -  1115
=DROPROT                           Abs   63654 #0000F8A6 -  1116
=DROPSWAP                          Abs   57991 #0000E287 -  1117
=DROPTRUE                          Abs   56788 #0000DDD4 -  1118
=DROPZERO                          Abs   57568 #0000E0E0 -  1119
=DUMP                              Abs   55841 #0000DA21 -  1120
=DUP                               Abs   12680 #00003188 -  1121
=DUP#0<>                           Abs   56959 #0000DE7F -  1122
=DUP#0<>WHILE                      Abs   64752 #0000FCF0 -  1123
=DUP#0=                            Abs   56849 #0000DE11 -  1124
=DUP#0=IT                          Abs   67267 #000106C3 -  1125
=DUP#0=ITE                         Abs   67392 #00010740 -  1126
=DUP#0=case                        Abs   54362 #0000D45A -  1127
=DUP#0=csDROP                      Abs   66872 #00010538 -  1128
=DUP#0=csedrp                      Abs   54385 #0000D471 -  1129
=DUP#0_DO                          Abs   64887 #0000FD77 -  1130
=DUP#1+                            Abs   58470 #0000E466 -  1131
=DUP#1=                            Abs   56944 #0000DE70 -  1132
=DUP#<7                            Abs   65382 #0000FF66 -  1133
=DUP$>ID                           Abs   64381 #0000FB7D -  1134
=DUP%0=                            Abs   66597 #00010425 -  1135
=DUP'                              Abs   65957 #000101A5 -  1136
=DUP1LAMBIND                       Abs   64962 #0000FDC2 -  1137
=DUP3PICK#+                        Abs   65507 #0000FFE3 -  1138
=DUP@                              Abs   62687 #0000F4DF -  1139
=DUPDUP                            Abs   62867 #0000F593 -  1140
=DUPINCOMP                         Abs   64201 #0000FAC9 -  1141
=DUPINDEX@                         Abs   64777 #0000FD09 -  1142
=DUPLEN$                           Abs   58166 #0000E336 -  1143
=DUPLENCOMP                        Abs   64281 #0000FB19 -  1144
=DUPNULL$?                         Abs   64241 #0000FAF1 -  1145
=DUPNULLCOMP?                      Abs   64261 #0000FB05 -  1146
=DUPNULL{}?                        Abs   66287 #000102EF -  1147
=DUPONE                            Abs   66352 #00010330 -  1148
=DUPPICK                           Abs   63934 #0000F9BE -  1149
=DUPROLL                           Abs   63954 #0000F9D2 -  1150
=DUPROMPTR@                        Abs   62707 #0000F4F3 -  1151
=DUPROT                            Abs   63634 #0000F892 -  1152
=DUPTWO                            Abs   66412 #0001036C -  1153
=DUPTYPEARRY?                      Abs   56458 #0000DC8A -  1154
=DUPTYPEBINT?                      Abs   56383 #0000DC3F -  1155
=DUPTYPECHAR?                      Abs   56218 #0000DB9A -  1156
=DUPTYPECMP?                       Abs   56443 #0000DC7B -  1157
=DUPTYPECOL?                       Abs   56518 #0000DCC6 -  1158
=DUPTYPECSTR?                      Abs   56413 #0000DC5D -  1159
=DUPTYPEEXT?                       Abs   56578 #0000DD02 -  1160
=DUPTYPEGROB?                      Abs   56533 #0000DCD5 -  1161
=DUPTYPEHSTR?                      Abs   56398 #0000DC4E -  1162
=DUPTYPEIDNT?                      Abs   56233 #0000DBA9 -  1163
=DUPTYPELAM?                       Abs   56368 #0000DC30 -  1164
=DUPTYPELIST?                      Abs   56548 #0000DCE4 -  1165
=DUPTYPEREAL?                      Abs   56428 #0000DC6C -  1166
=DUPTYPEROMP?                      Abs   56473 #0000DC99 -  1167
=DUPTYPERRP?                       Abs   56488 #0000DCA8 -  1168
=DUPTYPESYMB?                      Abs   56503 #0000DCB7 -  1169
=DUPTYPETAG?                       Abs   56563 #0000DCF3 -  1170
=DUPUNROT                          Abs   53464 #0000D0D8 -  1171
=DUPZERO                           Abs   66332 #0001031C -  1172
 DateFmtBit                        Abs       1 #00000001 -  5283
 DateFmtFl                         Abs      42 #0000002A -  5223  5282  5283
 DateFmtNib                        Abs      10 #0000000A -  5282
 DblSpaceBit                       Abs       0 #00000000 -  5286
 DblSpaceFl                        Abs      37 #00000025 -  5217  5285  5286
 DblSpaceNib                       Abs       9 #00000009 -  5285
=Decomp%Short                      Abs  258885 #0003F345 -  1173
=DecompNoNL                        Abs  259600 #0003F610 -  1174
=DecompOb                          Abs  259559 #0003F5E7 -  1175
 DefSysF32-01                      Abs67178480 #04010FF0 -  5113
 DefSysF64-33                      Abs       2 #00000002 -  5112
 DefSysF65-96                      Abs1107296256 #42000000 -  5114
 DefSysF97-128                     Abs       0 #00000000 -  5115
=DefauPtXit                        Abs  191599 #0002EC6F -  1176
=DefauTrcInit                      Abs  194403 #0002F763 -  1177
=DefaultHint                       Abs  223767 #00036A17 -  1178
 DelNRAlmBit                       Abs       3 #00000003 -  5289
 DelNRAlmFl                        Abs      44 #0000002C -  5225  5288  5289
 DelNRAlmNib                       Abs      10 #0000000A -  5288
=DemoFrames                        Abs  260304 #0003F8D0 -  1179
 DesasmWithAdrBit                  Abs       2 #00000002 -  5814
 DesasmWithAdrFl                   Abs      71 #00000047 -  5812  5813  5814
 DesasmWithAdrNib                  Abs      17 #00000011 -  5813
 DigitalClockBit                   Abs       2 #00000002 -  5802
 DigitalClockFl                    Abs      67 #00000043 -  5800  5801  5802
 DigitalClockNib                   Abs      16 #00000010 -  5801
=Digits                            Abs     878 #0000036E -  6319
=Digits@                           Abs  160275 #00027213 -  1180
 DirAlt                            Rel    1820 #0000071C -  6807  6818
 DirCode                           Rel    1691 #0000069B -  6771  6807
 DirEnd                            Rel    1854 #0000073E -  6829  6023
 DirNot                            Rel    1837 #0000072D -  6818  6829
 DirStart                          Rel      40 #00000028 -  6023  6053  6063
                                        6073  6083  6093  6101  6109  6117  6125
                                        6135  6145  6155  6165  6173  6181  6189
                                        6197  6203  6210  6217  6225  6233  6241
                                        6251  6261  6273  6281  6287  6293  6299
                                        6305  6311  6319  6337  6339  6341  6343
                                        6345  6347
 DirVar                            Rel     980 #000003D4 -  6376  6771
=DisableIntr                       Abs    4428 #0000114C -  1181
=Disp5x7                           Abs  259834 #0003F6FA -  5080
=DispMenu                          Abs   69161 #00010E29 -  1182
=DispMenu.1                        Abs   69181 #00010E3D -  1183
=DispMsgBox                        Abs  258889 #0003F349 -  1184
=DispXFunc                         Abs  197747 #00030473 -  1185
=DispYFunc                         Abs  195803 #0002FCDB -  1186
=DoAlert                           Abs  258891 #0003F34B -  1187
=DoAlert&Query                     Abs  258892 #0003F34C -  1188
=DoApletLib                        Abs  259601 #0003F611 -  1189
=DoAs2Col                          Abs  259073 #0003F401 -  1190
=DoBadKey                          Abs  146965 #00023E15 -  1191
=DoCAlarmKey                       Abs  158184 #000269E8 -  5068
=DoCApNoteV                        Abs  258894 #0003F34E -  1192
=DoCApPlotSV                       Abs  258895 #0003F34F -  1193
=DoCApPlotV                        Abs  259602 #0003F612 -  1194
=DoCApSketchV                      Abs  258896 #0003F350 -  1195
=DoCApSymbSV                       Abs  258897 #0003F351 -  1196
=DoCApSymbV                        Abs  259603 #0003F613 -  1197
=DoCApTableSV                      Abs  258898 #0003F352 -  1198
=DoCApTableV                       Abs  259604 #0003F614 -  1199
=DoCKeyCancel                      Abs  258899 #0003F353 -  1200
=DoCKeyChAll                       Abs  258900 #0003F354 -  1201
=DoCKeyCheck                       Abs  258901 #0003F355 -  1202
=DoCKeyOK                          Abs  258902 #0003F356 -  1203
=DoCKeyUnChAll                     Abs  258903 #0003F357 -  1204
=DoCurrAplet                       Abs  259605 #0003F615 -  1205
=DoDemo                            Abs  260305 #0003F8D1 -  1206
=DoDispBorder                      Abs  259606 #0003F616 -  1207
=DoDispField                       Abs  259521 #0003F5C1 -  1208
=DoDispList                        Abs  259607 #0003F617 -  1209
=DoDispPrompt                      Abs  259608 #0003F618 -  1210
=DoEditLCancel                     Abs  259837 #0003F6FD -  1211
=DoEditLOK                         Abs  259839 #0003F6FF -  1212
=DoEditLine                        Abs  259841 #0003F701 -  1213
=DoGetObFrSto                      Abs  258708 #0003F294 -  1214
=DoIOErrAlert                      Abs  258709 #0003F295 -  1215
=DoIOStatusBox                     Abs  258710 #0003F296 -  1216
=DoInApLbCxt                       Abs   94774 #00017236 -  1217
=DoInAppCxt                        Abs   76495 #00012ACF -  1218
=DoInCalcCxt                       Abs   76470 #00012AB6 -  1219
=DoInCxt                           Abs   76380 #00012A5C -  1220
=DoInFuncCxt                       Abs   76520 #00012AE8 -  1221
=DoInNotCxt                        Abs  163895 #00028037 -  1222
=DoInOtherCxt                      Abs   76670 #00012B7E -  1223
=DoInParamCxt                      Abs   76570 #00012B1A -  1224
=DoInPgmCxt                        Abs  162705 #00027B91 -  1225
=DoInPolarCxt                      Abs   76545 #00012B01 -  1226
=DoInSeqCxt                        Abs   76595 #00012B33 -  1227
=DoInSolveCxt                      Abs   76645 #00012B65 -  1228
=DoInStatCxt                       Abs   76620 #00012B4C -  1229
=DoInputForm                       Abs   88641 #00015A41 -  1230
=DoKeyCancel                       Abs  258905 #0003F359 -  1231
=DoKeyCheck                        Abs  259609 #0003F619 -  1232
=DoKeyChoos/Ck                     Abs  259611 #0003F61B -  1233
=DoKeyChoose                       Abs  259610 #0003F61A -  1234
=DoKeyEdit                         Abs  259612 #0003F61C -  1235
=DoKeyOK                           Abs  259613 #0003F61D -  1236
=DoMKeyOK                          Abs  258907 #0003F35B -  1237
=DoMatEdit                         Abs  259842 #0003F702 -  1238
=DoMsgBox                          Abs  258909 #0003F35D -  1239
=DoQueryBox                        Abs  258915 #0003F363 -  1240
=DoRecv/GetOb                      Abs  258091 #0003F02B -  1241
=DoRecvObFrEls                     Abs  258711 #0003F297 -  1242
=DoRestCovWin                      Abs  259762 #0003F6B2 -  1243
=DoResultTab                       Abs  260109 #0003F80D -  1244
=DoRomPtrKey                       Abs  148342 #00024376 -  1245
=DoSaveCovWin                      Abs  259761 #0003F6B1 -  1246
=DoSendOb                          Abs  258092 #0003F02C -  1247
=DoSendObToCDi                     Abs  258712 #0003F298 -  1248
=DoSendObToDir                     Abs  258713 #0003F299 -  1249
=DoSendObToEls                     Abs  258776 #0003F2D8 -  1250
=DoSendObToSto                     Abs  258714 #0003F29A -  1251
=DoSpecAlert                       Abs  259614 #0003F61E -  1252
=Docrunchc                         Abs  102989 #0001924D -  1253
=Done?CkNoNul:                     Abs   93328 #00016C90 -  1254
=DropJunk                          Abs  217792 #000352C0 -  1255
=DropSysObs                        Abs   89773 #00015EAD -  1256
=DummyMenuErr                      Abs  230148 #00038304 -  1257
=DummyVar                          Abs  166464 #00028A40 -  1258
=DummyVarProc                      Abs  166444 #00028A2C -  5081
=EDITDECOMP$                       Abs  134329 #00020CB9 -  1259
=EIGHT                             Abs   16537 #00004099 -  1260
=EIGHTEEN                          Abs   16637 #000040FD -  1261
=EIGHTY                            Abs   17257 #00004369 -  1262
=EIGHTYEIGHT                       Abs   17337 #000043B9 -  1263
=EIGHTYNINE                        Abs   17347 #000043C3 -  1264
=EIGHTYONE                         Abs   17267 #00004373 -  1265
=ELEVEN                            Abs   16567 #000040B7 -  1266
=EQ                                Abs   15150 #00003B2E -  1267
=EQIT                              Abs   67242 #000106AA -  1268
=EQITE                             Abs   67312 #000106F0 -  1269
=EQLookup                          Abs   67852 #0001090C -  1270
=EQOR                              Abs   65252 #0000FEE4 -  1271
=EQOVER                            Abs   63774 #0000F91E -  1272
=EQUAL                             Abs   15255 #00003B97 -  1273
=EQUALNOT                          Abs   65212 #0000FEBC -  1274
=EQUALNOTcase                      Abs   67182 #0001066E -  1275
=EQUALOR                           Abs   65272 #0000FEF8 -  1276
=EQUALPOSCMP                       Abs   67807 #000108DF -  1277
=EQUALPOSCOMP                      Abs   67807 #000108DF -  1278
=EQUALcase                         Abs   66937 #00010579 -  1279
=EQUALcasedrp                      Abs   66847 #0001051F -  1280
=EQcase                            Abs   54524 #0000D4FC -  1281
=EQcaseDROP                        Abs   85717 #00014ED5 -  5078
=EQcasedrop                        Abs   54403 #0000D483 -  1282
=ERRBEEP                           Abs  132994 #00020782 -  1283
=ERRJMP                            Abs   22223 #000056CF -  1284  6575
=ERROR@                            Abs   21752 #000054F8 -  1285
=ERRORCLR                          Abs   21829 #00005545 -  1286
=ERROROUT                          Abs   65747 #000100D3 -  1287
=ERRORSTO                          Abs   21792 #00005520 -  1288
=ERRSET                            Abs   22108 #0000565C -  1289
=ERRTRAP                           Abs   22198 #000056B6 -  1290
=EVAL                              Abs   30556 #0000775C -  1291  6439
=EVALCRUNCH                        Abs  134074 #00020BBA -  1292
=EXITMSGSTO                        Abs   22069 #00005635 -  1293
=EXPAND                            Abs   55269 #0000D7E5 -  1294
=EXTN                              Abs   23610 #00005C3A -  1295
=EXTOBOB                           Abs   73357 #00011E8D -  1296
=EXTREAL                           Abs   18707 #00004913 -  1297
=EXTSYM                            Abs   18797 #0000496D -  1298
=EditExstCase                      Abs   67142 #00010646 -  1299
=ElsieGet                          Abs  258715 #0003F29B -  1300
=ElsiePkt                          Abs  258716 #0003F29C -  1301
=ElsieSend                         Abs  258717 #0003F29D -  1302
=Embedded?                         Abs   59586 #0000E8C2 -  1303
=EmptyList?                        Abs  258922 #0003F36A -  1304
=EmptyRList?                       Abs  259615 #0003F61F -  1305
=EnsureMenuOff                     Abs  230273 #00038381 -  1306  6481
=EnterGraphView                    Abs  229630 #000380FE -  1307
=EnterTextView                     Abs  229580 #000380CC -  1308
 ErableHeaderBit                   Abs       0 #00000000 -  5880
 ErableHeaderFl                    Abs      93 #0000005D -  5878  5879  5880
 ErableHeaderNib                   Abs      23 #00000017 -  5879
=EraseGraph                        Abs  259568 #0003F5F0 -  1309
=EraseGrob                         Abs  259616 #0003F620 -  1310
=Err#Chr00                         Abs   72717 #00011C0D -  1311
=Err#Cont                          Abs   72907 #00011CCB -  1312
=Err#Kill                          Abs   72767 #00011C3F -  1313
=Err#NoLstArg                      Abs   72937 #00011CE9 -  1314
=Err#NoLstStk                      Abs   72777 #00011C49 -  1315
 ErrorBeepBit                      Abs       3 #00000003 -  5292
 ErrorBeepFl                       Abs      56 #00000038 -  5236  5291  5292
 ErrorBeepNib                      Abs      13 #0000000D -  5291
=EvalPart1                         Abs   97477 #00017CC5 -  1316
=EvalPart2                         Abs   97497 #00017CD9 -  1317
=EvalPart3                         Abs   97517 #00017CED -  1318
 ExactModeBit                      Abs       0 #00000000 -  5905
 ExactModeFl                       Abs     105 #00000069 -  5903  5904  5905
 ExactModeNib                      Abs      26 #0000001A -  5904
=ExitAtLOOP                        Abs   67722 #0001088A -  1319
=Extremum@                         Abs  160675 #000273A3 -  1320
=FALSE                             Abs   15040 #00003AC0 -  1321
=FALSE'                            Abs   66102 #00010236 -  1322
=FALSETRUE                         Abs   65027 #0000FE03 -  1323
=FAreaBad?                         Abs  259633 #0003F631 -  1324
=FIFTEEN                           Abs   16607 #000040DF -  1325
=FIFTY                             Abs   16957 #0000423D -  1326
=FIFTYEIGHT                        Abs   17037 #0000428D -  1327
=FIFTYFIVE                         Abs   17007 #0000426F -  1328
=FIFTYFOUR                         Abs   16997 #00004265 -  1329
=FIFTYNINE                         Abs   17047 #00004297 -  1330
=FIFTYONE                          Abs   16967 #00004247 -  1331
=FIFTYSEVEN                        Abs   17027 #00004283 -  1332
=FIFTYSIX                          Abs   17017 #00004279 -  1333
=FIFTYTHREE                        Abs   16987 #0000425B -  1334
=FIFTYTWO                          Abs   16977 #00004251 -  1335
=FIVE                              Abs   16507 #0000407B -  1336
=FIVEFOUR                          Abs   17297 #00004391 -  1337
=FIVESIX                           Abs   17317 #000043A5 -  1338
=FIVETHREE                         Abs   17287 #00004387 -  1339
=FLUSHKEYS                         Abs    3130 #00000C3A -  1340
=FORTY                             Abs   16857 #000041D9 -  1341
=FORTYEIGHT                        Abs   16937 #00004229 -  1342
=FORTYFIVE                         Abs   16907 #0000420B -  1343
=FORTYFOUR                         Abs   16897 #00004201 -  1344
=FORTYNINE                         Abs   16947 #00004233 -  1345
=FORTYONE                          Abs   16867 #000041E3 -  1346
=FORTYSEVEN                        Abs   16927 #0000421F -  1347
=FORTYSIX                          Abs   16917 #00004215 -  1348
=FORTYTHREE                        Abs   16887 #000041F7 -  1349
=FORTYTWO                          Abs   16877 #000041ED -  1350
=FOUR                              Abs   16497 #00004071 -  1351
=FOURFIVE                          Abs   17147 #000042FB -  1352
=FOURROLLROT                       Abs   63714 #0000F8E2 -  1353
=FOURTEEN                          Abs   16597 #000040D5 -  1354
=FOURTHREE                         Abs   17127 #000042E7 -  1355
=FOURTWO                           Abs   17117 #000042DD -  1356
=FOURpsh                           Abs  258191 #0003F08F -  1357
=FSTFLOATROM#                      Abs   19017 #00004A49 -  1358
=FSTMACROROM#                      Abs   73057 #00011D61 -  1359
=FTypeCheck?                       Abs  259619 #0003F623 -  1360
=FTypeFixedL?                      Abs  259618 #0003F622 -  1361
=FTypeList?                        Abs  259620 #0003F624 -  1362
=FTypeText?                        Abs  259621 #0003F625 -  1363
=FUNCPLOT                          Abs  259622 #0003F626 -  1364
=FalseFalse                        Abs  258192 #0003F090 -  1365
=FalseTrue                         Abs   65027 #0000FE03 -  1366
 FastEViewBit                      Abs       2 #00000002 -  5295
 FastEViewNib                      Abs      14 #0000000E -  5294
 FastEqViewFl                      Abs      59 #0000003B -  5239  5294  5295
 FilerConfirmBit                   Abs       0 #00000000 -  5832
 FilerConfirmFl                    Abs      77 #0000004D -  5830  5831  5832
 FilerConfirmNib                   Abs      19 #00000013 -  5831
 FilerConfirmationBit              Abs       3 #00000003 -  5829
 FilerConfirmationFl               Abs      76 #0000004C -  5827  5828  5829
 FilerConfirmationNib              Abs      18 #00000012 -  5828
=FitLeftSmF                        Abs  258927 #0003F36F -  1367
=FitRightSmF                       Abs  259623 #0003F627 -  1368
=Format                            Abs     861 #0000035D -  6311
=Format@                           Abs  160255 #000271FF -  1369
 FullScreenEditBit                 Abs       0 #00000000 -  5808
 FullScreenEditFl                  Abs      69 #00000045 -  5806  5807  5808
 FullScreenEditNib                 Abs      17 #00000011 -  5807
=FuncPLoop                         Abs  259624 #0003F628 -  1370
=FuncPSetup1                       Abs  259625 #0003F629 -  1371
=FuncSplitViewers                  Abs   93566 #00016D7E -  1372
 FunctPlotBit                      Abs       1 #00000001 -  5298
 FunctPlotFl                       Abs      30 #0000001E -  5210  5297  5298
 FunctPlotNib                      Abs       7 #00000007 -  5297
=GARBAGE                           Abs   26434 #00006742 -  1373
=GBUFF                             Abs  125311 #0001E97F -  1374
 GCursorBit                        Abs       3 #00000003 -  5301
 GCursorFl                         Abs      32 #00000020 -  5212  5300  5301
 GCursorNib                        Abs       7 #00000007 -  5300
=GDISP?                            Abs  128194 #0001F4C2 -  1375
=GDISPCENTER                       Abs  259631 #0003F62F -  1376
=GET@tTYPER                        Abs   76926 #00012C7E -  1377
=GETATELN                          Abs   14109 #0000371D -  1378
=GETEXITMSG                        Abs   22021 #00005605 -  1379
=GETKEY                            Abs  157215 #0002661F -  1380
=GETKEY*                           Abs  156870 #000264C6 -  5066
=GETLAM                            Abs   32126 #00007D7E -  1381
=GETLAMPAIR                        Abs   54177 #0000D3A1 -  1382
=GETPTRLOOP                        Abs   22780 #000058FC -  1383
=GETSERIAL                         Abs  258718 #0003F29E -  1384
=GETTHEMESG                        Abs   21878 #00005576 -  1385
=GETTOUCH                          Abs   20382 #00004F9E -  1386
=GETXMAX                           Abs  259745 #0003F6A1 -  1387
=GETXMIN                           Abs  259747 #0003F6A3 -  1388
=GETXPOS                           Abs  259085 #0003F40D -  1389
=GETYMAX                           Abs  259744 #0003F6A0 -  1390
=GETYMIN                           Abs  259746 #0003F6A2 -  1391
=GETYPOS                           Abs  259086 #0003F40E -  1392
=GPOverWrALp                       Abs   13938 #00003672 -  1393
=GPPushFLoop                       Abs   56739 #0000DDA3 -  1394
=GPPushTLoop                       Abs   56714 #0000DD8A -  1395
=GROB!                             Abs  120580 #0001D704 -  1396
=GROB!ZERO                         Abs  121592 #0001DAF8 -  1397
=GROB!ZERODRP                      Abs   65797 #00010105 -  1398
=GROB+#                            Abs  259634 #0003F632 -  1399
=GROB>GDISP                        Abs  127662 #0001F2AE -  1400
=GROBBUFF!                         Abs  259635 #0003F633 -  1401
=GROBDIM                           Abs   86180 #000150A4 -  1402
=GROBDIMw                          Abs   66687 #0001047F -  1403
=GROBVIEW                          Abs  259636 #0003F634 -  1404
=GetApDirList                      Abs  259499 #0003F5AB -  1405
=GetBVars.1                        Abs  258719 #0003F29F -  1406
=GetChoiceFmt                      Abs  259637 #0003F635 -  1407
=GetChoiceList                     Abs  259638 #0003F636 -  1408
=GetDASpecFlag                     Abs  258933 #0003F375 -  1409
=GetElNoRomp                       Abs   89090 #00015C02 -  1410
=GetLastNotThis                    Abs  259088 #0003F410 -  1411
=GetNextFId                        Abs  259639 #0003F637 -  1412
=GetNextToken                      Abs  258208 #0003F0A0 -  1413
=GetObType$                        Abs  258721 #0003F2A1 -  1414
=GetObTypePr$                      Abs  258720 #0003F2A0 -  1415
=GetPart1                          Abs   97417 #00017C89 -  1416
=GetPart2                          Abs   97437 #00017C9D -  1417
=GetPart3                          Abs   97457 #00017CB1 -  1418
=GetPrevFId                        Abs  259640 #0003F638 -  1419
=GraphTableUI                      Abs  259564 #0003F5EC -  1420
=GraphZoomUI                       Abs  259565 #0003F5ED -  1421
 GrobDisplayBit                    Abs       2 #00000002 -  5850
 GrobDisplayFl                     Abs      83 #00000053 -  5848  5849  5850
 GrobDisplayNib                    Abs      20 #00000014 -  5849
=GtoField                          Abs  259641 #0003F639 -  1422
=H/W>KeyCode                       Abs  147344 #00023F90 -  5069
=HARDBUFF                          Abs  125263 #0001E94F -  1423
=HARDBUFF2                         Abs  125279 #0001E95F -  1424
=HARDHEIGHT                        Abs  126598 #0001EE86 -  1425
=HEIGHTENGROB                      Abs  127211 #0001F0EB -  1426
=HOME>BAK                          Abs   40379 #00009DBB -  1427
=HOMEDIR                           Abs   38552 #00009698 -  1428
=HTick                             Abs     327 #00000147 -  6125
=HTick@                            Abs  159795 #00027033 -  1429
=HXSREAL                           Abs   18227 #00004733 -  1430
=HZoom                             Abs     383 #0000017F -  6145
=HZoom@                            Abs  159835 #0002705B -  1431
=HisWidth@                         Abs  161550 #0002770E -  1432
=Hmax@                             Abs  161590 #00027736 -  1433
=Hmin@                             Abs  161570 #00027722 -  1434
=ID>$                              Abs   25545 #000063C9 -  1435
=IDARRY                            Abs   17457 #00004431 -  1436
=IDCMP                             Abs   17437 #0000441D -  1437
=IDLIST                            Abs   17467 #0000443B -  1438
=IDLISTOB                          Abs   73047 #00011D57 -  1439
=IDREAL                            Abs   17427 #00004413 -  1440
=IDREALOB                          Abs   73037 #00011D4D -  1441
=IFECheck                          Abs  259642 #0003F63A -  1442
=IFEChoosByChr                     Abs  259643 #0003F63B -  1443
=IFEChooseNext                     Abs  259644 #0003F63C -  1444
=IFEDispClient                     Abs  259645 #0003F63D -  1445
=IFEDispField                      Abs  259646 #0003F63E -  1446
=IFEDispHelp                       Abs  259647 #0003F63F -  1447
=IFEDispLabel                      Abs  259648 #0003F640 -  1448
=IFEDispTitle                      Abs  259649 #0003F641 -  1449
=IFEUnShowSel                      Abs  259650 #0003F642 -  1450
=IFEdLineMenu                      Abs  259651 #0003F643 -  1451
=IFMenu                            Abs  259652 #0003F644 -  1452
=IFSymbViewUI                      Abs  259754 #0003F6AA -  1453
=INCOMPDROP                        Abs   62562 #0000F462 -  1454
=INDEX@                            Abs   31226 #000079FA -  1455
=INDEX@#-                          Abs   65647 #0001006F -  1456
=INDEXSTO                          Abs   31305 #00007A49 -  1457
=INHARDROM?                        Abs   82103 #000140B7 -  1458
=INNER#1=                          Abs   65407 #0000FF7F -  1459
=INNERCOMP                         Abs   23656 #00005C68 -  1460  6535  6605
                                        6631  6721
=INNERDUP                          Abs   62747 #0000F51B -  1461
=INTEGER337                        Abs   72917 #00011CD5 -  1462
=INTEMNOTREF?                      Abs   29468 #0000731C -  1463
=INT_00                            Abs  230977 #00038641 -  1464  6424
=INT_01                            Abs  230982 #00038646 -  1465  6467
=INT_02                            Abs  230987 #0003864B -  1466  6471
=INT_03                            Abs  230992 #00038650 -  1467  6497
=INT_04                            Abs  230997 #00038655 -  1468
=INT_05                            Abs  231002 #0003865A -  1469  6556
=INT_06                            Abs  231007 #0003865F -  1470
=INT_07                            Abs  231012 #00038664 -  1471
=INT_08                            Abs  231017 #00038669 -  1472
=INT_09                            Abs  231022 #0003866E -  1473
=INT_0A                            Abs  231027 #00038673 -  1474
=INT_0B                            Abs  231032 #00038678 -  1475
=INT_0C                            Abs  231037 #0003867D -  1476
=INT_0D                            Abs  231042 #00038682 -  1477
=INT_0E                            Abs  231047 #00038687 -  1478
=INT_0F                            Abs  231052 #0003868C -  1479
=INT_10                            Abs  231057 #00038691 -  1480
=INT_11                            Abs  231062 #00038696 -  1481
=INT_12                            Abs  231067 #0003869B -  1482
=INT_13                            Abs  231072 #000386A0 -  1483
=INT_14                            Abs  231077 #000386A5 -  1484
=INT_15                            Abs  231082 #000386AA -  1485
=INT_16                            Abs  231087 #000386AF -  1486
=INT_17                            Abs  231092 #000386B4 -  1487
=INT_18                            Abs  231097 #000386B9 -  1488
=INT_19                            Abs  231102 #000386BE -  1489
=INT_1A                            Abs  231107 #000386C3 -  1490
=INT_1B                            Abs  231112 #000386C8 -  1491
=INT_1C                            Abs  231117 #000386CD -  1492
=INT_1D                            Abs  231122 #000386D2 -  1493
=INT_1E                            Abs  231127 #000386D7 -  1494
=INT_1F                            Abs  231132 #000386DC -  1495
=INT_NN                            Abs  230868 #000385D4 -  1496
=INVGROB                           Abs  124349 #0001E5BD -  1497
 IODataFmtBit                      Abs       2 #00000002 -  5313
 IODataFmtFl                       Abs      35 #00000023 -  5215  5312  5313
 IODataFmtNib                      Abs       8 #00000008 -  5312
 IODeviceBit                       Abs       0 #00000000 -  5316
 IODeviceFl                        Abs      33 #00000021 -  5213  5315  5316
 IODeviceNib                       Abs       8 #00000008 -  5315
=ISTOP@                            Abs   31266 #00007A22 -  1498
=ISTOPSTO                          Abs   31342 #00007A6E -  1499
=IT                                Abs   54661 #0000D585 -  1500
=ITE                               Abs   54945 #0000D6A1 -  1501
=ITE_DROP                          Abs   54817 #0000D621 -  1502
=Id>ApNameId                       Abs  259653 #0003F645 -  1503
=InAplet?                          Abs  258947 #0003F383 -  1504
=InApletF?                         Abs  259654 #0003F646 -  1505
 IndexWrapBit                      Abs       3 #00000003 -  5304
 IndexWrapFl                       Abs      64 #00000040 -  5244  5303  5304
 IndexWrapNib                      Abs      15 #0000000F -  5303
 InfResActBit                      Abs       1 #00000001 -  5307
 InfResActFl                       Abs      22 #00000016 -  5204  5306  5307
 InfResActNib                      Abs       5 #00000005 -  5306
 InfResultBit                      Abs       1 #00000001 -  5310
 InfResultFl                       Abs      26 #0000001A -  5208  5309  5310
 InfResultNib                      Abs       6 #00000006 -  5309
=Init2ColMets                      Abs  259655 #0003F647 -  1506
=InitEnab                          Abs   40993 #0000A021 -  1507
=InitIndep                         Abs  259095 #0003F417 -  1508
=InitListMets                      Abs  259500 #0003F5AC -  1509
=InitMenu                          Abs  152125 #0002523D -  1510
=Init_window                       Abs  259656 #0003F648 -  1511
=InpFormVEntry                     Abs  259529 #0003F5C9 -  1512
=InpFormVExit                      Abs  259524 #0003F5C4 -  1513
=InpFormViewUI                     Abs  259525 #0003F5C5 -  1514
 IntTable                          Rel     933 #000003A5 -  6331  6376
=InvalServCmd                      Abs   73317 #00011E65 -  1515
=InvertField                       Abs  259657 #0003F649 -  1516
=IsIFMenu?                         Abs  259658 #0003F64A -  1517
=IsNullField?                      Abs  259659 #0003F64B -  1518
=IsTaskSwKey?                      Abs  148962 #000245E2 -  1519
=Isect@                            Abs  160635 #0002737B -  1520
=JINDEX@                           Abs   31281 #00007A31 -  1521
=JINDEXSTO                         Abs   31366 #00007A86 -  1522
=JSTOP@                            Abs   31293 #00007A3D -  1523
=JSTOPSTO                          Abs   31387 #00007A9B -  1524
=JUMPBOT                           Abs  259660 #0003F64C -  1525
=JUMPLEFT                          Abs  259661 #0003F64D -  1526
=JUMPRIGHT                         Abs  259662 #0003F64E -  1527
=JUMPTOP                           Abs  259663 #0003F64F -  1528
=JstGETTHEMSG                      Abs   21913 #00005599 -  1529
=KEYINBUFFER?                      Abs  158019 #00026943 -  1530
=KILLGDISP                         Abs  127867 #0001F37B -  1531
 KernelParamBit                    Abs       1 #00000001 -  5835
 KernelParamFl                     Abs      78 #0000004E -  5833  5834  5835
 KernelParamNib                    Abs      19 #00000013 -  5834
=Key>StdKeyOb                      Abs  146475 #00023C2B -  1532
=KeyFace                           Abs  225145 #00036F79 -  1533  6515
 KeystrokeBeepBit                  Abs       2 #00000002 -  5826
 KeystrokeBeepFl                   Abs      75 #0000004B -  5824  5825  5826
 KeystrokeBeepNib                  Abs      18 #00000012 -  5825
 L1                                Rel      58 #0000003A -  6023  6053
 L10                               Rel     365 #0000016D -  6125  6135
 L11                               Rel     393 #00000189 -  6135  6145
 L12                               Rel     421 #000001A5 -  6145  6155
 L13                               Rel     449 #000001C1 -  6155  6165
 L14                               Rel     477 #000001DD -  6165  6173
 L15                               Rel     494 #000001EE -  6173  6181
 L16                               Rel     522 #0000020A -  6181  6189
 L17                               Rel     550 #00000226 -  6189  6197
 L18                               Rel     578 #00000242 -  6197  6203
 L19                               Rel     595 #00000253 -  6203  6210
 L2                                Rel     141 #0000008D -  6053  6063
 L20                               Rel     612 #00000264 -  6210  6217
 L21                               Rel     629 #00000275 -  6217  6225
 L22                               Rel     657 #00000291 -  6225  6233
 L23                               Rel     685 #000002AD -  6233  6241
 L24                               Rel     713 #000002C9 -  6241  6251
 L25                               Rel     741 #000002E5 -  6251  6261
 L26                               Rel     769 #00000301 -  6261  6273
 L27                               Rel     797 #0000031D -  6273  6281
 L28                               Rel     814 #0000032E -  6281  6287
 L29                               Rel     831 #0000033F -  6287  6293
 L3                                Rel     169 #000000A9 -  6063  6073
 L30                               Rel     848 #00000350 -  6293  6299
 L31                               Rel     865 #00000361 -  6299  6305
 L32                               Rel     882 #00000372 -  6305  6311
 L33                               Rel     899 #00000383 -  6311  6319
 L34                               Rel     916 #00000394 -  6319  6331
 L4                                Rel     197 #000000C5 -  6073  6083
 L5                                Rel     225 #000000E1 -  6083  6093
 L6                                Rel     253 #000000FD -  6093  6101
 L7                                Rel     281 #00000119 -  6101  6109
 L8                                Rel     309 #00000135 -  6109  6117
 L9                                Rel     337 #00000151 -  6117  6125
=LAMANYANY                         Abs   73057 #00011D61 -  1534
=LAMLIST                           Abs   17637 #000044E5 -  1535
=LAMREAL                           Abs   17587 #000044B3 -  1536
=LAST$                             Abs   64341 #0000FB55 -  1537
=LASTBUTN                          Abs  166426 #00028A1A -  1538
=LASTRAM-WORD                      Abs   35893 #00008C35 -  1539
=LEDispBorder                      Abs  259664 #0003F650 -  1540
=LEDispItem                        Abs  259665 #0003F651 -  1541
=LEDispList                        Abs  259666 #0003F652 -  1542
=LEDispPrompt                      Abs  259667 #0003F653 -  1543
=LEN$                              Abs   24047 #00005DEF -  1544
=LENCOMP                           Abs   24116 #00005E34 -  1545
=LESetIDecomp                      Abs  259668 #0003F654 -  1546
=LESetItem                         Abs  258948 #0003F384 -  1547
=LESetRowWidth                     Abs  259669 #0003F655 -  1548
=LF$                               Abs   74948 #000124C4 -  1549
=LHighlight                        Abs  259670 #0003F656 -  1550
=LINECHANGE                        Abs  259671 #0003F657 -  1551
=LINEOFF                           Abs  258952 #0003F388 -  1552
=LINEOFF3                          Abs  258953 #0003F389 -  1553
=LINEON                            Abs  258954 #0003F38A -  1554
=LINEON3                           Abs  258955 #0003F38B -  1555
=LISTCMP                           Abs   17277 #0000437D -  1556
=LISTID                            Abs   17317 #000043A5 -  1557
=LISTLAM                           Abs   17327 #000043AF -  1558
=LISTLISTOB                        Abs   73027 #00011D43 -  1559
=LISTOB                            Abs   17257 #00004369 -  1560
=LISTREAL                          Abs   17267 #00004373 -  1561
=LISTREALOB                        Abs   73007 #00011D2F -  1562
=LISTREALREAL                      Abs   73017 #00011D39 -  1563
=LOOP                              Abs   31501 #00007B0D -  1564
=LSTBIMACROM#                      Abs   73057 #00011D61 -  1565
=LUnHighlight                      Abs  259672 #0003F658 -  1566
 LastArgsBit                       Abs       2 #00000002 -  5319
 LastArgsFl                        Abs      55 #00000037 -  5235  5318  5319
 LastArgsNib                       Abs      13 #0000000D -  5318
=LastBut0                          Abs  166168 #00028918 -  1567
=LastBut1                          Abs  166175 #0002891F -  1568
=LastBut10                         Abs  166238 #0002895E -  1569
=LastBut11                         Abs  166245 #00028965 -  1570
=LastBut12                         Abs  166252 #0002896C -  1571
=LastBut13                         Abs  166259 #00028973 -  1572
=LastBut14                         Abs  166266 #0002897A -  1573
=LastBut15                         Abs  166273 #00028981 -  1574
=LastBut16                         Abs  166280 #00028988 -  1575
=LastBut17                         Abs  166287 #0002898F -  1576
=LastBut18                         Abs  166294 #00028996 -  1577
=LastBut19                         Abs  166301 #0002899D -  1578
=LastBut2                          Abs  166182 #00028926 -  1579
=LastBut20                         Abs  166308 #000289A4 -  1580
=LastBut21                         Abs  166315 #000289AB -  1581
=LastBut22                         Abs  166322 #000289B2 -  1582
=LastBut23                         Abs  166329 #000289B9 -  1583
=LastBut24                         Abs  166336 #000289C0 -  1584
=LastBut25                         Abs  166343 #000289C7 -  1585
=LastBut26                         Abs  166350 #000289CE -  1586
=LastBut27                         Abs  166357 #000289D5 -  1587
=LastBut28                         Abs  166364 #000289DC -  1588
=LastBut29                         Abs  166371 #000289E3 -  1589
=LastBut3                          Abs  166189 #0002892D -  1590  6534  6591
                                        6604  6629  6639  6682  6719  6729
=LastBut30                         Abs  166378 #000289EA -  1591
=LastBut31                         Abs  166385 #000289F1 -  1592
=LastBut32                         Abs  166392 #000289F8 -  1593
=LastBut4                          Abs  166196 #00028934 -  1594
=LastBut5                          Abs  166203 #0002893B -  1595
=LastBut6                          Abs  166210 #00028942 -  1596
=LastBut7                          Abs  166217 #00028949 -  1597
=LastBut8                          Abs  166224 #00028950 -  1598
=LastBut9                          Abs  166231 #00028957 -  1599
=LastEq                            Abs     540 #0000021C -  6197
=LastEq@                           Abs  159955 #000270D3 -  1600
=LastIndep                         Abs     512 #00000200 -  6189
=LastIndep@                        Abs  159935 #000270BF -  1601
=LastX                             Abs     456 #000001C8 -  6173
=LastX@                            Abs  159895 #00027097 -  1602
=LastY                             Abs     484 #000001E4 -  6181
=LastY@                            Abs  159915 #000270AB -  1603
=LeaveGraphView                    Abs  229605 #000380E5 -  1604  6645
=LeaveTextView                     Abs  229605 #000380E5 -  1605
=ListBar                           Abs  259673 #0003F659 -  1606
=ListNames                         Abs  259674 #0003F65A -  1607
=ListOfEqs@                        Abs  160730 #000273DA -  1608
=LockAlpha                         Abs  151587 #00025023 -  1609
=Lookup                            Abs   60912 #0000EDF0 -  1610
=Lookup.1                          Abs   60937 #0000EE09 -  1611
=M+prep                            Abs  258722 #0003F2A2 -  1612
=MAKEARRY                          Abs   94714 #000171FA -  1613
=MAKEGROB                          Abs  120354 #0001D622 -  1614
=MAKERRP                           Abs   32701 #00007FBD -  1615
 MASDDecompilerBit                 Abs       1 #00000001 -  5859
 MASDDecompilerFl                  Abs      86 #00000056 -  5857  5858  5859
 MASDDecompilerNib                 Abs      21 #00000015 -  5858
=MATCON                            Abs   94726 #00017206 -  1616
=MATREDIM                          Abs   94738 #00017212 -  1617
=MATTRN                            Abs   94750 #0001721E -  1618
=MDIMS                             Abs   94762 #0001722A -  1619
=MDIMSDROP                         Abs   63607 #0000F877 -  1620
=MEM                               Abs   26465 #00006761 -  1621
=MEMERR                            Abs   16467 #00004053 -  1622
=MENUOFF?                          Abs  258962 #0003F392 -  1623
=MINUSFIVE                         Abs   73417 #00011EC9 -  1624  6434
=MINUSFOUR                         Abs   73407 #00011EBF -  1625  6432
=MINUSONE                          Abs   73377 #00011EA1 -  1626  6416
=MINUSTHREE                        Abs   73397 #00011EB5 -  1627  6430
=MINUSTWO                          Abs   73387 #00011EAB -  1628  6428
 MKSmallFontMenuBit                Abs       3 #00000003 -  5853
 MKSmallFontMenuFl                 Abs      84 #00000054 -  5851  5852  5853
 MKSmallFontMenuNib                Abs      20 #00000014 -  5852
 MLMASDModeBit                     Abs       3 #00000003 -  5877
 MLMASDModeFl                      Abs      92 #0000005C -  5875  5876  5877
 MLMASDModeNib                     Abs      22 #00000016 -  5876
=Make1stAplet                      Abs  259676 #0003F65C -  1629
=MakeBoxLabel                      Abs   69574 #00010FC6 -  1630
=MakeDirLabel                      Abs   69672 #00011028 -  1631
=MakeInvLabel                      Abs   69770 #0001108A -  1632
=MakeNoteVTtl                      Abs  258963 #0003F393 -  1633
=MakeNumSVTtl                      Abs  259677 #0003F65D -  1634
=MakeNumVTtl                       Abs  259675 #0003F65B -  1635
=MakePlotSVTtl                     Abs  259678 #0003F65E -  1636
=MakePlotVTtl                      Abs  259679 #0003F65F -  1637
=MakeSketVTtl                      Abs  259680 #0003F660 -  1638
=MakeStdLabel                      Abs   69476 #00010F64 -  1639
=MakeSymbSVTtl                     Abs  259681 #0003F661 -  1640
=MakeSymbVTtl                      Abs  259682 #0003F662 -  1641
=MakeTitleBar                      Abs  258964 #0003F394 -  1642
=MakeViewTitle                     Abs  259683 #0003F663 -  1643
=MemStoAns                         Abs  259858 #0003F712 -  1644
 MenuOnBit                         Abs       3 #00000003 -  5889
 MenuOnFl                          Abs      96 #00000060 -  5887  5888  5889
 MenuOnNib                         Abs      23 #00000017 -  5888
=MiniVar                           Abs  230213 #00038345 -  1645  6429
=ModifierKey?                      Abs  147399 #00023FC7 -  1646
=MoreDown?                         Abs  259684 #0003F664 -  1647
=MoreU/D?                          Abs  259685 #0003F665 -  1648
=MoreUp?                           Abs  259686 #0003F666 -  1649
=MsgBoxMenu                        Abs  258966 #0003F396 -  1650
 MultiDispBit                      Abs       3 #00000003 -  5325
 MultiDispFl                       Abs      52 #00000034 -  5232  5324  5325
 MultiDispNib                      Abs      12 #0000000C -  5324
 MultiLine2GROBBit                 Abs       1 #00000001 -  5811
 MultiLine2GROBFl                  Abs      70 #00000046 -  5809  5810  5811
 MultiLine2GROBNib                 Abs      17 #00000011 -  5810
 MultiLineBit                      Abs       0 #00000000 -  5796
 MultiLineFl                       Abs      65 #00000041 -  5794  5795  5796
 MultiLineNib                      Abs      16 #00000010 -  5795
 MultiLineStringsBit               Abs       1 #00000001 -  5799
 MultiLineStringsFl                Abs      66 #00000042 -  5797  5798  5799
 MultiLineStringsNib               Abs      16 #00000010 -  5798
=N+1DROP                           Abs   63567 #0000F84F -  1651
=NDROP                             Abs   12910 #0000326E -  1652
=NDUP                              Abs   12761 #000031D9 -  1653
=NDUPN                             Abs   86839 #00015337 -  1654
=NEWINDEP                          Abs  258967 #0003F397 -  1655
=NEWLINE$                          Abs   74948 #000124C4 -  1656
=NEWLINE$&$                        Abs   64121 #0000FA79 -  1657
=NEWLINE&$                         Abs   64121 #0000FA79 -  1658
=NEXTCOMPOB                        Abs   61786 #0000F15A -  1659
=NINE                              Abs   16547 #000040A3 -  1660
=NINETEEN                          Abs   16647 #00004107 -  1661
=NINETY                            Abs   17357 #000043CD -  1662
=NINETYEIGHT                       Abs   17437 #0000441D -  1663
=NINETYFIVE                        Abs   17407 #000043FF -  1664
=NINETYFOUR                        Abs   17397 #000043F5 -  1665
=NINETYNINE                        Abs   17447 #00004427 -  1666
=NINETYTHREE                       Abs   17387 #000043EB -  1667
=NINETYTWO                         Abs   17377 #000043E1 -  1668
=NOP                               Abs   30300 #0000765C -  1669  6431  6433
                                        6435
=NOT                               Abs   15090 #00003AF2 -  1670
=NOT?SEMI                          Abs   54773 #0000D5F5 -  1671
=NOT?SWAPDROP                      Abs   63517 #0000F81D -  1672
=NOTAND                            Abs   62767 #0000F52F -  1673
=NOTESCXT!                         Abs   75478 #000126D6 -  1674
=NOTESCXT@                         Abs   75494 #000126E6 -  1675
=NOT_UNTIL                         Abs   64702 #0000FCBE -  1676
=NOT_WHILE                         Abs   64727 #0000FCD7 -  1677
=NOTcase                           Abs   54646 #0000D576 -  1678
=NOTcase2DROP                      Abs   54605 #0000D54D -  1679
=NOTcase2drop                      Abs   54489 #0000D4D9 -  1680
=NOTcaseDROP                       Abs   54569 #0000D529 -  1681
=NOTcaseFALSE                      Abs   65867 #0001014B -  1682
=NOTcaseTRUE                       Abs   65842 #00010132 -  1683
=NOTcasedrop                       Abs   54449 #0000D4B1 -  1684
=NOTcsdrpfls                       Abs   66432 #00010380 -  1685
=NTHCOMDDUP                        Abs   62967 #0000F5F7 -  1686
=NTHCOMPDROP                       Abs   62582 #0000F476 -  1687  6593
=NTHELCOMP                         Abs   24175 #00005E6F -  1688
=NTHOF                             Abs   67832 #000108F8 -  1689
=NULL$                             Abs   23960 #00005D98 -  1690
=NULL$?                            Abs   23848 #00005D28 -  1691
=NULL$SWAP                         Abs   63027 #0000F633 -  1692
=NULL::                            Abs   23990 #00005DB6 -  1693
=NULLCOMP?                         Abs   23920 #00005D70 -  1694
=NULLHXS                           Abs   23950 #00005D8E -  1695
=NULLID                            Abs  133887 #00020AFF -  1696
=NULLLAM                           Abs   68091 #000109FB -  1697
=NULLSYMB                          Abs   23980 #00005DAC -  1698
=NULLargcase                       Abs   93923 #00016EE3 -  1699
=NULL{}                            Abs   23970 #00005DA2 -  1700  6502  6504
                                        6506  6508  6510  6723
=NUMEVAL1                          Abs   80902 #00013C06 -  1701
=NcaseSIZEERR                      Abs   66477 #000103AD -  1702
=NcaseTYPEERR                      Abs   66497 #000103C1 -  1703
=NextApOfType                      Abs  259687 #0003F667 -  1704
=NextTextLine                      Abs  259688 #0003F668 -  1705
 NoAutoCRBit                       Abs       1 #00000001 -  5328
 NoAutoCRFl                        Abs      38 #00000026 -  5218  5327  5328
 NoAutoCRNib                       Abs       9 #00000009 -  5327
=NoExitAction                      Abs  144560 #000234B0 -  1706
 NoIOStMsgBit                      Abs       2 #00000002 -  5331
 NoIOStMsgNib                      Abs       9 #00000009 -  5330
 NoIOStsMsgFl                      Abs      39 #00000027 -  5219  5330  5331
 NoParseBit                        Abs       2 #00000002 -  5334
 NoParseFl                         Abs      63 #0000003F -  5243  5333  5334
 NoParseNib                        Abs      15 #0000000F -  5333
=NotAndbitmap                      Abs  232555 #00038C6B -  1707
=NotesViewUI                       Abs  259753 #0003F6A9 -  1708
=NullMenuKey                       Abs  170873 #00029B79 -  1709  6543  6545
                                        6547  6549
 NumDigsBCt                        Abs       4 #00000004 -  5228
 NumDigsBit1                       Abs       0 #00000000 -  5337
 NumDigsFl1                        Abs      45 #0000002D -  5227  5336  5337
 NumDigsNib                        Abs      11 #0000000B -  5336
 NumDispBCt                        Abs       2 #00000002 -  5230
 NumDispBit1                       Abs       0 #00000000 -  5340
 NumDispFl1                        Abs      49 #00000031 -  5229  5339  5340
 NumDispNib                        Abs      12 #0000000C -  5339
=OB>BAK                            Abs  258723 #0003F2A3 -  1710
=OCRC                              Abs   24829 #000060FD -  1711
=OFFSRRP                           Abs   32391 #00007E87 -  1712
=ONE                               Abs   16467 #00004053 -  1713  6514  6564
=ONE#>                             Abs   65487 #0000FFCF -  1714
=ONECOLA                           Abs   66197 #00010295 -  1715
=ONEDUP                            Abs   66392 #00010358 -  1716
=ONEFALSE                          Abs   65067 #0000FE2B -  1717
=ONEFALSE'                         Abs   66077 #0001021D -  1718
=ONEHUNDRED                        Abs   17457 #00004431 -  1719
=ONEONE                            Abs   66392 #00010358 -  1720
=ONESWAP                           Abs   63297 #0000F741 -  1721
=ONE_DO                            Abs   31655 #00007BA7 -  1722
=ONE_EQ                            Abs   64637 #0000FC7D -  1723
=ONSRRP?                           Abs   32614 #00007F66 -  1724
=OR                                Abs   15221 #00003B75 -  1725
=ORNOT                             Abs   65192 #0000FEA8 -  1726
=ORcase                            Abs   58679 #0000E537 -  1727
=OSIZE                             Abs   24763 #000060BB -  1728
=OVER                              Abs   12994 #000032C2 -  1729
=OVER#+                            Abs   65547 #0001000B -  1730
=OVER#-                            Abs   65627 #0001005B -  1731
=OVER#0=                           Abs   65322 #0000FF2A -  1732
=OVER#1-                           Abs   67762 #000108B2 -  1733
=OVER#<                            Abs   65342 #0000FF3E -  1734
=OVER#=                            Abs   56764 #0000DDBC -  1735
=OVER#=case                        Abs   54341 #0000D445 -  1736
=OVER#>                            Abs   65467 #0000FFBB -  1737
=OVER'                             Abs   66017 #000101E1 -  1738
=OVER5PICK                         Abs   66827 #0001050B -  1739
=OVERARSIZE                        Abs   64034 #0000FA22 -  1740
=OVERDUP                           Abs   62887 #0000F5A7 -  1741
=OVEREQcase                        Abs   54524 #0000D4FC -  1742
=OVERINDEX@                        Abs   64817 #0000FD31 -  1743
=OVERSWAP                          Abs   62987 #0000F60B -  1744
=OVERUNROT                         Abs   62987 #0000F60B -  1745
=Ob>Seco                           Abs   67682 #00010862 -  1746
=OnKeyDown?                        Abs    2872 #00000B38 -  1747
=OpenIO                            Abs  258112 #0003F040 -  1748
=OpenUart?Clr                      Abs  258724 #0003F2A4 -  1749
=Orbitmap                          Abs  232517 #00038C45 -  1750
 OverfActBit                       Abs       0 #00000000 -  5343
 OverfActFl                        Abs      21 #00000015 -  5203  5342  5343
 OverfActNib                       Abs       5 #00000005 -  5342
 OverflowBit                       Abs       0 #00000000 -  5346
 OverflowFl                        Abs      25 #00000019 -  5207  5345  5346
 OverflowNib                       Abs       6 #00000006 -  5345
 OverwriteBit                      Abs       3 #00000003 -  5349
 OverwriteFl                       Abs      36 #00000024 -  5216  5348  5349
 OverwriteNib                      Abs       8 #00000008 -  5348
=P::N                              Abs   92030 #0001677E -  1751
=PGMCXT!                           Abs   75446 #000126B6 -  1752
=PGMCXT@                           Abs   75462 #000126C6 -  1753
=PICK                              Abs   13026 #000032E2 -  1754
=PIXOFF                            Abs  130255 #0001FCCF -  1755
=PIXOFF3                           Abs  130211 #0001FCA3 -  1756
=PIXON                             Abs  130270 #0001FCDE -  1757
=PIXON3                            Abs  130233 #0001FCB9 -  1758
=PIXON?                            Abs  130598 #0001FE26 -  1759
=PIXON?3                           Abs  130586 #0001FE1A -  1760
=POLErrorTrap                      Abs  219032 #00035798 -  1761
=POLKeyUI                          Abs  218947 #00035743 -  1762
=POLResUI&Err                      Abs  219082 #000357CA -  1763
=POLRestoreUI                      Abs  219107 #000357E3 -  1764
=POLSaveUI                         Abs  218542 #000355AE -  1765
=POLSetUI                          Abs  218717 #0003565D -  1766
=POLSetUIExt                       Abs  218917 #00035725 -  1767
=POP#                              Abs   28185 #00006E19 -  1768
=PORT0ADDR                         Abs   39996 #00009C3C -  1769
=POS$                              Abs   61012 #0000EE54 -  1770
=POS$REV                           Abs   61024 #0000EE60 -  1771
=POSCHR                            Abs   61012 #0000EE54 -  1772
=POSCHRREV                         Abs   61024 #0000EE60 -  1773
=POSCOMP                           Abs   60687 #0000ED0F -  1774
=PREVRAM-WORD                      Abs   35973 #00008C85 -  1775
=PRINT                             Abs  258725 #0003F2A5 -  1776
=PRLG                              Abs   10492 #000028FC -  1777
=PROGIDCMP                         Abs   73107 #00011D93 -  1778
=PROGIDEXT                         Abs   73127 #00011DA7 -  1779
=PROGIDLIST                        Abs   73117 #00011D9D -  1780
=PROGIDREAL                        Abs   73097 #00011D89 -  1781
=PROTERR                           Abs   73307 #00011E5B -  1782
=PTYPE>PINFO                       Abs  214988 #000347CC -  1783
=PURGE                             Abs   38189 #0000952D -  1784
=PUSH%LOOP                         Abs  111476 #0001B374 -  1785
=PUSHA                             Abs   14982 #00003A86 -  1786
=PUTEL                             Abs  101820 #00018DBC -  1787
=PUTLAM                            Abs   32194 #00007DC2 -  1788
=PUTLIST                           Abs  258115 #0003F043 -  1789
=PUTSERIAL                         Abs  258726 #0003F2A6 -  1790
=PUTXMAX                           Abs   93873 #00016EB1 -  1791
=PUTXMIN                           Abs  259743 #0003F69F -  1792
=PUTYMAX                           Abs   93898 #00016ECA -  1793
=PUTYMIN                           Abs  259742 #0003F69E -  1794
=PageDnNGrob                       Abs   87411 #00015573 -  1795
=PageDnYGrob                       Abs   87343 #0001552F -  1796
=PageUpNGrob                       Abs   87275 #000154EB -  1797
=PageUpYGrob                       Abs   87207 #000154A7 -  1798
=ParOuterLoop                      Abs  218487 #00035577 -  1799
=ParseExpr                         Abs  151092 #00024E34 -  1800
=PickedEqs@                        Abs  259101 #0003F41D -  1801
=PictViewUI                        Abs  259760 #0003F6B0 -  1802
=PlaceFVals                        Abs  259689 #0003F669 -  1803
=Plot2Flg                          Abs     574 #0000023E -  6210
=Plot2Flg@                         Abs  159995 #000270FB -  1804
=PlotCKSUM                         Abs     591 #0000024F -  6217
=PlotCKSUM@                        Abs  160015 #0002710F -  1805
=PlotFlag                          Abs     557 #0000022D -  6203
=PlotFlag@                         Abs  159975 #000270E7 -  1806
=PlotOvViewUI                      Abs  259626 #0003F62A -  1807
=PlotSetViewUI                     Abs  259755 #0003F6AB -  1808
=PlotViewUI                        Abs  259690 #0003F66A -  1809
=PopASavptr                        Abs  105164 #00019ACC -  1810
=Port0Ids                          Abs  258730 #0003F2AA -  1811
=PrepCurrAplet                     Abs  259691 #0003F66B -  1812
=PrepEdLKeyOb                      Abs  258986 #0003F3AA -  1813
 PrettyPrintBit                    Abs       2 #00000002 -  5838
 PrettyPrintFl                     Abs      79 #0000004F -  5836  5837  5838
 PrettyPrintNib                    Abs      19 #00000013 -  5837
 PrintDevBit                       Abs       1 #00000001 -  5352
 PrintDevFl                        Abs      34 #00000022 -  5214  5351  5352
 PrintDevNib                       Abs       8 #00000008 -  5351
=PrintHist                         Abs  258727 #0003F2A7 -  1814
=PrintLcd                          Abs  258728 #0003F2A8 -  1815
=PrintVar                          Abs  258729 #0003F2A9 -  1816
=PrintVarOb                        Abs  258244 #0003F0C4 -  1817
=PurgeAplet                        Abs  259693 #0003F66D -  1818
=PurgeApletOb                      Abs  259692 #0003F66C -  1819
=Push#FLoop                        Abs   82863 #000143AF -  1820
=Put3x5                            Abs  258570 #0003F20A -  1821
=Put5x7                            Abs  232574 #00038C7E -  1822
=PutDASpecFlag                     Abs  258987 #0003F3AB -  1823
=Putbitmap                         Abs  232392 #00038BC8 -  1824
=P{}N                              Abs   91975 #00016747 -  5077
=R>                                Abs   30712 #000077F8 -  1825
=R@                                Abs   30699 #000077EB -  1826
=RAM-WORDNAME                      Abs   35826 #00008BF2 -  1827
=RDROP                             Abs   30608 #00007790 -  1828
=RDROPCOLA                         Abs   58579 #0000E4D3 -  1829
=RDUP                              Abs  133272 #00020898 -  1830
=REALLISTREAL                      Abs   72917 #00011CD5 -  1831
=REALOBOB                          Abs   19017 #00004A49 -  1832
=REALREALOB                        Abs   72747 #00011C2B -  1833
=REALSTRID                         Abs   72837 #00011C85 -  1834
=REALSTRSTR                        Abs   72807 #00011C67 -  1835
=REALcase                          Abs   67082 #0001060A -  1836
=RECLAIMDISP                       Abs  127942 #0001F3C6 -  1837  6574
=REDIMPREP                         Abs  260110 #0003F80E -  1838
=REPEAT                            Abs   31166 #000079BE -  1839
=REPEATER                          Abs   95355 #0001747B -  1840
=REPEATERCH                        Abs   95355 #0001747B -  1841
=REPKEY?                           Abs   20561 #00005051 -  1842
=REPLACE                           Abs   36569 #00008ED9 -  1843  6640  6730
=RESOROMP                          Abs   90572 #000161CC -  1844
=RNDXY                             Abs  115786 #0001C44A -  1845
=ROLL                              Abs   13093 #00003325 -  1846
=ROLLDROP                          Abs   63587 #0000F863 -  1847  6536  6606
=ROLLSWAP                          Abs   63007 #0000F61F -  1848
=ROM-WORD?                         Abs   56112 #0000DB30 -  1849
=ROMPANY                           Abs   18857 #000049A9 -  1850
=ROMPTR>#                          Abs   38354 #000095D2 -  1851
=ROMPTR@                           Abs   34742 #000087B6 -  1852
=ROT                               Abs   12949 #00003295 -  1853
=ROT#+                             Abs   65527 #0000FFF7 -  1854
=ROT#+SWAP                         Abs   63142 #0000F6A6 -  1855
=ROT#-                             Abs   65607 #00010047 -  1856
=ROT#1+                            Abs   65687 #00010097 -  1857
=ROT#1+UNROT                       Abs   86268 #000150FC -  1858
=ROT+SWAP                          Abs   63142 #0000F6A6 -  1859
=ROT2DROP                          Abs   58017 #0000E2A1 -  1860
=ROT2DUP                           Abs   62807 #0000F557 -  1861
=ROTAND                            Abs   62827 #0000F56B -  1862
=ROTDROP                           Abs   52481 #0000CD01 -  1863
=ROTDROPSWAP                       Abs   52462 #0000CCEE -  1864  6635  6725
=ROTDUP                            Abs   58096 #0000E2F0 -  1865
=ROTOVER                           Abs   62847 #0000F57F -  1866
=ROTROT2DROP                       Abs   53014 #0000CF16 -  1867
=ROTSWAP                           Abs   52423 #0000CCC7 -  1868
=ROTUntop&                         Abs   67497 #000107A9 -  1869
=RPICK                             Abs  133455 #0002094F -  1870
=RPIT                              Abs   30934 #000078D6 -  1871
=RPITE                             Abs   30876 #0000789C -  1872
=RROLL                             Abs  133357 #000208ED -  1873
=RSKIP                             Abs   65767 #000100E7 -  1874
=RSWAP                             Abs   52381 #0000CC9D -  1875
 RadixBit                          Abs       2 #00000002 -  5355
 RadixFl                           Abs      51 #00000033 -  5231  5354  5355
 RadixNib                          Abs      12 #0000000C -  5354
=RclAplet                          Abs  258999 #0003F3B7 -  1876
=RclAplet?Err                      Abs  259694 #0003F66E -  1877
=RclFieldVal                       Abs  259695 #0003F66F -  1878
=RclResetVal                       Abs  259696 #0003F670 -  1879
=ReCalcFlag@                       Abs  161670 #00027786 -  1880
 RecursiveEditBit                  Abs       3 #00000003 -  5865
 RecursiveEditFl                   Abs      88 #00000058 -  5863  5864  5865
 RecursiveEditNib                  Abs      21 #00000015 -  5864
 RecursiveStackBit                 Abs       2 #00000002 -  5862
 RecursiveStackFl                  Abs      87 #00000057 -  5860  5861  5862
 RecursiveStackNib                 Abs      21 #00000015 -  5861
=Replace_List                      Abs  259697 #0003F671 -  1881
 ResRepAlmBit                      Abs       2 #00000002 -  5358
 ResRepAlmFl                       Abs      43 #0000002B -  5224  5357  5358
 ResRepAlmNib                      Abs      10 #0000000A -  5357
 ResultsBit                        Abs       2 #00000002 -  5361
 ResultsFl                         Abs       3 #00000003 -  5189  5360  5361
 ResultsNib                        Abs       0 #00000000 -  5360
=Retry                             Abs   73337 #00011E79 -  1882
 RightJustifiedStackBit            Abs       1 #00000001 -  5823
 RightJustifiedStackFl             Abs      74 #0000004A -  5821  5822  5823
 RightJustifiedStackNib            Abs      18 #00000012 -  5822
=Root@                             Abs  160595 #00027353 -  1883
=SAVPTR                            Abs   28531 #00006F73 -  1884
=SCROLLDOWN                        Abs  259001 #0003F3B9 -  1885
=SCROLLLEFT                        Abs  259698 #0003F672 -  1886
=SCROLLRIGHT                       Abs  259699 #0003F673 -  1887
=SCROLLUP                          Abs  259002 #0003F3BA -  1888
=SEFINISH                          Abs  258731 #0003F2AB -  1889
=SEMI                              Abs   12587 #0000312B -  1890  6044  6425
                                        6426  6427  6436  6484  6498  6499  6512
                                        6517  6540  6541  6557  6558  6560  6576
                                        6578  6616  6647  6704  6735  6750  6799
                                        6801  6812  6834
=SETLBERR                          Abs   22371 #00005763 -  1891
=SETMEMERR                         Abs   22383 #0000576F -  1892
=SETNONEXTERR                      Abs   78316 #000131EC -  1893
=SETPLOTENV                        Abs  259003 #0003F3BB -  1894
=SETROMPERR                        Abs   22479 #000057CF -  1895
=SETSIZEERR                        Abs   78332 #000131FC -  1896
=SETSTACKERR                       Abs   78364 #0001321C -  1897
=SETTYPEERR                        Abs   78348 #0001320C -  1898
=SEVEN                             Abs   16527 #0000408F -  1899  6592
=SEVENTEEN                         Abs   16627 #000040F3 -  1900
=SEVENTY                           Abs   17157 #00004305 -  1901
=SEVENTYEIGHT                      Abs   17237 #00004355 -  1902
=SEVENTYFIVE                       Abs   17207 #00004337 -  1903
=SEVENTYFOUR                       Abs   17197 #0000432D -  1904
=SEVENTYNINE                       Abs   17247 #0000435F -  1905
=SEVENTYONE                        Abs   17167 #0000430F -  1906
=SEVENTYSEVEN                      Abs   17227 #0000434B -  1907
=SEVENTYSIX                        Abs   17217 #00004341 -  1908
=SEVENTYTHREE                      Abs   17187 #00004323 -  1909
=SEVENTYTWO                        Abs   17177 #00004319 -  1910
=SIX                               Abs   16517 #00004085 -  1911
=SIXFIVE                           Abs   17467 #0000443B -  1912
=SIXTEEN                           Abs   16617 #000040E9 -  1913
=SIXTY                             Abs   17057 #000042A1 -  1914
=SIXTYEIGHT                        Abs   17137 #000042F1 -  1915
=SIXTYFIVE                         Abs   17107 #000042D3 -  1916
=SIXTYFOUR                         Abs   17097 #000042C9 -  1917
=SIXTYONE                          Abs   17067 #000042AB -  1918
=SIXTYSIX                          Abs   17117 #000042DD -  1919
=SIXTYTHREE                        Abs   17087 #000042BF -  1920
=SIXTYTWO                          Abs   17077 #000042B5 -  1921
=SKIP                              Abs   31014 #00007926 -  1922
=SKIPOB                            Abs   12313 #00003019 -  1923
=SLOW                              Abs  151942 #00025186 -  1924
=SPACE$                            Abs   74976 #000124E0 -  1925
=STArryList                        Abs   93268 #00016C54 -  1926
=STBigKeyDef                       Abs   97607 #00017D47 -  1927
=STDoMedium                        Abs  260101 #0003F805 -  1928
=STDoSmall                         Abs  260102 #0003F806 -  1929
=STEditKeyDef                      Abs   97688 #00017D98 -  1930
=STErrorGrob                       Abs  259893 #0003F735 -  1931
=STInitCols                        Abs  260103 #0003F807 -  1932
=STInsKeyDef                       Abs   97736 #00017DC8 -  1933
=STJump                            Abs  260104 #0003F808 -  1934
=STJumpN                           Abs  260105 #0003F809 -  1935
=STO                               Abs   34372 #00008644 -  1936
=STO'                              Abs   66037 #000101F5 -  1937
=STOLAM                            Abs   34360 #00008638 -  1938
=STO_tTYPE                         Abs  159605 #00026F75 -  1939
=STRLIST                           Abs   16987 #0000425B -  1940
=STRREALREAL                       Abs   72947 #00011CF3 -  1941
=STSortCol                         Abs  260106 #0003F80A -  1942
=STStatsKeyDef                     Abs   97782 #00017DF6 -  1943
=STTableDisp                       Abs  259894 #0003F736 -  1944
=STTableExit                       Abs  259895 #0003F737 -  1945
=STTableHKeys                      Abs  259896 #0003F738 -  1946
=STTableInit                       Abs  259897 #0003F739 -  1947
=STypeAnyChr                       Abs   68880 #00010D10 -  1948
=STypeDirChr                       Abs   68810 #00010CCA -  1949
=STypeLibChr                       Abs   68859 #00010CFB -  1950
=STypeLstChr                       Abs   68845 #00010CED -  1951
=STypeMatChr                       Abs   68852 #00010CF4 -  1952
=STypeNteChr                       Abs   68824 #00010CD8 -  1953
=STypePgmChr                       Abs   68831 #00010CDF -  1954
=STypeTgtChr                       Abs   68866 #00010D02 -  1955
=STypeVarChr                       Abs   68838 #00010CE6 -  1956
=STypeVecChr                       Abs   68873 #00010D09 -  1957
=STypeZapChr                       Abs   68817 #00010CD1 -  1958
=SUB$                              Abs   24300 #00005EEC -  1959
=SUB$1#                            Abs   82800 #00014370 -  1960
=SUB$SWAP                          Abs   63047 #0000F647 -  1961
=SUBCOMP                           Abs   24538 #00005FDA -  1962
=SUBGROB                           Abs  121274 #0001D9BA -  1963
=SV_?defined                       Abs  259700 #0003F674 -  1964
=SV_actual                         Abs  259701 #0003F675 -  1965
=SV_calledit                       Abs  259702 #0003F676 -  1966
=SV_getbody                        Abs  259703 #0003F677 -  1967
=SV_keycancel                      Abs   94015 #00016F3F -  1968
=SV_keycheck                       Abs   94055 #00016F67 -  1969
=SV_keyedit                        Abs   94075 #00016F7B -  1970
=SV_keyeval                        Abs   94108 #00016F9C -  1971
=SV_keyok                          Abs   94035 #00016F53 -  1972
=SV_keyshow                        Abs   94141 #00016FBD -  1973
=SV_setgrob19                      Abs  259707 #0003F67B -  1974
=SV_setitem0                       Abs  259708 #0003F67C -  1975
=SVarType@                         Abs  161510 #000276E6 -  1976
=SWAP                              Abs   12835 #00003223 -  1977
=SWAP#-                            Abs   58127 #0000E30F -  1978
=SWAP#1+                           Abs   58495 #0000E47F -  1979
=SWAP#1-                           Abs   65707 #000100AB -  1980
=SWAP%%/                           Abs   66617 #00010439 -  1981
=SWAP%>C%                          Abs   64401 #0000FB91 -  1982
=SWAP&$                            Abs   56986 #0000DE9A -  1983
=SWAP'                             Abs   65977 #000101B9 -  1984
=SWAP2DUP                          Abs  103179 #0001930B -  1985
=SWAP3PICK                         Abs   66767 #000104CF -  1986
=SWAP4PICK                         Abs   66807 #000104F7 -  1987
=SWAP4ROLL                         Abs   66727 #000104A7 -  1988
=SWAPCKREF                         Abs   67577 #000107F9 -  1989
=SWAPCOLA                          Abs   64506 #0000FBFA -  1990
=SWAPDROP                          Abs   52595 #0000CD73 -  1991
=SWAPDROPDUP                       Abs   58283 #0000E3AB -  1992
=SWAPDUP                           Abs   58050 #0000E2C2 -  1993
=SWAPINCOMP                        Abs   64221 #0000FADD -  1994
=SWAPINDEX@                        Abs   64797 #0000FD1D -  1995
=SWAPLOOP                          Abs   64837 #0000FD45 -  1996
=SWAPONE                           Abs   66372 #00010344 -  1997
=SWAPOVER#-                        Abs   65667 #00010083 -  1998
=SWAPROT                           Abs   52499 #0000CD13 -  1999
=SWAPStatFlag                      Abs  259899 #0003F73B -  2000
=SWAPStatFlags                     Abs  259899 #0003F73B -  2001
=SWAPUnDROP                        Abs   65917 #0001017D -  2002
=SWAPUnNDROP                       Abs   65937 #00010191 -  2003
=SWAPcompSWAP                      Abs  258732 #0003F2AC -  2004
=SYMARRY                           Abs   18097 #000046B1 -  2005
=SYMBCMP                           Abs   17917 #000045FD -  2006
=SYMBN                             Abs   23590 #00005C26 -  2007
=SYMBNUMSOLVE                      Abs  259900 #0003F73C -  2008
=SYMBREAL                          Abs   17907 #000045F3 -  2009
=SYMBSYM                           Abs   17997 #0000464D -  2010
=SYMBUNIT                          Abs   18037 #00004675 -  2011
=SYMCMP                            Abs   18077 #0000469D -  2012
=SYMCMPCMP                         Abs   73207 #00011DF7 -  2013
=SYMCMPREAL                        Abs   73197 #00011DED -  2014
=SYMCMPSYM                         Abs   73217 #00011E01 -  2015
=SYMEXT                            Abs   18197 #00004715 -  2016
=SYMID                             Abs   18117 #000046C5 -  2017
=SYMIDCMP                          Abs   73237 #00011E15 -  2018
=SYMIDEXT                          Abs   73257 #00011E29 -  2019
=SYMIDLIST                         Abs   73247 #00011E1F -  2020
=SYMIDREAL                         Abs   73227 #00011E0B -  2021
=SYMLAM                            Abs   18127 #000046CF -  2022
=SYMLIST                           Abs   18107 #000046BB -  2023
=SYMOB                             Abs   18057 #00004689 -  2024
=SYMREAL                           Abs   18067 #00004693 -  2025
=SYMREALCMP                        Abs   73177 #00011DD9 -  2026
=SYMREALREAL                       Abs   73167 #00011DCF -  2027
=SYMREALSYM                        Abs   73187 #00011DE3 -  2028
=SYMSTR                            Abs   18087 #000046A7 -  2029
=SYMSYM                            Abs   18157 #000046ED -  2030
=SYMSYMB                           Abs   18147 #000046E3 -  2031
=SYMSYMCMP                         Abs   73277 #00011E3D -  2032
=SYMSYMREAL                        Abs   73267 #00011E33 -  2033
=SYSCONTEXT                        Abs   38552 #00009698 -  2034
=SYSRRP?                           Abs   38618 #000096DA -  2035
=SafeCrunch%                       Abs  259009 #0003F3C1 -  2036
=SafeDecomp                        Abs  259010 #0003F3C2 -  2037
=SavPtrTime*                       Abs    4893 #0000131D -  5070
=SaveListMets                      Abs  259709 #0003F67D -  2038
=Sel&DispNextF                     Abs  259710 #0003F67E -  2039
=SelNextField                      Abs  259711 #0003F67F -  2040
=SelPrevField                      Abs  259712 #0003F680 -  2041
=SelectAplet                       Abs  259012 #0003F3C4 -  2042
=SeqTableViewUI                    Abs  259756 #0003F6AC -  2043
=Seq_eval0                         Abs  259560 #0003F5E8 -  2044
=Seq_eval1                         Abs  259561 #0003F5E9 -  2045
=Seq_eval2                         Abs  259562 #0003F5EA -  2046
=Seq_evaln                         Abs  259563 #0003F5EB -  2047
=SetDA12NoCh                       Abs  221983 #0003631F -  2048
=SetDA12Temp                       Abs  222108 #0003639C -  2049
=SetDA12a3NCh                      Abs  222043 #0003635B -  2050
=SetDA13NoCh                       Abs  222023 #00036347 -  2051
=SetDA1Bad                         Abs  222716 #000365FC -  2052
=SetDA1IsStat                      Abs  222884 #000366A4 -  2053
=SetDA1NoCh                        Abs  222548 #00036554 -  2054
=SetDA1Temp                        Abs  221653 #000361D5 -  2055
=SetDA1Valid                       Abs  221563 #0003617B -  2056
=SetDA23NoCh                       Abs  222003 #00036333 -  2057
=SetDA2NoCh                        Abs  221963 #0003630B -  2058
=SetDA2Temp                        Abs  222088 #00036388 -  2059
=SetDA2Valid                       Abs  221918 #000362DE -  2060
=SetDA2aBad                        Abs  222758 #00036626 -  2061
=SetDA2aEcho                       Abs  221743 #0003622F -  2062
=SetDA2aNoCh                       Abs  222590 #0003657E -  2063
=SetDA2aTemp                       Abs  221678 #000361EE -  2064
=SetDA2aValid                      Abs  221588 #00036194 -  2065
=SetDA2bBad                        Abs  222800 #00036650 -  2066
=SetDA2bNoCh                       Abs  222632 #000365A8 -  2067
=SetDA2bValid                      Abs  221608 #000361A8 -  2068
=SetDA3Bad                         Abs  222842 #0003667A -  2069
=SetDA3NoCh                        Abs  222674 #000365D2 -  2070
=SetDA3Temp                        Abs  221723 #0003621B -  2071
=SetDA3Valid                       Abs  221633 #000361C1 -  2072
=SetDA3ValidF                      Abs  222338 #00036482 -  2073
=SetDAsBad                         Abs  259013 #0003F3C5 -  2074
=SetDAsNoCh                        Abs  222063 #0003636F -  2075
=SetDAsTemp                        Abs  222128 #000363B0 -  2076
=SetEcma94                         Abs  258733 #0003F2AD -  2077
=SetFAreaBad                       Abs  259526 #0003F5C6 -  2078
=SetFAreaOK                        Abs  259014 #0003F3C6 -  2079
=SetFAreasBad                      Abs  259713 #0003F681 -  2080
=SetFAreasOK                       Abs  259714 #0003F682 -  2081
=SetInAplet                        Abs  259715 #0003F683 -  2082
=SetNoRollDA2                      Abs  222971 #000366FB -  2083
=SetRedrawFlag                     Abs  259017 #0003F3C9 -  2084
=SetSomeRow                        Abs  159329 #00026E61 -  5079
=SetSysFlag                        Abs  103335 #000193A7 -  2085
=SetUserFlag                       Abs  103323 #0001939B -  2086
=Set_window                        Abs  259716 #0003F684 -  2087
 ShowPrecBit                       Abs       0 #00000000 -  5364
 ShowPrecFl                        Abs      53 #00000035 -  5233  5363  5364
 ShowPrecNib                       Abs      13 #0000000D -  5363
=Shrink$                           Abs  104874 #000199AA -  2088
=Slope@                            Abs  160615 #00027367 -  2089
 SmallFontChooseBit                Abs       1 #00000001 -  5871
 SmallFontChooseFl                 Abs      90 #0000005A -  5869  5870  5871
 SmallFontChooseNib                Abs      22 #00000016 -  5870
 SmallFontEQWEditBit               Abs       1 #00000001 -  5847
 SmallFontEQWEditFl                Abs      82 #00000052 -  5845  5846  5847
 SmallFontEQWEditNib               Abs      20 #00000014 -  5846
 SmallFontEQWGrobBit               Abs       0 #00000000 -  5844
 SmallFontEQWGrobFl                Abs      81 #00000051 -  5842  5843  5844
 SmallFontEQWGrobNib               Abs      20 #00000014 -  5843
 SmallFontEQWStackBit              Abs       3 #00000003 -  5841
 SmallFontEQWStackFl               Abs      80 #00000050 -  5839  5840  5841
 SmallFontEQWStackNib              Abs      19 #00000013 -  5840
 SolutionsBit                      Abs       0 #00000000 -  5367
 SolutionsFl                       Abs       1 #00000001 -  5187  5366  5367
 SolutionsNib                      Abs       0 #00000000 -  5366
=SolveNumViewUI                    Abs  259758 #0003F6AE -  2090
=Split1CKSUM@                      Abs  160035 #00027123 -  2091
=Split2CKSUM                       Abs     647 #00000287 -  6233
=Split2CKSUM@                      Abs  160055 #00027137 -  2092
=SplitCKSUM                        Abs     619 #0000026B -  6225
=SplitRow                          Abs     827 #0000033B -  6299
=SplitRow@                         Abs  160215 #000271D7 -  2093
=SplitTraceInit                    Abs  194748 #0002F8BC -  2094
=Stat2Flag@                        Abs  161650 #00027772 -  2095
=StatFit@                          Abs  161850 #0002783A -  2096
=StatFont@                         Abs  161690 #0002779A -  2097
=StatMark@                         Abs  161610 #0002774A -  2098
=StatMisc[]@                       Abs  161700 #000277A4 -  2099
=StatModel@                        Abs  161630 #0002775E -  2100
=StatPlot@                         Abs  161530 #000276FA -  2101
=StatTableViewUI                   Abs  259757 #0003F6AD -  2102
=StatType!                         Abs  161485 #000276CD -  2103
=StatType@                         Abs  161490 #000276D2 -  2104
=Std/BoxLabel                      Abs  144695 #00023537 -  2105
=StdApEntry                        Abs  259567 #0003F5EF -  2106
=StdDecompNoNL                     Abs  259718 #0003F686 -  2107
=StdIOProc                         Abs  258734 #0003F2AE -  2108
=StdTableViewUI                    Abs  259717 #0003F685 -  2109
=StndXYCoord?                      Abs  259719 #0003F687 -  2110
=StoAns@                           Abs   87770 #000156DA -  2111
=StoAns@Drp                        Abs  259905 #0003F741 -  2112
=StoAplet                          Abs  259019 #0003F3CB -  2113
=StoVar                            Abs  159525 #00026F25 -  2114
=StripTicks                        Abs  259022 #0003F3CE -  2115
 SubTypeChrBase                    Abs      65 #00000041 -  5702
=SwapL/RMets                       Abs  259501 #0003F5AD -  2116
=SymbSetViewUI                     Abs  259759 #0003F6AF -  2117
=SymbViewUI                        Abs  259720 #0003F688 -  2118
=SysITE                            Abs   67432 #00010768 -  2119
 SystemRPLStackBit                 Abs       0 #00000000 -  5856
 SystemRPLStackFl                  Abs      85 #00000055 -  5854  5855  5856
 SystemRPLStackNib                 Abs      21 #00000015 -  5855
=TAGGEDANY                         Abs   18537 #00004869 -  2120
=TBColL3x5                         Abs  260111 #0003F80F -  2121
=TBColL5x7                         Abs  260112 #0003F810 -  2122
=TBColR3x5                         Abs  260113 #0003F811 -  2123
=TBColR5x7                         Abs  260114 #0003F812 -  2124
=TBDrawF3x5                        Abs  260115 #0003F813 -  2125
=TBDrawF5x7                        Abs  260116 #0003F814 -  2126
=TBEdSfKeys                        Abs  259906 #0003F742 -  2127
=TBErrorGrob                       Abs  259907 #0003F743 -  2128
=TBFormat                          Abs  259908 #0003F744 -  2129
=TBFuncDecomp                      Abs  259909 #0003F745 -  2130
=TBInv3x5C0                        Abs  259911 #0003F747 -  2131
=TBInv3x5C1                        Abs  259912 #0003F748 -  2132
=TBInv3x5C2                        Abs  259913 #0003F749 -  2133
=TBInv3x5C3                        Abs  259914 #0003F74A -  2134
=TBInv5x7C0                        Abs  260117 #0003F815 -  2135
=TBInv5x7C1                        Abs  260118 #0003F816 -  2136
=TBInv5x7C2                        Abs  260119 #0003F817 -  2137
=TBRollD3x5                        Abs  260120 #0003F818 -  2138
=TBRollD5x7                        Abs  260121 #0003F819 -  2139
=TBRollU3x5                        Abs  260122 #0003F81A -  2140
=TBRollU5x7                        Abs  260123 #0003F81B -  2141
=TBStdZooms                        Abs  259922 #0003F752 -  2142
=TBStndSplitInfo                   Abs  101661 #00018D1D -  2143
=TCol1                             Abs     810 #0000032A -  6293
=TCol1@                            Abs  160195 #000271C3 -  2144
=TDDat3x5C1                        Abs  260124 #0003F81C -  2145
=TDDat3x5C2                        Abs  260125 #0003F81D -  2146
=TDDat3x5C3                        Abs  260126 #0003F81E -  2147
=TDDat3x5C4                        Abs  260127 #0003F81F -  2148
=TDDat3x5C5                        Abs  260128 #0003F820 -  2149
=TDDatD3x5                         Abs  260129 #0003F821 -  2150
=TDDatL3x5                         Abs  260130 #0003F822 -  2151
=TDDatR3x5                         Abs  260131 #0003F823 -  2152
=TDDatU3x5                         Abs  260132 #0003F824 -  2153
=TDDataF3x5                        Abs  260133 #0003F825 -  2154
=TEN                               Abs   16557 #000040AD -  2155
=TFlags                            Abs     759 #000002F7 -  6273
=TFlags@                           Abs  160135 #00027187 -  2156
=THIRTEEN                          Abs   16587 #000040CB -  2157
=THIRTY                            Abs   16757 #00004175 -  2158
=THIRTYEIGHT                       Abs   16837 #000041C5 -  2159
=THIRTYFIVE                        Abs   16807 #000041A7 -  2160
=THIRTYFOUR                        Abs   16797 #0000419D -  2161
=THIRTYNINE                        Abs   16847 #000041CF -  2162
=THIRTYONE                         Abs   16767 #0000417F -  2163
=THIRTYSEVEN                       Abs   16827 #000041BB -  2164
=THIRTYSIX                         Abs   16817 #000041B1 -  2165
=THIRTYTHREE                       Abs   16787 #00004193 -  2166
=THIRTYTWO                         Abs   16777 #00004189 -  2167
=THREE                             Abs   16487 #00004067 -  2168
=THREEFIVE                         Abs   16987 #0000425B -  2169
=THREEFOUR                         Abs   16977 #00004251 -  2170
=THREE{}N                          Abs   64181 #0000FAB5 -  2171
=TOADISP                           Abs  128168 #0001F4A8 -  2172
=TOGDISP                           Abs  128144 #0001F490 -  2173
=TOGLINE                           Abs  259024 #0003F3D0 -  2174
=TOGLINE3                          Abs  259721 #0003F689 -  2175
=TOLErrorTrap                      Abs  220462 #00035D2E -  2176
=TOLKeyUI                          Abs  220377 #00035CD9 -  2177
=TOLResUI&Err                      Abs  220512 #00035D60 -  2178
=TOLRestoreUI                      Abs  220537 #00035D79 -  2179
=TOLSaveUI                         Abs  219992 #00035B58 -  2180
=TOLSetTopicUI                     Abs  220067 #00035BA3 -  2181
=TOLSetViewUI                      Abs  220172 #00035C0C -  2182
=TOLVar1!                          Abs   77143 #00012D57 -  2183
=TOLVar10!                         Abs   77152 #00012D60 -  2184
=TOLVar100!                        Abs   77242 #00012DBA -  2185
=TOLVar100@                        Abs   77458 #00012E92 -  2186
=TOLVar101!                        Abs   77243 #00012DBB -  2187
=TOLVar101@                        Abs   77459 #00012E93 -  2188
=TOLVar102!                        Abs   77244 #00012DBC -  2189
=TOLVar102@                        Abs   77460 #00012E94 -  2190
=TOLVar103!                        Abs   77245 #00012DBD -  2191
=TOLVar103@                        Abs   77461 #00012E95 -  2192
=TOLVar104!                        Abs   77246 #00012DBE -  2193
=TOLVar104@                        Abs   77462 #00012E96 -  2194
=TOLVar105!                        Abs   77247 #00012DBF -  2195
=TOLVar105@                        Abs   77463 #00012E97 -  2196
=TOLVar106!                        Abs   77248 #00012DC0 -  2197
=TOLVar106@                        Abs   77464 #00012E98 -  2198
=TOLVar107!                        Abs   77249 #00012DC1 -  2199
=TOLVar107@                        Abs   77465 #00012E99 -  2200
=TOLVar108!                        Abs   77250 #00012DC2 -  2201
=TOLVar108@                        Abs   77466 #00012E9A -  2202
=TOLVar109!                        Abs   77251 #00012DC3 -  2203
=TOLVar109@                        Abs   77467 #00012E9B -  2204
=TOLVar10@                         Abs   77368 #00012E38 -  2205
=TOLVar11!                         Abs   77153 #00012D61 -  2206
=TOLVar110!                        Abs   77252 #00012DC4 -  2207
=TOLVar110@                        Abs   77468 #00012E9C -  2208
=TOLVar111!                        Abs   77253 #00012DC5 -  2209
=TOLVar111@                        Abs   77469 #00012E9D -  2210
=TOLVar112!                        Abs   77254 #00012DC6 -  2211
=TOLVar112@                        Abs   77470 #00012E9E -  2212
=TOLVar113!                        Abs   77255 #00012DC7 -  2213
=TOLVar113@                        Abs   77471 #00012E9F -  2214
=TOLVar114!                        Abs   77256 #00012DC8 -  2215
=TOLVar114@                        Abs   77472 #00012EA0 -  2216
=TOLVar115!                        Abs   77257 #00012DC9 -  2217
=TOLVar115@                        Abs   77473 #00012EA1 -  2218
=TOLVar116!                        Abs   77258 #00012DCA -  2219
=TOLVar116@                        Abs   77474 #00012EA2 -  2220
=TOLVar117!                        Abs   77259 #00012DCB -  2221
=TOLVar117@                        Abs   77475 #00012EA3 -  2222
=TOLVar118!                        Abs   77260 #00012DCC -  2223
=TOLVar118@                        Abs   77476 #00012EA4 -  2224
=TOLVar119!                        Abs   77261 #00012DCD -  2225
=TOLVar119@                        Abs   77477 #00012EA5 -  2226
=TOLVar11@                         Abs   77369 #00012E39 -  2227
=TOLVar12!                         Abs   77154 #00012D62 -  2228
=TOLVar120!                        Abs   77262 #00012DCE -  2229
=TOLVar120@                        Abs   77478 #00012EA6 -  2230
=TOLVar121!                        Abs   77263 #00012DCF -  2231
=TOLVar121@                        Abs   77479 #00012EA7 -  2232
=TOLVar122!                        Abs   77264 #00012DD0 -  2233
=TOLVar122@                        Abs   77480 #00012EA8 -  2234
=TOLVar123!                        Abs   77265 #00012DD1 -  2235
=TOLVar123@                        Abs   77481 #00012EA9 -  2236
=TOLVar124!                        Abs   77266 #00012DD2 -  2237
=TOLVar124@                        Abs   77482 #00012EAA -  2238
=TOLVar125!                        Abs   77267 #00012DD3 -  2239
=TOLVar125@                        Abs   77483 #00012EAB -  2240
=TOLVar126!                        Abs   77268 #00012DD4 -  2241
=TOLVar126@                        Abs   77484 #00012EAC -  2242
=TOLVar127!                        Abs   77269 #00012DD5 -  2243
=TOLVar127@                        Abs   77485 #00012EAD -  2244
=TOLVar128!                        Abs   77270 #00012DD6 -  2245
=TOLVar128@                        Abs   77486 #00012EAE -  2246
=TOLVar129!                        Abs   77271 #00012DD7 -  2247
=TOLVar129@                        Abs   77487 #00012EAF -  2248
=TOLVar12@                         Abs   77370 #00012E3A -  2249
=TOLVar13!                         Abs   77155 #00012D63 -  2250
=TOLVar130!                        Abs   77272 #00012DD8 -  2251
=TOLVar130@                        Abs   77488 #00012EB0 -  2252
=TOLVar131!                        Abs   77273 #00012DD9 -  2253
=TOLVar131@                        Abs   77489 #00012EB1 -  2254
=TOLVar132!                        Abs   77274 #00012DDA -  2255
=TOLVar132@                        Abs   77490 #00012EB2 -  2256
=TOLVar133!                        Abs   77275 #00012DDB -  2257
=TOLVar133@                        Abs   77491 #00012EB3 -  2258
=TOLVar134!                        Abs   77276 #00012DDC -  2259
=TOLVar134@                        Abs   77492 #00012EB4 -  2260
=TOLVar135!                        Abs   77277 #00012DDD -  2261
=TOLVar135@                        Abs   77493 #00012EB5 -  2262
=TOLVar136!                        Abs   77278 #00012DDE -  2263
=TOLVar136@                        Abs   77494 #00012EB6 -  2264
=TOLVar137!                        Abs   77279 #00012DDF -  2265
=TOLVar137@                        Abs   77495 #00012EB7 -  2266
=TOLVar138!                        Abs   77280 #00012DE0 -  2267
=TOLVar138@                        Abs   77496 #00012EB8 -  2268
=TOLVar139!                        Abs   77281 #00012DE1 -  2269
=TOLVar139@                        Abs   77497 #00012EB9 -  2270
=TOLVar13@                         Abs   77371 #00012E3B -  2271
=TOLVar14!                         Abs   77156 #00012D64 -  2272
=TOLVar140!                        Abs   77282 #00012DE2 -  2273
=TOLVar140@                        Abs   77498 #00012EBA -  2274
=TOLVar141!                        Abs   77283 #00012DE3 -  2275
=TOLVar141@                        Abs   77499 #00012EBB -  2276
=TOLVar142!                        Abs   77284 #00012DE4 -  2277
=TOLVar142@                        Abs   77500 #00012EBC -  2278
=TOLVar143!                        Abs   77285 #00012DE5 -  2279
=TOLVar143@                        Abs   77501 #00012EBD -  2280
=TOLVar144!                        Abs   77286 #00012DE6 -  2281
=TOLVar144@                        Abs   77502 #00012EBE -  2282
=TOLVar145!                        Abs   77287 #00012DE7 -  2283
=TOLVar145@                        Abs   77503 #00012EBF -  2284
=TOLVar146!                        Abs   77288 #00012DE8 -  2285
=TOLVar146@                        Abs   77504 #00012EC0 -  2286
=TOLVar147!                        Abs   77289 #00012DE9 -  2287
=TOLVar147@                        Abs   77505 #00012EC1 -  2288
=TOLVar148!                        Abs   77290 #00012DEA -  2289
=TOLVar148@                        Abs   77506 #00012EC2 -  2290
=TOLVar149!                        Abs   77291 #00012DEB -  2291
=TOLVar149@                        Abs   77507 #00012EC3 -  2292
=TOLVar14@                         Abs   77372 #00012E3C -  2293
=TOLVar15!                         Abs   77157 #00012D65 -  2294
=TOLVar150!                        Abs   77292 #00012DEC -  2295
=TOLVar150@                        Abs   77508 #00012EC4 -  2296
=TOLVar151!                        Abs   77293 #00012DED -  2297
=TOLVar151@                        Abs   77509 #00012EC5 -  2298
=TOLVar152!                        Abs   77294 #00012DEE -  2299
=TOLVar152@                        Abs   77510 #00012EC6 -  2300
=TOLVar153!                        Abs   77295 #00012DEF -  2301
=TOLVar153@                        Abs   77511 #00012EC7 -  2302
=TOLVar154!                        Abs   77296 #00012DF0 -  2303
=TOLVar154@                        Abs   77512 #00012EC8 -  2304
=TOLVar155!                        Abs   77297 #00012DF1 -  2305
=TOLVar155@                        Abs   77513 #00012EC9 -  2306
=TOLVar156!                        Abs   77298 #00012DF2 -  2307
=TOLVar156@                        Abs   77514 #00012ECA -  2308
=TOLVar157!                        Abs   77299 #00012DF3 -  2309
=TOLVar157@                        Abs   77515 #00012ECB -  2310
=TOLVar158!                        Abs   77300 #00012DF4 -  2311
=TOLVar158@                        Abs   77516 #00012ECC -  2312
=TOLVar159!                        Abs   77301 #00012DF5 -  2313
=TOLVar159@                        Abs   77517 #00012ECD -  2314
=TOLVar15@                         Abs   77373 #00012E3D -  2315
=TOLVar16!                         Abs   77158 #00012D66 -  2316
=TOLVar160!                        Abs   77302 #00012DF6 -  2317
=TOLVar160@                        Abs   77518 #00012ECE -  2318
=TOLVar161!                        Abs   77303 #00012DF7 -  2319
=TOLVar161@                        Abs   77519 #00012ECF -  2320
=TOLVar162!                        Abs   77304 #00012DF8 -  2321
=TOLVar162@                        Abs   77520 #00012ED0 -  2322
=TOLVar163!                        Abs   77305 #00012DF9 -  2323
=TOLVar163@                        Abs   77521 #00012ED1 -  2324
=TOLVar164!                        Abs   77306 #00012DFA -  2325
=TOLVar164@                        Abs   77522 #00012ED2 -  2326
=TOLVar165!                        Abs   77307 #00012DFB -  2327
=TOLVar165@                        Abs   77523 #00012ED3 -  2328
=TOLVar166!                        Abs   77308 #00012DFC -  2329
=TOLVar166@                        Abs   77524 #00012ED4 -  2330
=TOLVar167!                        Abs   77309 #00012DFD -  2331
=TOLVar167@                        Abs   77525 #00012ED5 -  2332
=TOLVar168!                        Abs   77310 #00012DFE -  2333
=TOLVar168@                        Abs   77526 #00012ED6 -  2334
=TOLVar169!                        Abs   77311 #00012DFF -  2335
=TOLVar169@                        Abs   77527 #00012ED7 -  2336
=TOLVar16@                         Abs   77374 #00012E3E -  2337
=TOLVar17!                         Abs   77159 #00012D67 -  2338
=TOLVar170!                        Abs   77312 #00012E00 -  2339
=TOLVar170@                        Abs   77528 #00012ED8 -  2340
=TOLVar171!                        Abs   77313 #00012E01 -  2341
=TOLVar171@                        Abs   77529 #00012ED9 -  2342
=TOLVar172!                        Abs   77314 #00012E02 -  2343
=TOLVar172@                        Abs   77530 #00012EDA -  2344
=TOLVar173!                        Abs   77315 #00012E03 -  2345
=TOLVar173@                        Abs   77531 #00012EDB -  2346
=TOLVar174!                        Abs   77316 #00012E04 -  2347
=TOLVar174@                        Abs   77532 #00012EDC -  2348
=TOLVar175!                        Abs   77317 #00012E05 -  2349
=TOLVar175@                        Abs   77533 #00012EDD -  2350
=TOLVar176!                        Abs   77318 #00012E06 -  2351
=TOLVar176@                        Abs   77534 #00012EDE -  2352
=TOLVar177!                        Abs   77319 #00012E07 -  2353
=TOLVar177@                        Abs   77535 #00012EDF -  2354
=TOLVar178!                        Abs   77320 #00012E08 -  2355
=TOLVar178@                        Abs   77536 #00012EE0 -  2356
=TOLVar179!                        Abs   77321 #00012E09 -  2357
=TOLVar179@                        Abs   77537 #00012EE1 -  2358
=TOLVar17@                         Abs   77375 #00012E3F -  2359
=TOLVar18!                         Abs   77160 #00012D68 -  2360
=TOLVar180!                        Abs   77322 #00012E0A -  2361
=TOLVar180@                        Abs   77538 #00012EE2 -  2362
=TOLVar181!                        Abs   77323 #00012E0B -  2363
=TOLVar181@                        Abs   77539 #00012EE3 -  2364
=TOLVar182!                        Abs   77324 #00012E0C -  2365
=TOLVar182@                        Abs   77540 #00012EE4 -  2366
=TOLVar183!                        Abs   77325 #00012E0D -  2367
=TOLVar183@                        Abs   77541 #00012EE5 -  2368
=TOLVar184!                        Abs   77326 #00012E0E -  2369
=TOLVar184@                        Abs   77542 #00012EE6 -  2370
=TOLVar185!                        Abs   77327 #00012E0F -  2371
=TOLVar185@                        Abs   77543 #00012EE7 -  2372
=TOLVar186!                        Abs   77328 #00012E10 -  2373
=TOLVar186@                        Abs   77544 #00012EE8 -  2374
=TOLVar187!                        Abs   77329 #00012E11 -  2375
=TOLVar187@                        Abs   77545 #00012EE9 -  2376
=TOLVar188!                        Abs   77330 #00012E12 -  2377
=TOLVar188@                        Abs   77546 #00012EEA -  2378
=TOLVar189!                        Abs   77331 #00012E13 -  2379
=TOLVar189@                        Abs   77547 #00012EEB -  2380
=TOLVar18@                         Abs   77376 #00012E40 -  2381
=TOLVar19!                         Abs   77161 #00012D69 -  2382
=TOLVar190!                        Abs   77332 #00012E14 -  2383
=TOLVar190@                        Abs   77548 #00012EEC -  2384
=TOLVar191!                        Abs   77333 #00012E15 -  2385
=TOLVar191@                        Abs   77549 #00012EED -  2386
=TOLVar192!                        Abs   77334 #00012E16 -  2387
=TOLVar192@                        Abs   77550 #00012EEE -  2388
=TOLVar193!                        Abs   77335 #00012E17 -  2389
=TOLVar193@                        Abs   77551 #00012EEF -  2390
=TOLVar194!                        Abs   77336 #00012E18 -  2391
=TOLVar194@                        Abs   77552 #00012EF0 -  2392
=TOLVar195!                        Abs   77337 #00012E19 -  2393
=TOLVar195@                        Abs   77553 #00012EF1 -  2394
=TOLVar196!                        Abs   77338 #00012E1A -  2395
=TOLVar196@                        Abs   77554 #00012EF2 -  2396
=TOLVar197!                        Abs   77339 #00012E1B -  2397
=TOLVar197@                        Abs   77555 #00012EF3 -  2398
=TOLVar198!                        Abs   77340 #00012E1C -  2399
=TOLVar198@                        Abs   77556 #00012EF4 -  2400
=TOLVar199!                        Abs   77341 #00012E1D -  2401
=TOLVar199@                        Abs   77557 #00012EF5 -  2402
=TOLVar19@                         Abs   77377 #00012E41 -  2403
=TOLVar1@                          Abs   77359 #00012E2F -  2404
=TOLVar2!                          Abs   77144 #00012D58 -  2405
=TOLVar20!                         Abs   77162 #00012D6A -  2406
=TOLVar200!                        Abs   77342 #00012E1E -  2407
=TOLVar200@                        Abs   77558 #00012EF6 -  2408
=TOLVar201!                        Abs   77343 #00012E1F -  2409
=TOLVar201@                        Abs   77559 #00012EF7 -  2410
=TOLVar202!                        Abs   77344 #00012E20 -  2411
=TOLVar202@                        Abs   77560 #00012EF8 -  2412
=TOLVar203!                        Abs   77345 #00012E21 -  2413
=TOLVar203@                        Abs   77561 #00012EF9 -  2414
=TOLVar204!                        Abs   77346 #00012E22 -  2415
=TOLVar204@                        Abs   77562 #00012EFA -  2416
=TOLVar205!                        Abs   77347 #00012E23 -  2417
=TOLVar205@                        Abs   77563 #00012EFB -  2418
=TOLVar206!                        Abs   77348 #00012E24 -  2419
=TOLVar206@                        Abs   77564 #00012EFC -  2420
=TOLVar207!                        Abs   77349 #00012E25 -  2421
=TOLVar207@                        Abs   77565 #00012EFD -  2422
=TOLVar208!                        Abs   77350 #00012E26 -  2423
=TOLVar208@                        Abs   77566 #00012EFE -  2424
=TOLVar209!                        Abs   77351 #00012E27 -  2425
=TOLVar209@                        Abs   77567 #00012EFF -  2426
=TOLVar20@                         Abs   77378 #00012E42 -  2427
=TOLVar21!                         Abs   77163 #00012D6B -  2428
=TOLVar210!                        Abs   77352 #00012E28 -  2429
=TOLVar210@                        Abs   77568 #00012F00 -  2430
=TOLVar211!                        Abs   77353 #00012E29 -  2431
=TOLVar211@                        Abs   77569 #00012F01 -  2432
=TOLVar212!                        Abs   77354 #00012E2A -  2433
=TOLVar212@                        Abs   77570 #00012F02 -  2434
=TOLVar213!                        Abs   77355 #00012E2B -  2435
=TOLVar213@                        Abs   77571 #00012F03 -  2436
=TOLVar214!                        Abs   77356 #00012E2C -  2437
=TOLVar214@                        Abs   77572 #00012F04 -  2438
=TOLVar215!                        Abs   77357 #00012E2D -  2439
=TOLVar215@                        Abs   77573 #00012F05 -  2440
=TOLVar216!                        Abs   77358 #00012E2E -  2441
=TOLVar216@                        Abs   77574 #00012F06 -  2442
=TOLVar21@                         Abs   77379 #00012E43 -  2443
=TOLVar22!                         Abs   77164 #00012D6C -  2444
=TOLVar22@                         Abs   77380 #00012E44 -  2445
=TOLVar23!                         Abs   77165 #00012D6D -  2446
=TOLVar23@                         Abs   77381 #00012E45 -  2447
=TOLVar24!                         Abs   77166 #00012D6E -  2448
=TOLVar24@                         Abs   77382 #00012E46 -  2449
=TOLVar25!                         Abs   77167 #00012D6F -  2450
=TOLVar25@                         Abs   77383 #00012E47 -  2451
=TOLVar26!                         Abs   77168 #00012D70 -  2452
=TOLVar26@                         Abs   77384 #00012E48 -  2453
=TOLVar27!                         Abs   77169 #00012D71 -  2454
=TOLVar27@                         Abs   77385 #00012E49 -  2455
=TOLVar28!                         Abs   77170 #00012D72 -  2456
=TOLVar28@                         Abs   77386 #00012E4A -  2457
=TOLVar29!                         Abs   77171 #00012D73 -  2458
=TOLVar29@                         Abs   77387 #00012E4B -  2459
=TOLVar2@                          Abs   77360 #00012E30 -  2460
=TOLVar3!                          Abs   77145 #00012D59 -  2461
=TOLVar30!                         Abs   77172 #00012D74 -  2462
=TOLVar30@                         Abs   77388 #00012E4C -  2463
=TOLVar31!                         Abs   77173 #00012D75 -  2464
=TOLVar31@                         Abs   77389 #00012E4D -  2465
=TOLVar32!                         Abs   77174 #00012D76 -  2466
=TOLVar32@                         Abs   77390 #00012E4E -  2467
=TOLVar33!                         Abs   77175 #00012D77 -  2468
=TOLVar33@                         Abs   77391 #00012E4F -  2469
=TOLVar34!                         Abs   77176 #00012D78 -  2470
=TOLVar34@                         Abs   77392 #00012E50 -  2471
=TOLVar35!                         Abs   77177 #00012D79 -  2472
=TOLVar35@                         Abs   77393 #00012E51 -  2473
=TOLVar36!                         Abs   77178 #00012D7A -  2474
=TOLVar36@                         Abs   77394 #00012E52 -  2475
=TOLVar37!                         Abs   77179 #00012D7B -  2476
=TOLVar37@                         Abs   77395 #00012E53 -  2477
=TOLVar38!                         Abs   77180 #00012D7C -  2478
=TOLVar38@                         Abs   77396 #00012E54 -  2479
=TOLVar39!                         Abs   77181 #00012D7D -  2480
=TOLVar39@                         Abs   77397 #00012E55 -  2481
=TOLVar3@                          Abs   77361 #00012E31 -  2482
=TOLVar4!                          Abs   77146 #00012D5A -  2483
=TOLVar40!                         Abs   77182 #00012D7E -  2484
=TOLVar40@                         Abs   77398 #00012E56 -  2485
=TOLVar41!                         Abs   77183 #00012D7F -  2486
=TOLVar41@                         Abs   77399 #00012E57 -  2487
=TOLVar42!                         Abs   77184 #00012D80 -  2488
=TOLVar42@                         Abs   77400 #00012E58 -  2489
=TOLVar43!                         Abs   77185 #00012D81 -  2490
=TOLVar43@                         Abs   77401 #00012E59 -  2491
=TOLVar44!                         Abs   77186 #00012D82 -  2492
=TOLVar44@                         Abs   77402 #00012E5A -  2493
=TOLVar45!                         Abs   77187 #00012D83 -  2494
=TOLVar45@                         Abs   77403 #00012E5B -  2495
=TOLVar46!                         Abs   77188 #00012D84 -  2496
=TOLVar46@                         Abs   77404 #00012E5C -  2497
=TOLVar47!                         Abs   77189 #00012D85 -  2498
=TOLVar47@                         Abs   77405 #00012E5D -  2499
=TOLVar48!                         Abs   77190 #00012D86 -  2500
=TOLVar48@                         Abs   77406 #00012E5E -  2501
=TOLVar49!                         Abs   77191 #00012D87 -  2502
=TOLVar49@                         Abs   77407 #00012E5F -  2503
=TOLVar4@                          Abs   77362 #00012E32 -  2504
=TOLVar5!                          Abs   77147 #00012D5B -  2505
=TOLVar50!                         Abs   77192 #00012D88 -  2506
=TOLVar50@                         Abs   77408 #00012E60 -  2507
=TOLVar51!                         Abs   77193 #00012D89 -  2508
=TOLVar51@                         Abs   77409 #00012E61 -  2509
=TOLVar52!                         Abs   77194 #00012D8A -  2510
=TOLVar52@                         Abs   77410 #00012E62 -  2511
=TOLVar53!                         Abs   77195 #00012D8B -  2512
=TOLVar53@                         Abs   77411 #00012E63 -  2513
=TOLVar54!                         Abs   77196 #00012D8C -  2514
=TOLVar54@                         Abs   77412 #00012E64 -  2515
=TOLVar55!                         Abs   77197 #00012D8D -  2516
=TOLVar55@                         Abs   77413 #00012E65 -  2517
=TOLVar56!                         Abs   77198 #00012D8E -  2518
=TOLVar56@                         Abs   77414 #00012E66 -  2519
=TOLVar57!                         Abs   77199 #00012D8F -  2520
=TOLVar57@                         Abs   77415 #00012E67 -  2521
=TOLVar58!                         Abs   77200 #00012D90 -  2522
=TOLVar58@                         Abs   77416 #00012E68 -  2523
=TOLVar59!                         Abs   77201 #00012D91 -  2524
=TOLVar59@                         Abs   77417 #00012E69 -  2525
=TOLVar5@                          Abs   77363 #00012E33 -  2526
=TOLVar6!                          Abs   77148 #00012D5C -  2527
=TOLVar60!                         Abs   77202 #00012D92 -  2528
=TOLVar60@                         Abs   77418 #00012E6A -  2529
=TOLVar61!                         Abs   77203 #00012D93 -  2530
=TOLVar61@                         Abs   77419 #00012E6B -  2531
=TOLVar62!                         Abs   77204 #00012D94 -  2532
=TOLVar62@                         Abs   77420 #00012E6C -  2533
=TOLVar63!                         Abs   77205 #00012D95 -  2534
=TOLVar63@                         Abs   77421 #00012E6D -  2535
=TOLVar64!                         Abs   77206 #00012D96 -  2536
=TOLVar64@                         Abs   77422 #00012E6E -  2537
=TOLVar65!                         Abs   77207 #00012D97 -  2538
=TOLVar65@                         Abs   77423 #00012E6F -  2539
=TOLVar66!                         Abs   77208 #00012D98 -  2540
=TOLVar66@                         Abs   77424 #00012E70 -  2541
=TOLVar67!                         Abs   77209 #00012D99 -  2542
=TOLVar67@                         Abs   77425 #00012E71 -  2543
=TOLVar68!                         Abs   77210 #00012D9A -  2544
=TOLVar68@                         Abs   77426 #00012E72 -  2545
=TOLVar69!                         Abs   77211 #00012D9B -  2546
=TOLVar69@                         Abs   77427 #00012E73 -  2547
=TOLVar6@                          Abs   77364 #00012E34 -  2548
=TOLVar7!                          Abs   77149 #00012D5D -  2549
=TOLVar70!                         Abs   77212 #00012D9C -  2550
=TOLVar70@                         Abs   77428 #00012E74 -  2551
=TOLVar71!                         Abs   77213 #00012D9D -  2552
=TOLVar71@                         Abs   77429 #00012E75 -  2553
=TOLVar72!                         Abs   77214 #00012D9E -  2554
=TOLVar72@                         Abs   77430 #00012E76 -  2555
=TOLVar73!                         Abs   77215 #00012D9F -  2556
=TOLVar73@                         Abs   77431 #00012E77 -  2557
=TOLVar74!                         Abs   77216 #00012DA0 -  2558
=TOLVar74@                         Abs   77432 #00012E78 -  2559
=TOLVar75!                         Abs   77217 #00012DA1 -  2560
=TOLVar75@                         Abs   77433 #00012E79 -  2561
=TOLVar76!                         Abs   77218 #00012DA2 -  2562
=TOLVar76@                         Abs   77434 #00012E7A -  2563
=TOLVar77!                         Abs   77219 #00012DA3 -  2564
=TOLVar77@                         Abs   77435 #00012E7B -  2565
=TOLVar78!                         Abs   77220 #00012DA4 -  2566
=TOLVar78@                         Abs   77436 #00012E7C -  2567
=TOLVar79!                         Abs   77221 #00012DA5 -  2568
=TOLVar79@                         Abs   77437 #00012E7D -  2569
=TOLVar7@                          Abs   77365 #00012E35 -  2570
=TOLVar8!                          Abs   77150 #00012D5E -  2571
=TOLVar80!                         Abs   77222 #00012DA6 -  2572
=TOLVar80@                         Abs   77438 #00012E7E -  2573
=TOLVar81!                         Abs   77223 #00012DA7 -  2574
=TOLVar81@                         Abs   77439 #00012E7F -  2575
=TOLVar82!                         Abs   77224 #00012DA8 -  2576
=TOLVar82@                         Abs   77440 #00012E80 -  2577
=TOLVar83!                         Abs   77225 #00012DA9 -  2578
=TOLVar83@                         Abs   77441 #00012E81 -  2579
=TOLVar84!                         Abs   77226 #00012DAA -  2580
=TOLVar84@                         Abs   77442 #00012E82 -  2581
=TOLVar85!                         Abs   77227 #00012DAB -  2582
=TOLVar85@                         Abs   77443 #00012E83 -  2583
=TOLVar86!                         Abs   77228 #00012DAC -  2584
=TOLVar86@                         Abs   77444 #00012E84 -  2585
=TOLVar87!                         Abs   77229 #00012DAD -  2586
=TOLVar87@                         Abs   77445 #00012E85 -  2587
=TOLVar88!                         Abs   77230 #00012DAE -  2588
=TOLVar88@                         Abs   77446 #00012E86 -  2589
=TOLVar89!                         Abs   77231 #00012DAF -  2590
=TOLVar89@                         Abs   77447 #00012E87 -  2591
=TOLVar8@                          Abs   77366 #00012E36 -  2592
=TOLVar9!                          Abs   77151 #00012D5F -  2593
=TOLVar90!                         Abs   77232 #00012DB0 -  2594
=TOLVar90@                         Abs   77448 #00012E88 -  2595
=TOLVar91!                         Abs   77233 #00012DB1 -  2596
=TOLVar91@                         Abs   77449 #00012E89 -  2597
=TOLVar92!                         Abs   77234 #00012DB2 -  2598
=TOLVar92@                         Abs   77450 #00012E8A -  2599
=TOLVar93!                         Abs   77235 #00012DB3 -  2600
=TOLVar93@                         Abs   77451 #00012E8B -  2601
=TOLVar94!                         Abs   77236 #00012DB4 -  2602
=TOLVar94@                         Abs   77452 #00012E8C -  2603
=TOLVar95!                         Abs   77237 #00012DB5 -  2604
=TOLVar95@                         Abs   77453 #00012E8D -  2605
=TOLVar96!                         Abs   77238 #00012DB6 -  2606
=TOLVar96@                         Abs   77454 #00012E8E -  2607
=TOLVar97!                         Abs   77239 #00012DB7 -  2608
=TOLVar97@                         Abs   77455 #00012E8F -  2609
=TOLVar98!                         Abs   77240 #00012DB8 -  2610
=TOLVar98@                         Abs   77456 #00012E90 -  2611
=TOLVar99!                         Abs   77241 #00012DB9 -  2612
=TOLVar99@                         Abs   77457 #00012E91 -  2613
=TOLVar9@                          Abs   77367 #00012E37 -  2614
=TOLVarN!                          Abs   75805 #0001281D -  2615
=TOLVarN@                          Abs   75840 #00012840 -  2616
=TOLVarSet!                        Abs   76075 #0001292B -  2617
=TOSRRP                            Abs   32482 #00007EE2 -  2618
=TOTEMPOB                          Abs   28207 #00006E2F -  2619
=TOTEMPSWAP                        Abs   62787 #0000F543 -  2620
=TRCXY                             Abs  115806 #0001C45E -  2621
=TRUE                              Abs   14977 #00003A81 -  2622  6521
=TRUE'                             Abs   66057 #00010209 -  2623
=TRUEFALSE                         Abs   65007 #0000FDEF -  2624
=TStart                            Abs     675 #000002A3 -  6241
=TStart@                           Abs  160075 #0002714B -  2625
=TStep                             Abs     703 #000002BF -  6251
=TStep@                            Abs  160095 #0002715F -  2626
=TURNMENUOFF                       Abs  259029 #0003F3D5 -  2627
=TURNMENUON                        Abs  259030 #0003F3D6 -  2628  6573
=TWELVE                            Abs   16577 #000040C1 -  2629
=TWENTY                            Abs   16657 #00004111 -  2630
=TWENTYEIGHT                       Abs   16737 #00004161 -  2631
=TWENTYFIVE                        Abs   16707 #00004143 -  2632
=TWENTYFOUR                        Abs   16697 #00004139 -  2633
=TWENTYNINE                        Abs   16747 #0000416B -  2634
=TWENTYONE                         Abs   16667 #0000411B -  2635
=TWENTYSEVEN                       Abs   16727 #00004157 -  2636
=TWENTYSIX                         Abs   16717 #0000414D -  2637
=TWENTYTHREE                       Abs   16687 #0000412F -  2638
=TWENTYTWO                         Abs   16677 #00004125 -  2639
=TWO                               Abs   16477 #0000405D -  2640
=TWODROPNULL$                      Abs   21865 #00005569 -  2641
=TWO{}N                            Abs   64161 #0000FAA1 -  2642
=TYPE                              Abs   15460 #00003C64 -  2643
=TYPEARRY?                         Abs   56463 #0000DC8F -  2644
=TYPEBINT?                         Abs   56388 #0000DC44 -  2645
=TYPECARRY?                        Abs   56833 #0000DE01 -  2646
=TYPECHAR?                         Abs   56223 #0000DB9F -  2647
=TYPECMP                           Abs   16357 #00003FE5 -  2648
=TYPECMP?                          Abs   56448 #0000DC80 -  2649
=TYPECOL                           Abs   16387 #00004003 -  2650
=TYPECOL?                          Abs   56523 #0000DCCB -  2651
=TYPECSTR?                         Abs   56418 #0000DC62 -  2652
=TYPEEREL                          Abs   16427 #0000402B -  2653
=TYPEEXT                           Abs   16437 #00004035 -  2654
=TYPEEXT?                          Abs   56583 #0000DD07 -  2655
=TYPEGROB?                         Abs   56538 #0000DCDA -  2656
=TYPEHSTR?                         Abs   56403 #0000DC53 -  2657
=TYPEIDNT                          Abs   16377 #00003FF9 -  2658
=TYPEIDNT?                         Abs   56238 #0000DBAE -  2659
=TYPELAM                           Abs   16417 #00004021 -  2660
=TYPELAM?                          Abs   56373 #0000DC35 -  2661
=TYPELIST                          Abs   16367 #00003FEF -  2662
=TYPELIST?                         Abs   56553 #0000DCE9 -  2663
=TYPERARRY?                        Abs   56806 #0000DDE6 -  2664
=TYPEREAL                          Abs   16347 #00003FDB -  2665
=TYPEREAL?                         Abs   56433 #0000DC71 -  2666
=TYPEROMP?                         Abs   56478 #0000DC9E -  2667
=TYPERRP                           Abs   16407 #00004017 -  2668
=TYPERRP?                          Abs   56493 #0000DCAD -  2669
=TYPESYMB                          Abs   16397 #0000400D -  2670
=TYPESYMB?                         Abs   56508 #0000DCBC -  2671
=TZoom                             Abs     731 #000002DB -  6261
=TZoom@                            Abs  160115 #00027173 -  2672
=TablSetViewUI                     Abs  259722 #0003F68A -  2673
=TakeOver                          Abs  148552 #00024448 -  2674  6496  6533
                                        6555
=Tcol                              Abs     793 #00000319 -  6287
=Tcol@                             Abs  160175 #000271AF -  2675
=TempMenuBuff                      Abs  259723 #0003F68B -  2676
=TestSysFlag                       Abs  103418 #000193FA -  2677
=TestUserFlag                      Abs  103406 #000193EE -  2678
=TopOuterLoop                      Abs  219759 #00035A6F -  2679
=TopicVar1!                        Abs   76961 #00012CA1 -  2680  6595  6693
=TopicVar10!                       Abs   76970 #00012CAA -  2681
=TopicVar10@                       Abs   77061 #00012D05 -  2682
=TopicVar11!                       Abs   76971 #00012CAB -  2683
=TopicVar11@                       Abs   77062 #00012D06 -  2684
=TopicVar12!                       Abs   76972 #00012CAC -  2685
=TopicVar12@                       Abs   77063 #00012D07 -  2686
=TopicVar13!                       Abs   76973 #00012CAD -  2687
=TopicVar13@                       Abs   77064 #00012D08 -  2688
=TopicVar14!                       Abs   76974 #00012CAE -  2689
=TopicVar14@                       Abs   77065 #00012D09 -  2690
=TopicVar15!                       Abs   76975 #00012CAF -  2691
=TopicVar15@                       Abs   77066 #00012D0A -  2692
=TopicVar16!                       Abs   76976 #00012CB0 -  2693
=TopicVar16@                       Abs   77067 #00012D0B -  2694
=TopicVar17!                       Abs   76977 #00012CB1 -  2695
=TopicVar17@                       Abs   77068 #00012D0C -  2696
=TopicVar18!                       Abs   76978 #00012CB2 -  2697
=TopicVar18@                       Abs   77069 #00012D0D -  2698
=TopicVar19!                       Abs   76979 #00012CB3 -  2699
=TopicVar19@                       Abs   77070 #00012D0E -  2700
=TopicVar1@                        Abs   77052 #00012CFC -  2701  6633  6678
=TopicVar2!                        Abs   76962 #00012CA2 -  2702  6446
=TopicVar20!                       Abs   76980 #00012CB4 -  2703
=TopicVar20@                       Abs   77071 #00012D0F -  2704
=TopicVar21!                       Abs   76981 #00012CB5 -  2705
=TopicVar21@                       Abs   77072 #00012D10 -  2706
=TopicVar22!                       Abs   76982 #00012CB6 -  2707
=TopicVar22@                       Abs   77073 #00012D11 -  2708
=TopicVar23!                       Abs   76983 #00012CB7 -  2709
=TopicVar23@                       Abs   77074 #00012D12 -  2710
=TopicVar24!                       Abs   76984 #00012CB8 -  2711
=TopicVar24@                       Abs   77075 #00012D13 -  2712
=TopicVar25!                       Abs   76985 #00012CB9 -  2713
=TopicVar25@                       Abs   77076 #00012D14 -  2714
=TopicVar26!                       Abs   76986 #00012CBA -  2715
=TopicVar26@                       Abs   77077 #00012D15 -  2716
=TopicVar27!                       Abs   76987 #00012CBB -  2717
=TopicVar27@                       Abs   77078 #00012D16 -  2718
=TopicVar28!                       Abs   76988 #00012CBC -  2719
=TopicVar28@                       Abs   77079 #00012D17 -  2720
=TopicVar29!                       Abs   76989 #00012CBD -  2721
=TopicVar29@                       Abs   77080 #00012D18 -  2722
=TopicVar2@                        Abs   77053 #00012CFD -  2723  6671
=TopicVar3!                        Abs   76963 #00012CA3 -  2724
=TopicVar30!                       Abs   76990 #00012CBE -  2725
=TopicVar30@                       Abs   77081 #00012D19 -  2726
=TopicVar31!                       Abs   76991 #00012CBF -  2727
=TopicVar31@                       Abs   77082 #00012D1A -  2728
=TopicVar32!                       Abs   76992 #00012CC0 -  2729
=TopicVar32@                       Abs   77083 #00012D1B -  2730
=TopicVar33!                       Abs   76993 #00012CC1 -  2731
=TopicVar33@                       Abs   77084 #00012D1C -  2732
=TopicVar34!                       Abs   76994 #00012CC2 -  2733
=TopicVar34@                       Abs   77085 #00012D1D -  2734
=TopicVar35!                       Abs   76995 #00012CC3 -  2735
=TopicVar35@                       Abs   77086 #00012D1E -  2736
=TopicVar36!                       Abs   76996 #00012CC4 -  2737
=TopicVar36@                       Abs   77087 #00012D1F -  2738
=TopicVar37!                       Abs   76997 #00012CC5 -  2739
=TopicVar37@                       Abs   77088 #00012D20 -  2740
=TopicVar38!                       Abs   76998 #00012CC6 -  2741
=TopicVar38@                       Abs   77089 #00012D21 -  2742
=TopicVar39!                       Abs   76999 #00012CC7 -  2743
=TopicVar39@                       Abs   77090 #00012D22 -  2744
=TopicVar3@                        Abs   77054 #00012CFE -  2745
=TopicVar4!                        Abs   76964 #00012CA4 -  2746
=TopicVar40!                       Abs   77000 #00012CC8 -  2747
=TopicVar40@                       Abs   77091 #00012D23 -  2748
=TopicVar41!                       Abs   77001 #00012CC9 -  2749
=TopicVar41@                       Abs   77092 #00012D24 -  2750
=TopicVar42!                       Abs   77002 #00012CCA -  2751
=TopicVar42@                       Abs   77093 #00012D25 -  2752
=TopicVar43!                       Abs   77003 #00012CCB -  2753
=TopicVar43@                       Abs   77094 #00012D26 -  2754
=TopicVar44!                       Abs   77004 #00012CCC -  2755
=TopicVar44@                       Abs   77095 #00012D27 -  2756
=TopicVar45!                       Abs   77005 #00012CCD -  2757
=TopicVar45@                       Abs   77096 #00012D28 -  2758
=TopicVar46!                       Abs   77006 #00012CCE -  2759
=TopicVar46@                       Abs   77097 #00012D29 -  2760
=TopicVar47!                       Abs   77007 #00012CCF -  2761
=TopicVar47@                       Abs   77098 #00012D2A -  2762
=TopicVar48!                       Abs   77008 #00012CD0 -  2763
=TopicVar48@                       Abs   77099 #00012D2B -  2764
=TopicVar49!                       Abs   77009 #00012CD1 -  2765
=TopicVar49@                       Abs   77100 #00012D2C -  2766
=TopicVar4@                        Abs   77055 #00012CFF -  2767
=TopicVar5!                        Abs   76965 #00012CA5 -  2768
=TopicVar50!                       Abs   77010 #00012CD2 -  2769
=TopicVar50@                       Abs   77101 #00012D2D -  2770
=TopicVar51!                       Abs   77011 #00012CD3 -  2771
=TopicVar51@                       Abs   77102 #00012D2E -  2772
=TopicVar52!                       Abs   77012 #00012CD4 -  2773
=TopicVar52@                       Abs   77103 #00012D2F -  2774
=TopicVar53!                       Abs   77013 #00012CD5 -  2775
=TopicVar53@                       Abs   77104 #00012D30 -  2776
=TopicVar54!                       Abs   77014 #00012CD6 -  2777
=TopicVar54@                       Abs   77105 #00012D31 -  2778
=TopicVar55!                       Abs   77015 #00012CD7 -  2779
=TopicVar55@                       Abs   77106 #00012D32 -  2780
=TopicVar56!                       Abs   77016 #00012CD8 -  2781
=TopicVar56@                       Abs   77107 #00012D33 -  2782
=TopicVar57!                       Abs   77017 #00012CD9 -  2783
=TopicVar57@                       Abs   77108 #00012D34 -  2784
=TopicVar58!                       Abs   77018 #00012CDA -  2785
=TopicVar58@                       Abs   77109 #00012D35 -  2786
=TopicVar59!                       Abs   77019 #00012CDB -  2787
=TopicVar59@                       Abs   77110 #00012D36 -  2788
=TopicVar5@                        Abs   77056 #00012D00 -  2789
=TopicVar6!                        Abs   76966 #00012CA6 -  2790
=TopicVar60!                       Abs   77020 #00012CDC -  2791
=TopicVar60@                       Abs   77111 #00012D37 -  2792
=TopicVar61!                       Abs   77021 #00012CDD -  2793
=TopicVar61@                       Abs   77112 #00012D38 -  2794
=TopicVar62!                       Abs   77022 #00012CDE -  2795
=TopicVar62@                       Abs   77113 #00012D39 -  2796
=TopicVar63!                       Abs   77023 #00012CDF -  2797
=TopicVar63@                       Abs   77114 #00012D3A -  2798
=TopicVar64!                       Abs   77024 #00012CE0 -  2799
=TopicVar64@                       Abs   77115 #00012D3B -  2800
=TopicVar65!                       Abs   77025 #00012CE1 -  2801
=TopicVar65@                       Abs   77116 #00012D3C -  2802
=TopicVar66!                       Abs   77026 #00012CE2 -  2803
=TopicVar66@                       Abs   77117 #00012D3D -  2804
=TopicVar67!                       Abs   77027 #00012CE3 -  2805
=TopicVar67@                       Abs   77118 #00012D3E -  2806
=TopicVar68!                       Abs   77028 #00012CE4 -  2807
=TopicVar68@                       Abs   77119 #00012D3F -  2808
=TopicVar69!                       Abs   77029 #00012CE5 -  2809
=TopicVar69@                       Abs   77120 #00012D40 -  2810
=TopicVar6@                        Abs   77057 #00012D01 -  2811
=TopicVar7!                        Abs   76967 #00012CA7 -  2812
=TopicVar70!                       Abs   77030 #00012CE6 -  2813
=TopicVar70@                       Abs   77121 #00012D41 -  2814
=TopicVar71!                       Abs   77031 #00012CE7 -  2815
=TopicVar71@                       Abs   77122 #00012D42 -  2816
=TopicVar72!                       Abs   77032 #00012CE8 -  2817
=TopicVar72@                       Abs   77123 #00012D43 -  2818
=TopicVar73!                       Abs   77033 #00012CE9 -  2819
=TopicVar73@                       Abs   77124 #00012D44 -  2820
=TopicVar74!                       Abs   77034 #00012CEA -  2821
=TopicVar74@                       Abs   77125 #00012D45 -  2822
=TopicVar75!                       Abs   77035 #00012CEB -  2823
=TopicVar75@                       Abs   77126 #00012D46 -  2824
=TopicVar76!                       Abs   77036 #00012CEC -  2825
=TopicVar76@                       Abs   77127 #00012D47 -  2826
=TopicVar77!                       Abs   77037 #00012CED -  2827
=TopicVar77@                       Abs   77128 #00012D48 -  2828
=TopicVar78!                       Abs   77038 #00012CEE -  2829
=TopicVar78@                       Abs   77129 #00012D49 -  2830
=TopicVar79!                       Abs   77039 #00012CEF -  2831
=TopicVar79@                       Abs   77130 #00012D4A -  2832
=TopicVar7@                        Abs   77058 #00012D02 -  2833
=TopicVar8!                        Abs   76968 #00012CA8 -  2834
=TopicVar80!                       Abs   77040 #00012CF0 -  2835
=TopicVar80@                       Abs   77131 #00012D4B -  2836
=TopicVar81!                       Abs   77041 #00012CF1 -  2837
=TopicVar81@                       Abs   77132 #00012D4C -  2838
=TopicVar82!                       Abs   77042 #00012CF2 -  2839
=TopicVar82@                       Abs   77133 #00012D4D -  2840
=TopicVar83!                       Abs   77043 #00012CF3 -  2841
=TopicVar83@                       Abs   77134 #00012D4E -  2842
=TopicVar84!                       Abs   77044 #00012CF4 -  2843
=TopicVar84@                       Abs   77135 #00012D4F -  2844
=TopicVar85!                       Abs   77045 #00012CF5 -  2845
=TopicVar85@                       Abs   77136 #00012D50 -  2846
=TopicVar86!                       Abs   77046 #00012CF6 -  2847
=TopicVar86@                       Abs   77137 #00012D51 -  2848
=TopicVar87!                       Abs   77047 #00012CF7 -  2849
=TopicVar87@                       Abs   77138 #00012D52 -  2850
=TopicVar88!                       Abs   77048 #00012CF8 -  2851
=TopicVar88@                       Abs   77139 #00012D53 -  2852
=TopicVar89!                       Abs   77049 #00012CF9 -  2853
=TopicVar89@                       Abs   77140 #00012D54 -  2854
=TopicVar8@                        Abs   77059 #00012D03 -  2855
=TopicVar9!                        Abs   76969 #00012CA9 -  2856
=TopicVar90!                       Abs   77050 #00012CFA -  2857
=TopicVar90@                       Abs   77141 #00012D55 -  2858
=TopicVar91!                       Abs   77051 #00012CFB -  2859
=TopicVar91@                       Abs   77142 #00012D56 -  2860
=TopicVar9@                        Abs   77060 #00012D04 -  2861
=TopicVarN!                        Abs  231231 #0003873F -  2862
=TopicVarN@                        Abs  231195 #0003871B -  2863
=TraceY                            Abs  196494 #0002FF8E -  2864
 TriAlphaBit                       Abs       3 #00000003 -  5370
 TriAlphaFl                        Abs      60 #0000003C -  5240  5369  5370
 TriAlphaNib                       Abs      14 #0000000E -  5369
 TriUserBit                        Abs       0 #00000000 -  5373
 TriUserFl                         Abs      61 #0000003D -  5241  5372  5373
 TriUserNib                        Abs      15 #0000000F -  5372
=Trow                              Abs     776 #00000308 -  6281
=Trow@                             Abs  160155 #0002719B -  2865
=TrueFalse                         Abs   65007 #0000FDEF -  2866
=TrueTrue                          Abs   50294 #0000C476 -  2867
=TurnOff                           Abs   19027 #00004A53 -  2868
=UARTBUFLEN                        Abs  258735 #0003F2AF -  2869
=UNCOERCE                          Abs   78617 #00013319 -  2870
=UNCOERCE%%                        Abs   66577 #00010411 -  2871
=UNITSYM                           Abs   18797 #0000496D -  2872
=UNROLL                            Abs   13214 #0000339E -  2873
=UNROT                             Abs   52612 #0000CD84 -  2874
=UNROTDROP                         Abs   58310 #0000E3C6 -  2875
=UNROTDUP                          Abs   62927 #0000F5CF -  2876
=UNROTOVER                         Abs   63854 #0000F96E -  2877
=UNTIL                             Abs   31137 #000079A1 -  2878
=UnLockAlpha                       Abs  151607 #00025037 -  2879
 UnderfActBit                      Abs       3 #00000003 -  5376
 UnderfActFl                       Abs      20 #00000014 -  5202  5375  5376
 UnderfActNib                      Abs       4 #00000004 -  5375
 UnderfNegBit                      Abs       2 #00000002 -  5379
 UnderfNegFl                       Abs      23 #00000017 -  5205  5378  5379
 UnderfNegNib                      Abs       5 #00000005 -  5378
 UnderfPosBit                      Abs       3 #00000003 -  5382
 UnderfPosFl                       Abs      24 #00000018 -  5206  5381  5382
 UnderfPosNib                      Abs       5 #00000005 -  5381
=UnpackGrob                        Abs  260306 #0003F8D2 -  2880
=Update_tTYPE                      Abs  259049 #0003F3E9 -  2881
=UserITE                           Abs   67412 #00010754 -  2882
 UserKeysBit                       Abs       1 #00000001 -  5385
 UserKeysFl                        Abs      62 #0000003E -  5242  5384  5385
 UserKeysNib                       Abs      15 #0000000F -  5384
=UserSto                           Abs  259050 #0003F3EA -  2883
=VERYSLOW                          Abs  151969 #000251A1 -  2884
=VERYVERYSLOW                      Abs  151985 #000251B1 -  2885
=VLMAlarmMsg                       Abs   72877 #00011CAD -  2886
=VLMUserKeys                       Abs   72867 #00011CA3 -  2887
=VLMcmdlmsg                        Abs   72897 #00011CC1 -  2888
=VLMhistmsg                        Abs   72857 #00011C99 -  2889
=VLMlastargs                       Abs   72887 #00011CB7 -  2890
=VLMmsg                            Abs   72827 #00011C7B -  2891
=VLMpurgemsg                       Abs   72817 #00011C71 -  2892
=VLMstkmsg                         Abs   72837 #00011C85 -  2893
=VLMundomsg                        Abs   72847 #00011C8F -  2894
=VTick                             Abs     355 #00000163 -  6135
=VTick@                            Abs  159815 #00027047 -  2895
=VZoom                             Abs     411 #0000019B -  6155
=VZoom@                            Abs  159855 #0002706F -  2896
 VerboseBit                        Abs       1 #00000001 -  5322
 VerboseFl                         Abs      58 #0000003A -  5238  5321  5322
 VerboseNib                        Abs      14 #0000000E -  5321
 VerticalListBit                   Abs       0 #00000000 -  5892
 VerticalListFl                    Abs      97 #00000061 -  5890  5891  5892
 VerticalListNib                   Abs      24 #00000018 -  5891
 VerticalVectorBit                 Abs       1 #00000001 -  5895
 VerticalVectorFl                  Abs      98 #00000062 -  5893  5894  5895
 VerticalVectorNib                 Abs      24 #00000018 -  5894
=WHILE                             Abs   31175 #000079C7 -  2897
=WINDOWBOT?                        Abs  259724 #0003F68C -  2898
=WINDOWCORNER                      Abs  130121 #0001FC49 -  2899
=WINDOWDOWN                        Abs  128379 #0001F57B -  2900
=WINDOWLEFT                        Abs  129087 #0001F83F -  2901
=WINDOWLEFT?                       Abs  259725 #0003F68D -  2902
=WINDOWRIGHT                       Abs  129548 #0001FA0C -  2903
=WINDOWRIGHT?                      Abs  259726 #0003F68E -  2904
=WINDOWTOP?                        Abs  259727 #0003F68F -  2905
=WINDOWUP                          Abs  128291 #0001F523 -  2906
=WINDOWXY                          Abs  129798 #0001FB06 -  2907
=WaitForKey                        Abs  156379 #000262DB -  2908
=WaitTbz0                          Abs   94349 #0001708D -  2909
=WidthSmF                          Abs  259728 #0003F690 -  2910
=X@                                Abs   40001 #00009C41 -  2911
=XEQSETLIB                         Abs  258511 #0003F1CF -  2912
=XFERFAIL                          Abs   73297 #00011E51 -  2913
=XHI                               Abs   17767 #00004567 -  2914
=XHI-1                             Abs   17757 #0000455D -  2915
=XOR                               Abs   15066 #00003ADA -  2916
=XPURGEp                           Abs   40241 #00009D31 -  2917
=XPURGEp0                          Abs   40301 #00009D6D -  2918
=XRCLp                             Abs   39871 #00009BBF -  2919
=XRCLp0                            Abs   39961 #00009C19 -  2920
=XSTOp                             Abs   39382 #000099D6 -  2921
=XSTOp0                            Abs   39841 #00009BA1 -  2922
=XYGROBDISP                        Abs  125898 #0001EBCA -  2923
=XYZ>ZCOLA                         Abs   64526 #0000FC0E -  2924
=XYZ>ZTRUE                         Abs   63377 #0000F791 -  2925
=XYZW>YWZX                         Abs   66727 #000104A7 -  2926
=Xmax                              Abs     131 #00000083 -  6063
=Xmax!                             Abs  159650 #00026FA2 -  2927
=Xmax2                             Abs     243 #000000F3 -  6101
=Xmax2@                            Abs  159735 #00026FF7 -  2928
=Xmax@                             Abs  159655 #00026FA7 -  2929
=Xmin                              Abs     103 #00000067 -  6053
=Xmin!                             Abs  159630 #00026F8E -  2930
=Xmin2                             Abs     215 #000000D7 -  6093
=Xmin2@                            Abs  159715 #00026FE3 -  2931
=Xmin@                             Abs  159635 #00026F93 -  2932
=Xorbitmap                         Abs  232536 #00038C58 -  2933
=YHI                               Abs   17097 #000042C9 -  2934
=Ymax                              Abs     187 #000000BB -  6083
=Ymax2                             Abs     299 #0000012B -  6117
=Ymax2@                            Abs  159775 #0002701F -  2935
=Ymax@                             Abs  159695 #00026FCF -  2936
=Ymin                              Abs     159 #0000009F -  6073
=Ymin2                             Abs     271 #0000010F -  6109
=Ymin2@                            Abs  159755 #0002700B -  2937
=Ymin@                             Abs  159675 #00026FBB -  2938
=ZERO                              Abs   16457 #00004049 -  2939  6423
=ZEROFALSE                         Abs   65047 #0000FE17 -  2940
=ZEROISTOPSTO                      Abs   67722 #0001088A -  2941
=ZEROOVER                          Abs   63834 #0000F95A -  2942
=ZEROSWAP                          Abs   63252 #0000F714 -  2943
=ZEROZERO                          Abs   59798 #0000E996 -  2944
=ZERO_DO                           Abs   31644 #00007B9C -  2945
=ZoomAutoUI                        Abs  259627 #0003F62B -  2946
=_About                            Rel    1665 #00000681 -  6739  6347
=_Action                           Rel    1564 #0000061C -  6651  6343
=_Entry                            Rel    1448 #000005A8 -  6582  6339
=_Exit                             Rel    1509 #000005E5 -  6620  6341
=_Main                             Rel     992 #000003E0 -  6405  6337
=_Reset                            Rel    1615 #0000064F -  6710  6345
=alg=                              Abs  239837 #0003A8DD -  2947
 altROMID                          Abs    1789 #000006FD -  5968  5970  5971
                                        5972  5973  5974  5975
=apletPTR!                         Abs   75510 #000126F6 -  2948
=apletPTR@                         Abs   75526 #00012706 -  2949
=apndit                            Abs  258376 #0003F148 -  2950
=argswap                           Abs  258377 #0003F149 -  2951
=argswap&&                         Abs  258736 #0003F2B0 -  2952
=argswapnext                       Abs  258737 #0003F2B1 -  2953
=backup                            Abs   18047 #0000467F -  2954
=blackbox                          Abs  260134 #0003F826 -  2955
=case                              Abs   54620 #0000D55C -  2956  6438
=case2DROP                         Abs   54585 #0000D539 -  2957
=case2drop                         Abs   54504 #0000D4E8 -  2958
=case2drpfls                       Abs   65147 #0000FE7B -  2959
=caseDEADKEY                       Abs   66662 #00010466 -  2960
=caseDROP                          Abs   54548 #0000D514 -  2961
=caseDoBadKey                      Abs   66662 #00010466 -  2962
=caseDrpBadKy                      Abs   66637 #0001044D -  2963
=caseERRJMP                        Abs   64081 #0000FA51 -  2964
=caseFALSE                         Abs   65172 #0000FE94 -  2965
=caseSIZEERR                       Abs   66457 #00010399 -  2966
=caseTRUE                          Abs   64987 #0000FDDB -  2967
=casedrop                          Abs   54464 #0000D4C0 -  2968
=casedrpfls                        Abs   65122 #0000FE62 -  2969
=casedrptru                        Abs   65817 #00010119 -  2970
=char                              Abs   17567 #0000449F -  2971
=check_xrange                      Abs  259729 #0003F691 -  2972
=check_yrange                      Abs  259730 #0003F692 -  2973
=chooselst                         Abs  258738 #0003F2B2 -  2974
=completed                         Abs   50294 #0000C476 -  2975
=d*                                Abs  225797 #00037205 -  2976
=d<                                Abs  225705 #000371A9 -  2977
=d<=                               Abs  225744 #000371D0 -  2978
=d>                                Abs  225589 #00037135 -  2979
=d>%                               Abs  226496 #000374C0 -  2980
=d>=                               Abs  225723 #000371BB -  2981
=dARRYcase                         Abs   67102 #0001061E -  2982
=dDIV                              Abs  226015 #000372DF -  2983
=dIDNTNcase                        Abs   67202 #00010682 -  2984
=dLISTcase                         Abs   67122 #00010632 -  2985
=dMOD                              Abs  226051 #00037303 -  2986
=dREALNcase                        Abs   67222 #00010696 -  2987
=dirstrucchk                       Abs   47460 #0000B964 -  2988
=dmuldiv                           Abs  226085 #00037325 -  2989
=docr                              Abs  258739 #0003F2B3 -  2990
=doptr!                            Abs   75778 #00012802 -  2991
=doptr@                            Abs   75762 #000127F2 -  2992
=dowait                            Abs  239579 #0003A7DB -  2993
=dvarlsBIND                        Abs   66217 #000102A9 -  2994
=dvbind                            Abs  258147 #0003F063 -  2995
=elsiename                         Abs  258740 #0003F2B4 -  2996
 endCode                           Rel    1686 #00000696 -  6756  6384
 endLink                           Rel     975 #000003CF -  6353  6335
=failed                            Abs   50314 #0000C48A -  2997
=filename                          Abs  258385 #0003F151 -  2998
=funcCache@                        Abs  160790 #00027416 -  2999
=funcPTR!                          Abs   75542 #00012716 -  3000
=funcPTR@                          Abs   75558 #00012726 -  3001
=gFldVal                           Abs  259527 #0003F5C7 -  3002
=get1                              Abs   53341 #0000D05D -  3003
=grobAlertIcon                     Abs  259542 #0003F5D6 -  3004
=grobCheck                         Abs  259534 #0003F5CE -  3005
=grobCheckKey                      Abs  259541 #0003F5D5 -  3006
=grobCheckX                        Abs  259535 #0003F5CF -  3007
=grobInvChk                        Abs  259536 #0003F5D0 -  3008
=grobInvChkX                       Abs  259537 #0003F5D1 -  3009
=grobInvNoChk                      Abs  259540 #0003F5D4 -  3010
=grobInvUnChkX                     Abs  259539 #0003F5D3 -  3011
=grobMoreDown                      Abs  259731 #0003F693 -  3012
=grobMoreUp                        Abs  259732 #0003F694 -  3013
=grobNoMore                        Abs  259733 #0003F695 -  3014
=grobPOBox2                        Abs  259737 #0003F699 -  3015
=grobPOBox3                        Abs  259738 #0003F69A -  3016
=grobPOBox4                        Abs  259739 #0003F69B -  3017
=grobPOBox5                        Abs  259740 #0003F69C -  3018
=grobPOBoxP2                       Abs  259734 #0003F696 -  3019
=grobPOBoxP3                       Abs  259735 #0003F697 -  3020
=grobPOBoxP4                       Abs  259736 #0003F698 -  3021
=grobQueryIcon                     Abs  259543 #0003F5D7 -  3022
=grobTitleBar                      Abs  259544 #0003F5D8 -  3023
=grobUnCheckX                      Abs  259538 #0003F5D2 -  3024
 hasALIAS                          Abs       2 #00000002 -  5398
 hasCOLCT                          Abs       2 #00000002 -  5404
 hasDER                            Abs       8 #00000008 -  5402
 hasEXPND                          Abs       1 #00000001 -  5405
 hasFORM                           Abs       8 #00000008 -  5408
 hasHELP                           Abs       4 #00000004 -  5396
 hasINTG                           Abs       4 #00000004 -  5409
 hasINV                            Abs       4 #00000004 -  5403
 hasPDATA                          Abs       1 #00000001 -  5399
 hasPROMPTM                        Abs       4 #00000004 -  5397
 hasVUNS                           Abs       1 #00000001 -  5411
 hasWHERE                          Abs       2 #00000002 -  5410
=idE0                              Abs  182592 #0002C940 -  3025
=idE1                              Abs  182385 #0002C871 -  3026
=idE2                              Abs  182408 #0002C888 -  3027
=idE3                              Abs  182431 #0002C89F -  3028
=idE4                              Abs  182454 #0002C8B6 -  3029
=idE5                              Abs  182477 #0002C8CD -  3030
=idE6                              Abs  182500 #0002C8E4 -  3031
=idE7                              Abs  182523 #0002C8FB -  3032
=idE8                              Abs  182546 #0002C912 -  3033
=idE9                              Abs  182569 #0002C929 -  3034
=idF0                              Abs  174863 #0002AB0F -  3035
=idF1                              Abs  173810 #0002A6F2 -  3036
=idF2                              Abs  173927 #0002A767 -  3037
=idF3                              Abs  174044 #0002A7DC -  3038
=idF4                              Abs  174161 #0002A851 -  3039
=idF5                              Abs  174278 #0002A8C6 -  3040
=idF6                              Abs  174395 #0002A93B -  3041
=idF7                              Abs  174512 #0002A9B0 -  3042
=idF8                              Abs  174629 #0002AA25 -  3043
=idF9                              Abs  174746 #0002AA9A -  3044
=idR0                              Abs  178373 #0002B8C5 -  3045
=idR1                              Abs  177320 #0002B4A8 -  3046
=idR2                              Abs  177437 #0002B51D -  3047
=idR3                              Abs  177554 #0002B592 -  3048
=idR4                              Abs  177671 #0002B607 -  3049
=idR5                              Abs  177788 #0002B67C -  3050
=idR6                              Abs  177905 #0002B6F1 -  3051
=idR7                              Abs  178022 #0002B766 -  3052
=idR8                              Abs  178139 #0002B7DB -  3053
=idR9                              Abs  178256 #0002B850 -  3054
=idU0                              Abs  173693 #0002A67D -  3055
=idU1                              Abs  172505 #0002A1D9 -  3056
=idU2                              Abs  172637 #0002A25D -  3057
=idU3                              Abs  172769 #0002A2E1 -  3058
=idU4                              Abs  172901 #0002A365 -  3059
=idU5                              Abs  173033 #0002A3E9 -  3060
=idU6                              Abs  173165 #0002A46D -  3061
=idU7                              Abs  173297 #0002A4F1 -  3062
=idU8                              Abs  173429 #0002A575 -  3063
=idU9                              Abs  173561 #0002A5F9 -  3064
=idX0                              Abs  177086 #0002B3BE -  3065
=idX1                              Abs  174980 #0002AB84 -  3066
=idX2                              Abs  175214 #0002AC6E -  3067
=idX3                              Abs  175448 #0002AD58 -  3068
=idX4                              Abs  175682 #0002AE42 -  3069
=idX5                              Abs  175916 #0002AF2C -  3070
=idX6                              Abs  176150 #0002B016 -  3071
=idX7                              Abs  176384 #0002B100 -  3072
=idX8                              Abs  176618 #0002B1EA -  3073
=idX9                              Abs  176852 #0002B2D4 -  3074
=idY0                              Abs  177203 #0002B433 -  3075
=idY1                              Abs  175097 #0002ABF9 -  3076
=idY2                              Abs  175331 #0002ACE3 -  3077
=idY3                              Abs  175565 #0002ADCD -  3078
=idY4                              Abs  175799 #0002AEB7 -  3079
=idY5                              Abs  176033 #0002AFA1 -  3080
=idY6                              Abs  176267 #0002B08B -  3081
=idY7                              Abs  176501 #0002B175 -  3082
=idY8                              Abs  176735 #0002B25F -  3083
=idY9                              Abs  176969 #0002B349 -  3084
=idntany                           Abs   17417 #00004409 -  3085
=illnameerr                        Abs   72717 #00011C0D -  3086
=j%0=case                          Abs   67062 #000105F6 -  3087
=jEQcase                           Abs   66897 #00010551 -  3088
=lamany                            Abs   17577 #000044A9 -  3089
=lbrac                             Abs   74728 #000123E8 -  3090
=library                           Abs   17887 #000045DF -  3091
=loopdirck                         Abs   47561 #0000B9C9 -  3092
=metaDUP                           Abs   86927 #0001538F -  3093
=metaROTDUP                        Abs   67477 #00010795 -  3094
=metainsert                        Abs  258741 #0003F2B5 -  3095
=newsymbPA                         Abs  258742 #0003F2B6 -  3096
 nonALG                            Abs       8 #00000008 -  5395
=nultrior                          Abs  258152 #0003F068 -  3097
=numargs                           Abs  258512 #0003F1D0 -  3098
=oneexpr                           Abs  258743 #0003F2B7 -  3099
=onestring                         Abs  258412 #0003F16C -  3100
=optfilename                       Abs  258744 #0003F2B8 -  3101
=otherNG?                          Abs   76875 #00012C4B -  3102
=otherPTR!                         Abs   75734 #000127D6 -  3103
=otherPTR@                         Abs   75750 #000127E6 -  3104
=pZpargSWAPUn                      Abs   67597 #0001080D -  3105
=paramPTR!                         Abs   75606 #00012756 -  3106
=paramPTR@                         Abs   75622 #00012766 -  3107
 pdCM                              Abs       6 #00000006 -  5420
 pdEQ                              Abs       7 #00000007 -  5421
 pdEX                              Abs       0 #00000000 -  5414
 pdLP                              Abs       4 #00000004 -  5418
 pdOP                              Abs       1 #00000001 -  5415
 pdOS0                             Abs       8 #00000008 -  5422
 pdOS1                             Abs       9 #00000009 -  5423
 pdOS2                             Abs      10 #0000000A -  5424
 pdOS3                             Abs      11 #0000000B -  5425
 pdOS4                             Abs      12 #0000000C -  5426
 pdOS5                             Abs      13 #0000000D -  5427
 pdOS6                             Abs      14 #0000000E -  5428
 pdOS7                             Abs      15 #0000000F -  5429
 pdQE                              Abs       2 #00000002 -  5416
 pdQN                              Abs       3 #00000003 -  5417
 pdRP                              Abs       5 #00000005 -  5419
=plDRPpZparg                       Abs   67537 #000107D1 -  3108
=polarPTR!                         Abs   75574 #00012736 -  3109
=polarPTR@                         Abs   75590 #00012746 -  3110
=popflag                           Abs   54731 #0000D5CB -  3111
=prx1                              Abs  258745 #0003F2B9 -  3112
=psh                               Abs   86120 #00015068 -  3113
=psh&                              Abs  258746 #0003F2BA -  3114
=psh1                              Abs  258154 #0003F06A -  3115
=psh1&                             Abs   85912 #00014F98 -  3116
=psh1&rev                          Abs  258514 #0003F1D2 -  3117
=psh1top&                          Abs  258155 #0003F06B -  3118
=psharg                            Abs  258747 #0003F2BB -  3119
=pshmonop                          Abs  258748 #0003F2BC -  3120
=pshtop&                           Abs  258416 #0003F170 -  3121
=pshzer                            Abs  258156 #0003F06C -  3122
=pull                              Abs   85872 #00014F70 -  3123
=pullpsh1&                         Abs  258159 #0003F06F -  3124
=pullrev                           Abs  258160 #0003F070 -  3125
=rbrac                             Abs   74716 #000123DC -  3126
=realPA                            Abs  258422 #0003F176 -  3127
=resolved                          Abs  258423 #0003F177 -  3128
=reversym                          Abs   86420 #00015194 -  3129
=roll2ND                           Abs  258749 #0003F2BD -  3130
=roll2top&                         Abs   67517 #000107BD -  3131
=roll3RD                           Abs  258515 #0003F1D3 -  3132
=roll4TH                           Abs  258750 #0003F2BE -  3133
=rollNTH                           Abs  258751 #0003F2BF -  3134
=rolltwotop&                       Abs   67517 #000107BD -  3135
=rrp                               Abs   16927 #0000421F -  3136
=s1>                               Abs  259741 #0003F69D -  3137
=sFldVal                           Abs  259528 #0003F5C8 -  3138
=seqPTR!                           Abs   75638 #00012776 -  3139
=seqPTR@                           Abs   75654 #00012786 -  3140
=setbeep                           Abs  132943 #0002074F -  3141
=solvePTR!                         Abs   75702 #000127B6 -  3142
=solvePTR@                         Abs   75718 #000127C6 -  3143
=solverTTT                         Abs   81571 #00013EA3 -  3144
=startSQFORM                       Abs  258752 #0003F2C0 -  3145
=statPTR!                          Abs   75670 #00012796 -  3146
=statPTR@                          Abs   75686 #000127A6 -  3147
=symcomp                           Abs   97377 #00017C61 -  3148
=syminner&                         Abs  258753 #0003F2C1 -  3149
=syminner&N                        Abs  258165 #0003F075 -  3150
=syminnertwo                       Abs  258754 #0003F2C2 -  3151
=tTYPE@                            Abs  159615 #00026F7F -  3152
=threeexprs                        Abs  258755 #0003F2C3 -  3153
=ticR                              Abs   55122 #0000D752 -  3154
=toLEN_DO                          Abs   64912 #0000FD90 -  3155
=tok$                              Abs   74802 #00012432 -  3156
=tok&                              Abs   74814 #0001243E -  3157
=tok'                              Abs   75024 #00012510 -  3158
=tok*                              Abs   75108 #00012564 -  3159
=tok+                              Abs   75132 #0001257C -  3160
=tok,                              Abs   75036 #0001251C -  3161
=tok-                              Abs   75144 #00012588 -  3162
=tok.                              Abs   75048 #00012528 -  3163
=tok/                              Abs   75120 #00012570 -  3164
=tok0                              Abs   75224 #000125D8 -  3165
=tok1                              Abs   75236 #000125E4 -  3166
=tok2                              Abs   75248 #000125F0 -  3167
=tok3                              Abs   75260 #000125FC -  3168
=tok4                              Abs   75272 #00012608 -  3169
=tok5                              Abs   75284 #00012614 -  3170
=tok6                              Abs   75296 #00012620 -  3171
=tok7                              Abs   75308 #0001262C -  3172
=tok8                              Abs   75320 #00012638 -  3173
=tok8cktrior                       Abs   50653 #0000C5DD -  3174
=tok8trior                         Abs   50665 #0000C5E9 -  3175
=tok9                              Abs   75332 #00012644 -  3176
=tok:                              Abs   95063 #00017357 -  3177
=tok;                              Abs   75060 #00012534 -  3178
=tok;triand                        Abs  258466 #0003F1A2 -  3179
=tok<<                             Abs   74850 #00012462 -  3180
=tok=                              Abs   75156 #00012594 -  3181
=tok>>                             Abs   74838 #00012456 -  3182
=tokCTGROB                         Abs   75192 #000125B8 -  3183
=tokCTSTR                          Abs   75210 #000125CA -  3184
=tokDER                            Abs   75180 #000125AC -  3185
=tokESC                            Abs   74826 #0001244A -  3186
=tokSIGMA                          Abs   74886 #00012486 -  3187
=tokSQRT                           Abs   75168 #000125A0 -  3188
=tokUNKNOWN                        Abs   74988 #000124EC -  3189
=tokWHERE                          Abs   74898 #00012492 -  3190
=tok[                              Abs   74742 #000123F6 -  3191
=tok]                              Abs   74716 #000123DC -  3192
=tok^                              Abs   75096 #00012558 -  3193
=tok_                              Abs   74976 #000124E0 -  3194
=tokanglesign                      Abs   74874 #0001247A -  3195
=tokexponent                       Abs   74862 #0001246E -  3196
=toklparen                         Abs   75072 #00012540 -  3197
=tokquote                          Abs   75012 #00012504 -  3198
=tokrparen                         Abs   75084 #0001254C -  3199
=toksharp                          Abs   74778 #0001241A -  3200
=toktriand                         Abs  258756 #0003F2C4 -  3201
=tokuscore                         Abs   74790 #00012426 -  3202
=tok{                              Abs   74754 #00012402 -  3203
=tok}                              Abs   74766 #0001240E -  3204
=top&                              Abs  258167 #0003F077 -  3205
=top&Cr                            Abs   67452 #0001077C -  3206
=topic_install                     Abs  229813 #000381B5 -  3207
=topic_uninstall                   Abs  230068 #000382B4 -  3208
=twoexprs                          Abs  258757 #0003F2C5 -  3209
=twostrings                        Abs  258758 #0003F2C6 -  3210
=uart_buffer                       Abs  525081 #00080319 -  3211
=unroll2ND                         Abs  258468 #0003F1A4 -  3212
=unroll3RD                         Abs  258759 #0003F2C7 -  3213
=unroll4TH                         Abs  258760 #0003F2C8 -  3214
=unrollNTH                         Abs  258761 #0003F2C9 -  3215
=unsyminner                        Abs  258169 #0003F079 -  3216
=unsymone                          Abs  258762 #0003F2CA -  3217
=verysyminner                      Abs  258170 #0003F07A -  3218
=veryunsymin                       Abs  258171 #0003F07B -  3219
=vunsymfcn                         Abs  258763 #0003F2CB -  3220
=x#?                               Abs  253711 #0003DF0F -  3221
=x%                                Abs  246866 #0003C452 -  3222
=x%CH                              Abs  247099 #0003C53B -  3223
=x%T                               Abs  246985 #0003C4C9 -  3224
=x'                                Abs  257406 #0003ED7E -  3225
=x+                                Abs  240543 #0003AB9F -  3226
=x-                                Abs  241000 #0003AD68 -  3227
=x->NUM                            Abs  239176 #0003A648 -  3228
=x->Q                              Abs  251914 #0003D80A -  3229
=x->QPI                            Abs  251945 #0003D829 -  3230
=x/                                Abs  241610 #0003AFCA -  3231
=x<                                Abs  247429 #0003C685 -  3232
=x<<                               Abs  257357 #0003ED4D -  3233
=x<=?                              Abs  254025 #0003E049 -  3234
=x<?                               Abs  247429 #0003C685 -  3235
=x=                                Abs  239837 #0003A8DD -  3236
=x==                               Abs  247737 #0003C7B9 -  3237
=x=?                               Abs  247737 #0003C7B9 -  3238
=x>                                Abs  247593 #0003C729 -  3239
=x>=?                              Abs  254189 #0003E0ED -  3240
=x>>                               Abs  257384 #0003ED68 -  3241
=x>?                               Abs  247593 #0003C729 -  3242
=x>HMS                             Abs  246395 #0003C27B -  3243
=x>NUM                             Abs  239176 #0003A648 -  3244
=xABS                              Abs  240201 #0003AA49 -  3245
=xACOS                             Abs  244193 #0003B9E1 -  3246
=xACOSH                            Abs  244440 #0003BAD8 -  3247
=xALG->                            Abs  255358 #0003E57E -  3248
=xALOG                             Abs  244955 #0003BCDB -  3249
=xAND                              Abs  253076 #0003DC94 -  3250
=xAPPLY                            Abs  250146 #0003D122 -  3251
=xARG                              Abs  243104 #0003B5A0 -  3252
=xASIN                             Abs  244059 #0003B95B -  3253
=xASINH                            Abs  244371 #0003BA93 -  3254
=xATAN                             Abs  244297 #0003BA49 -  3255
=xATANH                            Abs  244554 #0003BB4A -  3256
=xAngle                            Abs  181306 #0002C43A -  3257
=xAns                              Abs  181041 #0002C331 -  3258
=xArea                             Abs  182706 #0002C9B2 -  3259
=xAxes                             Abs  181335 #0002C457 -  3260
=xBEEP                             Abs  239150 #0003A62E -  3261
=xC0                               Abs  178603 #0002B9AB -  3262
=xC1                               Abs  178396 #0002B8DC -  3263
=xC2                               Abs  178419 #0002B8F3 -  3264
=xC3                               Abs  178442 #0002B90A -  3265
=xC4                               Abs  178465 #0002B921 -  3266
=xC5                               Abs  178488 #0002B938 -  3267
=xC6                               Abs  178511 #0002B94F -  3268
=xC7                               Abs  178534 #0002B966 -  3269
=xC8                               Abs  178557 #0002B97D -  3270
=xC9                               Abs  178580 #0002B994 -  3271
=xCASE                             Abs  257681 #0003EE91 -  3272
=xCEIL                             Abs  245426 #0003BEB2 -  3273
=xCHS                              Abs  240056 #0003A9B8 -  3274
=xCLLCD                            Abs  239716 #0003A864 -  3275
=xCMDAPPLY                         Abs  251314 #0003D5B2 -  3276
=xCNRM                             Abs  246586 #0003C33A -  3277
=xCOLCT                            Abs  252403 #0003D9F3 -  3278
=xCOMB                             Abs  247268 #0003C5E4 -  3279
=xCONJ                             Abs  240287 #0003AA9F -  3280
=xCONSTANTe                        Abs  240475 #0003AB5B -  3281
=xCONT                             Abs  239808 #0003A8C0 -  3282
=xCORR                             Abs  180038 #0002BF46 -  3283
=xCOS                              Abs  243669 #0003B7D5 -  3284
=xCOSH                             Abs  243911 #0003B8C7 -  3285
=xCOV                              Abs  180065 #0002BF61 -  3286
=xCROSS                            Abs  246764 #0003C3EC -  3287
=xConnect                          Abs  181389 #0002C48D -  3288
=xCoord                            Abs  181620 #0002C574 -  3289
=xD0                               Abs  178603 #0002B9AB -  3290
=xD1                               Abs  178396 #0002B8DC -  3291
=xD2                               Abs  178419 #0002B8F3 -  3292
=xD3                               Abs  178442 #0002B90A -  3293
=xD4                               Abs  178465 #0002B921 -  3294
=xD5                               Abs  178488 #0002B938 -  3295
=xD6                               Abs  178511 #0002B94F -  3296
=xD7                               Abs  178534 #0002B966 -  3297
=xD8                               Abs  178557 #0002B97D -  3298
=xD9                               Abs  178580 #0002B994 -  3299
=xD>R                              Abs  246307 #0003C223 -  3300
=xDER                              Abs  248654 #0003CB4E -  3301
=xDET                              Abs  246637 #0003C36D -  3302
=xDIR                              Abs  257983 #0003EFBF -  3303
=xDISP                             Abs  239124 #0003A614 -  3304
=xDO                               Abs  255637 #0003E695 -  3305
=xDOERR                            Abs  238546 #0003A3D2 -  3306
=xDOT                              Abs  246688 #0003C3A0 -  3307
=xDate                             Abs  181279 #0002C41F -  3308
=xDigits                           Abs  182259 #0002C7F3 -  3309
=xE                                Abs  179050 #0002BB6A -  3310
=xELSE                             Abs  255309 #0003E54D -  3311
=xENDDO                            Abs  257491 #0003EDD3 -  3312
=xENDTIC                           Abs  257432 #0003ED98 -  3313
=xEPS                              Abs  240441 #0003AB39 -  3314
=xERR0                             Abs  238592 #0003A400 -  3315
=xERRM                             Abs  238634 #0003A42A -  3316
=xERRN                             Abs  238613 #0003A415 -  3317
=xERRTHEN                          Abs  257588 #0003EE34 -  3318
=xEVAL                             Abs  238655 #0003A43F -  3319
=xEVAL>                            Abs  251566 #0003D6AE -  3320
=xEXIT                             Abs  238546 #0003A3D2 -  3321
=xEXP                              Abs  244653 #0003BBAD -  3322
=xEXPAN                            Abs  252470 #0003DA36 -  3323
=xEXPM                             Abs  245083 #0003BD5B -  3324
=xEXPM1                            Abs  245083 #0003BD5B -  3325
=xExtremum                         Abs  182671 #0002C98F -  3326
=xF0                               Abs  174772 #0002AAB4 -  3327
=xF1                               Abs  173719 #0002A697 -  3328
=xF2                               Abs  173836 #0002A70C -  3329
=xF3                               Abs  173953 #0002A781 -  3330
=xF4                               Abs  174070 #0002A7F6 -  3331
=xF5                               Abs  174187 #0002A86B -  3332
=xF6                               Abs  174304 #0002A8E0 -  3333
=xF7                               Abs  174421 #0002A955 -  3334
=xF8                               Abs  174538 #0002A9CA -  3335
=xF9                               Abs  174655 #0002AA3F -  3336
=xFACT                             Abs  245142 #0003BD96 -  3337
=xFCNAPPLY                         Abs  250269 #0003D19D -  3338
=xFIT                              Abs  181066 #0002C34A -  3339
=xFLOOR                            Abs  245367 #0003BE77 -  3340
=xFORMUNIT                         Abs  252165 #0003D905 -  3341
=xFP                               Abs  245308 #0003BE3C -  3342
=xFUNCTION                         Abs  253000 #0003DC48 -  3343
=xFmList                           Abs  252323 #0003D9A3 -  3344
=xFmMat                            Abs  252367 #0003D9CF -  3345
=xFormat                           Abs  182228 #0002C7D4 -  3346
=xGrid                             Abs  181362 #0002C472 -  3347
=xH1                               Abs  178626 #0002B9C2 -  3348
=xH2                               Abs  178643 #0002B9D3 -  3349
=xH3                               Abs  178660 #0002B9E4 -  3350
=xH4                               Abs  178677 #0002B9F5 -  3351
=xH5                               Abs  178694 #0002BA06 -  3352
=xHAngle                           Abs  181091 #0002C363 -  3353
=xHDigits                          Abs  181155 #0002C3A3 -  3354
=xHFormat                          Abs  181122 #0002C382 -  3355
=xHMS+                             Abs  246475 #0003C2CB -  3356
=xHMS-                             Abs  246501 #0003C2E5 -  3357
=xHMS>                             Abs  246439 #0003C2A7 -  3358
=xHTick                            Abs  181848 #0002C658 -  3359
=xHighRes                          Abs  181422 #0002C4AE -  3360
=xHisWidth                         Abs  183085 #0002CB2D -  3361
=xHmax                             Abs  183143 #0002CB67 -  3362
=xHmin                             Abs  183116 #0002CB4C -  3363
=xHzoom                            Abs  181906 #0002C692 -  3364
=xI                                Abs  179134 #0002BBBE -  3365
=xIF                               Abs  254998 #0003E416 -  3366
=xIFEND                            Abs  255336 #0003E568 -  3367
=xIFERR                            Abs  256791 #0003EB17 -  3368
=xIFT                              Abs  238953 #0003A569 -  3369
=xIFTE                             Abs  238709 #0003A475 -  3370
=xIM                               Abs  248454 #0003CA86 -  3371
=xINF                              Abs  240407 #0003AB17 -  3372
=xINTEGRAL                         Abs  249168 #0003CD50 -  3373
=xINV                              Abs  242984 #0003B528 -  3374
=xINVERSE                          Abs  242883 #0003B4C3 -  3375
=xIP                               Abs  245249 #0003BE01 -  3376
=xISOL                             Abs  252576 #0003DAA0 -  3377
=xIerr                             Abs  181225 #0002C3E9 -  3378
=xIndep                            Abs  181757 #0002C5FD -  3379
=xInvCursor                        Abs  181521 #0002C511 -  3380
=xIsect                            Abs  182642 #0002C972 -  3381
=xKEY                              Abs  239737 #0003A879 -  3382
=xKILL                             Abs  238504 #0003A3A8 -  3383
=xLAST                             Abs  239202 #0003A662 -  3384
=xLN                               Abs  244727 #0003BBF7 -  3385
=xLNP1                             Abs  245029 #0003BD25 -  3386
=xLOG                              Abs  244841 #0003BC69 -  3387
=xLabels                           Abs  181556 #0002C534 -  3388
=xMANT                             Abs  246258 #0003C1F2 -  3389
=xMATCHDN                          Abs  252102 #0003D8C6 -  3390
=xMATCHUP                          Abs  252056 #0003D898 -  3391
=xMAX                              Abs  245534 #0003BF1E -  3392
=xMAXR                             Abs  240407 #0003AB17 -  3393
=xMAXS                             Abs  179755 #0002BE2B -  3394
=xMEANS                            Abs  179533 #0002BD4D -  3395
=xMEANX                            Abs  179859 #0002BE93 -  3396
=xMEANY                            Abs  179936 #0002BEE0 -  3397
=xMEDIAN                           Abs  179782 #0002BE46 -  3398
=xMIN                              Abs  245753 #0003BFF9 -  3399
=xMINR                             Abs  240441 #0003AB39 -  3400
=xMINS                             Abs  179728 #0002BE10 -  3401
=xMOD                              Abs  246179 #0003C1A3 -  3402
=xNEG                              Abs  240056 #0003A9B8 -  3403
=xNEGNEG                           Abs  240914 #0003AD12 -  3404
=xNEXT                             Abs  256398 #0003E98E -  3405
=xNOEVAL>                          Abs  251815 #0003D7A7 -  3406
=xNOT                              Abs  253374 #0003DDBE -  3407
=xNS                               Abs  179705 #0002BDF9 -  3408
=xNmax                             Abs  182955 #0002CAAB -  3409
=xNmin                             Abs  182928 #0002CA90 -  3410
=xNoteText                         Abs  182290 #0002C812 -  3411
=xNumCol                           Abs  182164 #0002C794 -  3412
=xNumFont                          Abs  182195 #0002C7B3 -  3413
=xNumIndep                         Abs  182065 #0002C731 -  3414
=xNumRow                           Abs  182133 #0002C775 -  3415
=xNumStart                         Abs  181964 #0002C6CC -  3416
=xNumStep                          Abs  181999 #0002C6EF -  3417
=xNumType                          Abs  182032 #0002C710 -  3418
=xNumZoom                          Abs  182100 #0002C754 -  3419
=xOFF                              Abs  238525 #0003A3BD -  3420
=xOR                               Abs  253235 #0003DD33 -  3421
=xPARAMETRIC                       Abs  253024 #0003DC60 -  3422
=xPERM                             Abs  247332 #0003C624 -  3423
=xPI                               Abs  240373 #0003AAF5 -  3424
=xPOLAR                            Abs  253012 #0003DC54 -  3425
=xPREDIV                           Abs  252279 #0003D977 -  3426
=xPSDEV                            Abs  179676 #0002BDDC -  3427
=xPVARS                            Abs  179618 #0002BDA2 -  3428
=xP\8DR                            Abs  248117 #0003C935 -  3429
=xPage                             Abs  182325 #0002C835 -  3430
=xPageNum                          Abs  182352 #0002C850 -  3431
=xQ1                               Abs  179813 #0002BE65 -  3432
=xQ3                               Abs  179836 #0002BE7C -  3433
=xQUAD                             Abs  252675 #0003DB03 -  3434
=xQUOTE                            Abs  249960 #0003D068 -  3435
=xR0                               Abs  178282 #0002B86A -  3436
=xR1                               Abs  177229 #0002B44D -  3437
=xR2                               Abs  177346 #0002B4C2 -  3438
=xR3                               Abs  177463 #0002B537 -  3439
=xR4                               Abs  177580 #0002B5AC -  3440
=xR5                               Abs  177697 #0002B621 -  3441
=xR6                               Abs  177814 #0002B696 -  3442
=xR7                               Abs  177931 #0002B70B -  3443
=xR8                               Abs  178048 #0002B780 -  3444
=xR9                               Abs  178165 #0002B7F5 -  3445
=xR>D                              Abs  246351 #0003C24F -  3446
=xRAND                             Abs  247213 #0003C5AD -  3447
=xRDZ                              Abs  247234 #0003C5C2 -  3448
=xRE                               Abs  248368 #0003CA30 -  3449
=xRELERR                           Abs  180090 #0002BF7A -  3450
=xREPEAT                           Abs  255540 #0003E634 -  3451
=xRND                              Abs  245887 #0003C07F -  3452
=xRNRM                             Abs  246535 #0003C307 -  3453
=xROOT                             Abs  249013 #0003CCB5 -  3454
=xRPN->                            Abs  257045 #0003EC15 -  3455
=xRSD                              Abs  246832 #0003C430 -  3456
=xRULES                            Abs  252537 #0003DA79 -  3457
=xR\8DP                            Abs  247941 #0003C885 -  3458
=xRadixMark                        Abs  181188 #0002C3C4 -  3459
=xRecenter                         Abs  181486 #0002C4EE -  3460
=xRoot                             Abs  182615 #0002C957 -  3461
=xS1                               Abs  178711 #0002BA17 -  3462
=xS1fit                            Abs  183325 #0002CC1D -  3463
=xS1mark                           Abs  183170 #0002CB82 -  3464
=xS2                               Abs  178728 #0002BA28 -  3465
=xS2fit                            Abs  183354 #0002CC3A -  3466
=xS2mark                           Abs  183201 #0002CBA1 -  3467
=xS3                               Abs  178745 #0002BA39 -  3468
=xS3fit                            Abs  183383 #0002CC57 -  3469
=xS3mark                           Abs  183232 #0002CBC0 -  3470
=xS4                               Abs  178762 #0002BA4A -  3471
=xS4fit                            Abs  183412 #0002CC74 -  3472
=xS4mark                           Abs  183263 #0002CBDF -  3473
=xS5                               Abs  178779 #0002BA5B -  3474
=xS5fit                            Abs  183441 #0002CC91 -  3475
=xS5mark                           Abs  183294 #0002CBFE -  3476
=xSAME                             Abs  253042 #0003DC72 -  3477
=xSHOW                             Abs  252753 #0003DB51 -  3478
=xSIGN                             Abs  243183 #0003B5EF -  3479
=xSILENT'                          Abs  257019 #0003EBFB -  3480
=xSIN                              Abs  243585 #0003B781 -  3481
=xSINH                             Abs  243837 #0003B87D -  3482
=xSQ                               Abs  243430 #0003B6E6 -  3483
=xSQRT                             Abs  243257 #0003B639 -  3484
=xSSDEV                            Abs  179647 #0002BDBF -  3485
=xSTART                            Abs  255760 #0003E710 -  3486
=xSTARTVAR                         Abs  255912 #0003E7A8 -  3487
=xSTEP                             Abs  256701 #0003EABD -  3488
=xSUM                              Abs  249589 #0003CEF5 -  3489
=xSVARS                            Abs  179589 #0002BD85 -  3490
=xSX                               Abs  179888 #0002BEB0 -  3491
=xSX2                              Abs  179911 #0002BEC7 -  3492
=xSXY                              Abs  180013 #0002BF2D -  3493
=xSY                               Abs  179965 #0002BEFD -  3494
=xSY2                              Abs  179988 #0002BF14 -  3495
=xSYSEVAL                          Abs  239044 #0003A5C4 -  3496
=xSeqPlot                          Abs  182982 #0002CAC6 -  3497
=xSimult                           Abs  181455 #0002C4CF -  3498
=xSlope                            Abs  182733 #0002C9CD -  3499
=xStatMode                         Abs  183015 #0002CAE7 -  3500
=xStatPlot                         Abs  183050 #0002CB0A -  3501
=xTAN                              Abs  243753 #0003B829 -  3502
=xTANH                             Abs  243985 #0003B911 -  3503
=xTAYLR                            Abs  252892 #0003DBDC -  3504
=xTHEN                             Abs  255147 #0003E4AB -  3505
=xTHENCASE                         Abs  257823 #0003EF1F -  3506
=xTOTS                             Abs  179562 #0002BD6A -  3507
=xTRNC                             Abs  246033 #0003C111 -  3508
=xTStep                            Abs  182816 #0002CA20 -  3509
=xThetaMax                         Abs  182872 #0002CA58 -  3510
=xThetaMin                         Abs  182845 #0002CA3D -  3511
=xThetaStep                        Abs  182899 #0002CA73 -  3512
=xTime                             Abs  181252 #0002C404 -  3513
=xTmax                             Abs  182789 #0002CA05 -  3514
=xTmin                             Abs  182762 #0002C9EA -  3515
=xTracing                          Abs  181587 #0002C553 -  3516
=xU0                               Abs  173587 #0002A613 -  3517
=xU1                               Abs  172404 #0002A174 -  3518
=xU2                               Abs  172531 #0002A1F3 -  3519
=xU3                               Abs  172663 #0002A277 -  3520
=xU4                               Abs  172795 #0002A2FB -  3521
=xU5                               Abs  172927 #0002A37F -  3522
=xU6                               Abs  173059 #0002A403 -  3523
=xU7                               Abs  173191 #0002A487 -  3524
=xU8                               Abs  173323 #0002A50B -  3525
=xU9                               Abs  173455 #0002A58F -  3526
=xUNTIL                            Abs  255744 #0003E700 -  3527
=xVTick                            Abs  181877 #0002C675 -  3528
=xVzoom                            Abs  181935 #0002C6AF -  3529
=xWAIT                             Abs  239479 #0003A777 -  3530
=xWHERE                            Abs  249879 #0003D017 -  3531
=xWHILE                            Abs  255425 #0003E5C1 -  3532
=xWHILEEND                         Abs  257459 #0003EDB3 -  3533
=xX0                               Abs  176995 #0002B363 -  3534
=xX1                               Abs  174889 #0002AB29 -  3535
=xX2                               Abs  175123 #0002AC13 -  3536
=xX3                               Abs  175357 #0002ACFD -  3537
=xX4                               Abs  175591 #0002ADE7 -  3538
=xX5                               Abs  175825 #0002AED1 -  3539
=xX6                               Abs  176059 #0002AFBB -  3540
=xX7                               Abs  176293 #0002B0A5 -  3541
=xX8                               Abs  176527 #0002B18F -  3542
=xX9                               Abs  176761 #0002B279 -  3543
=xXOR                              Abs  253482 #0003DE2A -  3544
=xXPON                             Abs  245485 #0003BEED -  3545
=xXROOT                            Abs  242539 #0003B36B -  3546
=xXcross                           Abs  181786 #0002C61A -  3547
=xXmax                             Abs  181676 #0002C5AC -  3548
=xXmin                             Abs  181649 #0002C591 -  3549
=xY0                               Abs  177112 #0002B3D8 -  3550
=xY1                               Abs  175006 #0002AB9E -  3551
=xY2                               Abs  175240 #0002AC88 -  3552
=xY3                               Abs  175474 #0002AD72 -  3553
=xY4                               Abs  175708 #0002AE5C -  3554
=xY5                               Abs  175942 #0002AF46 -  3555
=xY6                               Abs  176176 #0002B030 -  3556
=xY7                               Abs  176410 #0002B11A -  3557
=xY8                               Abs  176644 #0002B204 -  3558
=xY9                               Abs  176878 #0002B2EE -  3559
=xYcross                           Abs  181817 #0002C639 -  3560
=xYmax                             Abs  181730 #0002C5E2 -  3561
=xYmin                             Abs  181703 #0002C5C7 -  3562
=x^                                Abs  242040 #0003B178 -  3563
=xa                                Abs  178966 #0002BB16 -  3564
=xb                                Abs  178987 #0002BB2B -  3565
=xc                                Abs  179008 #0002BB40 -  3566
=xd                                Abs  179029 #0002BB55 -  3567
=xf                                Abs  179071 #0002BB7F -  3568
=xg                                Abs  179092 #0002BB94 -  3569
=xg0                               Abs  180811 #0002C24B -  3570
=xg1                               Abs  180834 #0002C262 -  3571
=xg2                               Abs  180857 #0002C279 -  3572
=xg3                               Abs  180880 #0002C290 -  3573
=xg4                               Abs  180903 #0002C2A7 -  3574
=xg5                               Abs  180926 #0002C2BE -  3575
=xg6                               Abs  180949 #0002C2D5 -  3576
=xg7                               Abs  180972 #0002C2EC -  3577
=xg8                               Abs  180995 #0002C303 -  3578
=xg9                               Abs  181018 #0002C31A -  3579
=xh                                Abs  179113 #0002BBA9 -  3580
=xi                                Abs  240509 #0003AB7D -  3581
=xint                              Abs  248530 #0003CAD2 -  3582
=xj                                Abs  179155 #0002BBD3 -  3583
=xk                                Abs  179176 #0002BBE8 -  3584
=xl                                Abs  179197 #0002BBFD -  3585
=xl0                               Abs  180581 #0002C165 -  3586
=xl1                               Abs  180604 #0002C17C -  3587
=xl2                               Abs  180627 #0002C193 -  3588
=xl3                               Abs  180650 #0002C1AA -  3589
=xl4                               Abs  180673 #0002C1C1 -  3590
=xl5                               Abs  180696 #0002C1D8 -  3591
=xl6                               Abs  180719 #0002C1EF -  3592
=xl7                               Abs  180742 #0002C206 -  3593
=xl8                               Abs  180765 #0002C21D -  3594
=xl9                               Abs  180788 #0002C234 -  3595
=xm                                Abs  179218 #0002BC12 -  3596
=xm0                               Abs  180351 #0002C07F -  3597
=xm1                               Abs  180374 #0002C096 -  3598
=xm2                               Abs  180397 #0002C0AD -  3599
=xm3                               Abs  180420 #0002C0C4 -  3600
=xm4                               Abs  180443 #0002C0DB -  3601
=xm5                               Abs  180466 #0002C0F2 -  3602
=xm6                               Abs  180489 #0002C109 -  3603
=xm7                               Abs  180512 #0002C120 -  3604
=xm8                               Abs  180535 #0002C137 -  3605
=xm9                               Abs  180558 #0002C14E -  3606
=xn                                Abs  179239 #0002BC27 -  3607
=xn1                               Abs  178881 #0002BAC1 -  3608
=xn2                               Abs  178898 #0002BAD2 -  3609
=xn3                               Abs  178915 #0002BAE3 -  3610
=xn4                               Abs  178932 #0002BAF4 -  3611
=xn5                               Abs  178949 #0002BB05 -  3612
=xo                                Abs  179260 #0002BC3C -  3613
=xp                                Abs  179281 #0002BC51 -  3614
=xq                                Abs  179302 #0002BC66 -  3615
=xr                                Abs  179323 #0002BC7B -  3616
=xs                                Abs  179344 #0002BC90 -  3617
=xs1                               Abs  178796 #0002BA6C -  3618
=xs2                               Abs  178813 #0002BA7D -  3619
=xs3                               Abs  178830 #0002BA8E -  3620
=xs4                               Abs  178847 #0002BA9F -  3621
=xs5                               Abs  178864 #0002BAB0 -  3622
=xt                                Abs  179365 #0002BCA5 -  3623
=xtheta                            Abs  179512 #0002BD38 -  3624
=xu                                Abs  179386 #0002BCBA -  3625
=xv                                Abs  179407 #0002BCCF -  3626
=xw                                Abs  179428 #0002BCE4 -  3627
=xx                                Abs  179449 #0002BCF9 -  3628
=xy                                Abs  179470 #0002BD0E -  3629
=xz                                Abs  179491 #0002BD23 -  3630
=xz0                               Abs  180121 #0002BF99 -  3631
=xz1                               Abs  180144 #0002BFB0 -  3632
=xz2                               Abs  180167 #0002BFC7 -  3633
=xz3                               Abs  180190 #0002BFDE -  3634
=xz4                               Abs  180213 #0002BFF5 -  3635
=xz5                               Abs  180236 #0002C00C -  3636
=xz6                               Abs  180259 #0002C023 -  3637
=xz7                               Abs  180282 #0002C03A -  3638
=xz8                               Abs  180305 #0002C051 -  3639
=xz9                               Abs  180328 #0002C068 -  3640
={NoteText}                        Abs  260347 #0003F8FB -  3641
={NumVars}                         Abs  260355 #0003F903 -  3642
={SketchSet}                       Abs  260352 #0003F900 -  3643
={StatVars}                        Abs  260354 #0003F902 -  3644
={}N                               Abs   23570 #00005C12 -  3645  6637  6727
=~*ord                             Abs  409771 #000640AB -  3646
=~*spec                            Abs  405675 #000630AB -  3647
=~*xH                              Abs  299012 #00049004 -  3648
=~*xW                              Abs  303108 #0004A004 -  3649
=~::args                           Abs   24808 #000060E8 -  3650
=~?NULLSETDIM                      Abs   78056 #000130E8 -  3651
=~ALSKey1.1                        Abs     165 #000000A5 -  3652
=~ALSKey1.2                        Abs    4261 #000010A5 -  3653
=~ALSKey1.3                        Abs    8357 #000020A5 -  3654
=~ALSKey1.4                        Abs   12453 #000030A5 -  3655
=~ALSKey1.5                        Abs   16549 #000040A5 -  3656
=~ALSKey1.6                        Abs   20645 #000050A5 -  3657
=~ALSKey2.1                        Abs   24741 #000060A5 -  3658
=~ALSKey2.2                        Abs   28837 #000070A5 -  3659
=~ALSKey2.3                        Abs   32933 #000080A5 -  3660
=~ALSKey2.4                        Abs   37029 #000090A5 -  3661
=~ALSKey3.1                        Abs   41125 #0000A0A5 -  3662
=~ALSKey3.2                        Abs   45221 #0000B0A5 -  3663
=~ALSKey3.3                        Abs   49317 #0000C0A5 -  3664
=~ALSKey3.4                        Abs   53413 #0000D0A5 -  3665
=~ALSKey3.5                        Abs   57509 #0000E0A5 -  3666
=~ALSKey3.6                        Abs   61605 #0000F0A5 -  3667
=~ALSKey4.1                        Abs   65701 #000100A5 -  3668
=~ALSKey4.2                        Abs   69797 #000110A5 -  3669
=~ALSKey4.3                        Abs   73893 #000120A5 -  3670
=~ALSKey4.4                        Abs   77989 #000130A5 -  3671
=~ALSKey4.5                        Abs   82085 #000140A5 -  3672
=~ALSKey5.1                        Abs   86181 #000150A5 -  3673
=~ALSKey5.2                        Abs   90277 #000160A5 -  3674
=~ALSKey5.3                        Abs   94373 #000170A5 -  3675
=~ALSKey5.4                        Abs   98469 #000180A5 -  3676
=~ALSKey5.5                        Abs  102565 #000190A5 -  3677
=~ALSKey6.1                        Abs  106661 #0001A0A5 -  3678
=~ALSKey6.2                        Abs  110757 #0001B0A5 -  3679
=~ALSKey6.3                        Abs  114853 #0001C0A5 -  3680
=~ALSKey6.4                        Abs  118949 #0001D0A5 -  3681
=~ALSKey6.5                        Abs  123045 #0001E0A5 -  3682
=~ALSKey7.1                        Abs  127141 #0001F0A5 -  3683
=~ALSKey7.2                        Abs  131237 #000200A5 -  3684
=~ALSKey7.3                        Abs  135333 #000210A5 -  3685
=~ALSKey7.4                        Abs  139429 #000220A5 -  3686
=~ALSKey7.5                        Abs  143525 #000230A5 -  3687
=~ALSKey8.1                        Abs  147621 #000240A5 -  3688
=~ALSKey8.2                        Abs  151717 #000250A5 -  3689
=~ALSKey8.3                        Abs  155813 #000260A5 -  3690
=~ALSKey8.4                        Abs  159909 #000270A5 -  3691
=~ALSKey8.5                        Abs  164005 #000280A5 -  3692
=~ALSKey9.1                        Abs  168101 #000290A5 -  3693
=~ALSKey9.2                        Abs  172197 #0002A0A5 -  3694
=~ALSKey9.3                        Abs  176293 #0002B0A5 -  3695
=~ALSKey9.4                        Abs  180389 #0002C0A5 -  3696
=~ALSKey9.5                        Abs  184485 #0002D0A5 -  3697
=~ANSKey1.1                        Abs     164 #000000A4 -  3698
=~ANSKey1.2                        Abs    4260 #000010A4 -  3699
=~ANSKey1.3                        Abs    8356 #000020A4 -  3700
=~ANSKey1.4                        Abs   12452 #000030A4 -  3701
=~ANSKey1.5                        Abs   16548 #000040A4 -  3702
=~ANSKey1.6                        Abs   20644 #000050A4 -  3703
=~ANSKey2.1                        Abs   24740 #000060A4 -  3704
=~ANSKey2.2                        Abs   28836 #000070A4 -  3705
=~ANSKey2.3                        Abs   32932 #000080A4 -  3706
=~ANSKey2.4                        Abs   37028 #000090A4 -  3707
=~ANSKey3.1                        Abs   41124 #0000A0A4 -  3708
=~ANSKey3.2                        Abs   45220 #0000B0A4 -  3709
=~ANSKey3.3                        Abs   49316 #0000C0A4 -  3710
=~ANSKey3.4                        Abs   53412 #0000D0A4 -  3711
=~ANSKey3.5                        Abs   57508 #0000E0A4 -  3712
=~ANSKey3.6                        Abs   61604 #0000F0A4 -  3713
=~ANSKey4.1                        Abs   65700 #000100A4 -  3714
=~ANSKey4.2                        Abs   69796 #000110A4 -  3715
=~ANSKey4.3                        Abs   73892 #000120A4 -  3716
=~ANSKey4.4                        Abs   77988 #000130A4 -  3717
=~ANSKey4.5                        Abs   82084 #000140A4 -  3718
=~ANSKey5.1                        Abs   86180 #000150A4 -  3719
=~ANSKey5.2                        Abs   90276 #000160A4 -  3720
=~ANSKey5.3                        Abs   94372 #000170A4 -  3721
=~ANSKey5.4                        Abs   98468 #000180A4 -  3722
=~ANSKey5.5                        Abs  102564 #000190A4 -  3723
=~ANSKey6.1                        Abs  106660 #0001A0A4 -  3724
=~ANSKey6.2                        Abs  110756 #0001B0A4 -  3725
=~ANSKey6.3                        Abs  114852 #0001C0A4 -  3726
=~ANSKey6.4                        Abs  118948 #0001D0A4 -  3727
=~ANSKey6.5                        Abs  123044 #0001E0A4 -  3728
=~ANSKey7.1                        Abs  127140 #0001F0A4 -  3729
=~ANSKey7.2                        Abs  131236 #000200A4 -  3730
=~ANSKey7.3                        Abs  135332 #000210A4 -  3731
=~ANSKey7.4                        Abs  139428 #000220A4 -  3732
=~ANSKey7.5                        Abs  143524 #000230A4 -  3733
=~ANSKey8.1                        Abs  147620 #000240A4 -  3734
=~ANSKey8.2                        Abs  151716 #000250A4 -  3735
=~ANSKey8.3                        Abs  155812 #000260A4 -  3736
=~ANSKey8.4                        Abs  159908 #000270A4 -  3737
=~ANSKey8.5                        Abs  164004 #000280A4 -  3738
=~ANSKey9.1                        Abs  168100 #000290A4 -  3739
=~ANSKey9.2                        Abs  172196 #0002A0A4 -  3740
=~ANSKey9.3                        Abs  176292 #0002B0A4 -  3741
=~ANSKey9.4                        Abs  180388 #0002C0A4 -  3742
=~ANSKey9.5                        Abs  184484 #0002D0A4 -  3743
=~AttentionKe                      Abs  188577 #0002E0A1 -  3744
=~CHECKEXISTS                      Abs  536816 #000830F0 -  3745
=~CLRTOPICLAM                      Abs  155889 #000260F1 -  3746
=~COLCTDER                         Abs  585968 #0008F0F0 -  3747
=~COLCTFCNAP                       Abs  606448 #000940F0 -  3748
=~COLCTIFTE                        Abs  598256 #000920F0 -  3749
=~COLCTINTG                        Abs  590064 #000900F0 -  3750
=~COLCTQUOTE                       Abs  602352 #000930F0 -  3751
=~COLCTSUM                         Abs  594160 #000910F0 -  3752
=~COMPLEXDUMM                      Abs  536578 #00083002 -  3753
=~ChkDaList                        Abs  360619 #000580AB -  3754
=~DArrow                           Abs   57505 #0000E0A1 -  3755
=~DefauStat2T                      Abs  135409 #000210F1 -  3756
=~DefauStatTy                      Abs  131313 #000200F1 -  3757
=~DoExponent                       Abs  209058 #000330A2 -  3758
=~DoMenuKey1N                      Abs     161 #000000A1 -  3759
=~DoMenuKey2N                      Abs    4257 #000010A1 -  3760
=~DoMenuKey3N                      Abs    8353 #000020A1 -  3761
=~DoMenuKey4N                      Abs   12449 #000030A1 -  3762
=~DoMenuKey5N                      Abs   16545 #000040A1 -  3763
=~DoMenuKey6N                      Abs   20641 #000050A1 -  3764
=~DoNumeric:                       Abs  127208 #0001F0E8 -  3765
=~Enter/Again                      Abs  204961 #000320A1 -  3766
=~FarDArrow                        Abs   57506 #0000E0A2 -  3767
=~FarLArrow                        Abs   53410 #0000D0A2 -  3768
=~FarRArrow                        Abs   61602 #0000F0A2 -  3769
=~FarUArrow                        Abs   37026 #000090A2 -  3770
=~GETPLTLABLS                      Abs  159985 #000270F1 -  3771
=~GetTypeText                      Abs  127217 #0001F0F1 -  3772
=~I:-InvSin                        Abs    4336 #000010F0 -  3773
=~I:-InvSinh                       Abs   37104 #000090F0 -  3774
=~I:Acosh                          Abs   94448 #000170F0 -  3775
=~I:Asinh                          Abs   90352 #000160F0 -  3776
=~I:Atan                           Abs   78064 #000130F0 -  3777
=~I:LnTan                          Abs   12528 #000030F0 -  3778
=~I:LnTanh                         Abs   41200 #0000A0F0 -  3779
=~I:Tanh                           Abs   49392 #0000C0F0 -  3780
=~INTEMPOB?                        Abs  139496 #000220E8 -  3781
=~INTGACOS                         Abs   24816 #000060F0 -  3782
=~INTGALOG                         Abs   61680 #0000F0F0 -  3783
=~INTGASIN                         Abs   20720 #000050F0 -  3784
=~INTGATAN                         Abs   28912 #000070F0 -  3785
=~INTGCOS                          Abs    8432 #000020F0 -  3786
=~INTGCOSH                         Abs   45296 #0000B0F0 -  3787
=~INTGDER                          Abs  102640 #000190F0 -  3788
=~INTGEXPM                         Abs   57584 #0000E0F0 -  3789
=~INTGINV                          Abs   73968 #000120F0 -  3790
=~INTGLN                           Abs   65776 #000100F0 -  3791
=~INTGLOG                          Abs   69872 #000110F0 -  3792
=~INTGSIGN                         Abs   98544 #000180F0 -  3793
=~INTGSIN                          Abs     240 #000000F0 -  3794
=~INTGSINH                         Abs   33008 #000080F0 -  3795
=~INTGSQ                           Abs   82160 #000140F0 -  3796
=~INTGSQRT                         Abs   86256 #000150F0 -  3797
=~INTGTAN                          Abs   16624 #000040F0 -  3798
=~INTGTANH                         Abs   53488 #0000D0F0 -  3799
=~LArrow                           Abs   53409 #0000D0A1 -  3800
=~LIXRecv                          Abs  196840 #000300E8 -  3801
=~LIXSend                          Abs  200936 #000310E8 -  3802
=~LSKey1.1                         Abs     162 #000000A2 -  3803
=~LSKey1.2                         Abs    4258 #000010A2 -  3804
=~LSKey1.3                         Abs    8354 #000020A2 -  3805
=~LSKey1.4                         Abs   12450 #000030A2 -  3806
=~LSKey1.5                         Abs   16546 #000040A2 -  3807
=~LSKey1.6                         Abs   20642 #000050A2 -  3808
=~LSKey2.1                         Abs   24738 #000060A2 -  3809
=~LSKey2.2                         Abs   28834 #000070A2 -  3810
=~LSKey2.3                         Abs   32930 #000080A2 -  3811
=~LSKey3.1                         Abs   41122 #0000A0A2 -  3812
=~LSKey3.2                         Abs   45218 #0000B0A2 -  3813
=~LSKey3.3                         Abs   49314 #0000C0A2 -  3814
=~LSKey4.1                         Abs   65698 #000100A2 -  3815
=~LSKey4.2                         Abs   69794 #000110A2 -  3816
=~LSKey4.3                         Abs   73890 #000120A2 -  3817
=~LSKey4.4                         Abs   77986 #000130A2 -  3818
=~LSKey4.5                         Abs   82082 #000140A2 -  3819
=~LSKey5.1                         Abs   86178 #000150A2 -  3820
=~LSKey5.2                         Abs   90274 #000160A2 -  3821
=~LSKey5.4                         Abs   98466 #000180A2 -  3822
=~LSKey5.5                         Abs  102562 #000190A2 -  3823
=~LSKey6.1                         Abs  106658 #0001A0A2 -  3824
=~LSKey6.2                         Abs  110754 #0001B0A2 -  3825
=~LSKey6.3                         Abs  114850 #0001C0A2 -  3826
=~LSKey6.4                         Abs  118946 #0001D0A2 -  3827
=~LSKey6.5                         Abs  123042 #0001E0A2 -  3828
=~LSKey7.1                         Abs  127138 #0001F0A2 -  3829
=~LSKey7.2                         Abs  131234 #000200A2 -  3830
=~LSKey7.3                         Abs  135330 #000210A2 -  3831
=~LSKey7.4                         Abs  139426 #000220A2 -  3832
=~LSKey7.5                         Abs  143522 #000230A2 -  3833
=~LSKey8.1                         Abs  147618 #000240A2 -  3834
=~LSKey8.2                         Abs  151714 #000250A2 -  3835
=~LSKey8.3                         Abs  155810 #000260A2 -  3836
=~LSKey8.4                         Abs  159906 #000270A2 -  3837
=~LSKey8.5                         Abs  164002 #000280A2 -  3838
=~LSKey9.1                         Abs  168098 #000290A2 -  3839
=~LSKey9.2                         Abs  172194 #0002A0A2 -  3840
=~LSKey9.3                         Abs  176290 #0002B0A2 -  3841
=~LSKey9.4                         Abs  180386 #0002C0A2 -  3842
=~LSKey9.5                         Abs  184482 #0002D0A2 -  3843
=~MAKEEPIDN                        Abs  209090 #000330C2 -  3844
=~MiscIFMsg                        Abs     185 #000000B9 -  3845
=~NSKey3.2                         Abs   45217 #0000B0A1 -  3846
=~NSKey3.3                         Abs   49313 #0000C0A1 -  3847
=~NSKey4.1                         Abs   65697 #000100A1 -  3848
=~NSKey4.2                         Abs   69793 #000110A1 -  3849
=~NSKey4.3                         Abs   73889 #000120A1 -  3850
=~NSKey4.4                         Abs   77985 #000130A1 -  3851
=~NSKey4.5                         Abs   82081 #000140A1 -  3852
=~NSKey5.2                         Abs   90273 #000160A1 -  3853
=~NSKey5.3                         Abs   94369 #000170A1 -  3854
=~NSKey5.4                         Abs   98465 #000180A1 -  3855
=~NSKey5.5                         Abs  102561 #000190A1 -  3856
=~NSKey6.1                         Abs  106657 #0001A0A1 -  3857
=~NSKey6.2                         Abs  110753 #0001B0A1 -  3858
=~NSKey6.3                         Abs  114849 #0001C0A1 -  3859
=~NSKey6.4                         Abs  118945 #0001D0A1 -  3860
=~NSKey6.5                         Abs  123041 #0001E0A1 -  3861
=~NSKey7.1                         Abs  127137 #0001F0A1 -  3862
=~NSKey7.2                         Abs  131233 #000200A1 -  3863
=~NSKey7.3                         Abs  135329 #000210A1 -  3864
=~NSKey7.4                         Abs  139425 #000220A1 -  3865
=~NSKey7.5                         Abs  143521 #000230A1 -  3866
=~NSKey8.1                         Abs  147617 #000240A1 -  3867
=~NSKey8.2                         Abs  151713 #000250A1 -  3868
=~NSKey8.3                         Abs  155809 #000260A1 -  3869
=~NSKey8.4                         Abs  159905 #000270A1 -  3870
=~NSKey8.5                         Abs  164001 #000280A1 -  3871
=~NSKey9.2                         Abs  172193 #0002A0A1 -  3872
=~NSKey9.3                         Abs  176289 #0002B0A1 -  3873
=~NSKey9.4                         Abs  180385 #0002C0A1 -  3874
=~NSKey9.5                         Abs  184481 #0002D0A1 -  3875
=~NotHidden                        Abs  135400 #000210E8 -  3876
=~NullMenuKey                      Abs 1241330 #0012F0F2 -  3877
=~POINTERR                         Abs  164081 #000280F1 -  3878
=~POINTEXIT                        Abs  168177 #000290F1 -  3879
=~POLARDUMMY                       Abs  540674 #00084002 -  3880
=~PlotIFMsg                        Abs     190 #000000BE -  3881
=~PlotViewKey                      Abs  209057 #000330A1 -  3882
=~PolyNSymbF                       Abs   32960 #000080C0 -  3883
=~PolyNSymbP                       Abs   28864 #000070C0 -  3884
=~RArrow                           Abs   61601 #0000F0A1 -  3885
=~REIM[]*                          Abs  401648 #000620F0 -  3886
=~SETTOPICLAM                      Abs  151793 #000250F1 -  3887
=~SolveApEntr                      Abs  147697 #000240F1 -  3888
=~SolveIFMsg                       Abs     191 #000000BF -  3889
=~StatIFMsg                        Abs     187 #000000BB -  3890
=~StdApEntry                       Abs  143601 #000230F1 -  3891
=~SymbViewKey                      Abs  213153 #000340A1 -  3892
=~TableViewKe                      Abs  217249 #000350A1 -  3893
=~TopicLibKey                      Abs  221345 #000360A1 -  3894
=~UpArrow                          Abs   37025 #000090A1 -  3895
=~UseHidden{}                      Abs  131304 #000200E8 -  3896
=~WHEREDER                         Abs  491760 #000780F0 -  3897
=~WHEREFCNAPP                      Abs  487664 #000770F0 -  3898
=~WHEREIFTE                        Abs  495856 #000790F0 -  3899
=~WHEREINTG                        Abs  508144 #0007C0F0 -  3900
=~WHERESUM                         Abs  512240 #0007D0F0 -  3901
=~WHEREWHERE                       Abs  499952 #0007A0F0 -  3902
=~XEQDIAG>L                        Abs  307371 #0004B0AB -  3903
=~XEQDIAG>R                        Abs  311467 #0004C0AB -  3904
=~XEQRANM                          Abs  315563 #0004D0AB -  3905
=~XEQSYMLIN                        Abs  241835 #0003B0AB -  3906
=~XEQXDPTCH                        Abs  528624 #000810F0 -  3907
=~XEVALp*                          Abs  565488 #0008A0F0 -  3908
=~XEVALp?                          Abs  561392 #000890F0 -  3909
=~XPURGEp*                         Abs  573680 #0008C0F0 -  3910
=~XPURGEp?                         Abs  569584 #0008B0F0 -  3911
=~XRCLp*                           Abs  557296 #000880F0 -  3912
=~XRCLp?                           Abs  545008 #000850F0 -  3913
=~XRCLp?acc>                       Abs  581872 #0008E0F0 -  3914
=~XRCLpL                           Abs  553200 #000870F0 -  3915
=~XRCLpNL                          Abs  549104 #000860F0 -  3916
=~XSTOCHECK                        Abs  516336 #0007E0F0 -  3917
=~XSTOCHECK10                      Abs  520432 #0007F0F0 -  3918
=~Xcont                            Abs  532720 #000820F0 -  3919
=~adjdiv                           Abs  315632 #0004D0F0 -  3920
=~adjdivsign                       Abs  307440 #0004B0F0 -  3921
=~adjsign                          Abs  311536 #0004C0F0 -  3922
=~altFUNCTOPIC                     Abs    1789 #000006FD -  5970
=~altPARAMTOPIC                    Abs    9981 #000026FD -  5972
=~altPOLARTOPIC                    Abs    5885 #000016FD -  5971
=~altSEQTOPIC                      Abs   14077 #000036FD -  5973
=~altSOLVETOPIC                    Abs   22269 #000056FD -  5975
=~altSTATTOPIC                     Abs   18173 #000046FD -  5974
=~arryspec                         Abs  188648 #0002E0E8 -  3923
=~bad^                             Abs  430251 #000690AB -  3924
=~convertaddr                      Abs  577776 #0008D0F0 -  3925
=~copysub                          Abs  184552 #0002D0E8 -  3926
=~covD/D*                          Abs  610544 #000950F0 -  3927
=~covD/D+                          Abs  622832 #000980F0 -  3928
=~covD/D-                          Abs  626928 #000990F0 -  3929
=~covD/D/                          Abs  631024 #0009A0F0 -  3930
=~covD/D=                          Abs  635120 #0009B0F0 -  3931
=~covD/DABS                        Abs  643312 #0009D0F0 -  3932
=~covD/DACOS                       Abs  647408 #0009E0F0 -  3933
=~covD/DACOSH                      Abs  651504 #0009F0F0 -  3934
=~covD/DALOG                       Abs  655600 #000A00F0 -  3935
=~covD/DAPPLY                      Abs  766192 #000BB0F0 -  3936
=~covD/DARG                        Abs  659696 #000A10F0 -  3937
=~covD/DASIN                       Abs  663792 #000A20F0 -  3938
=~covD/DASINH                      Abs  667888 #000A30F0 -  3939
=~covD/DATAN                       Abs  671984 #000A40F0 -  3940
=~covD/DATANH                      Abs  676080 #000A50F0 -  3941
=~covD/DCOS                        Abs  680176 #000A60F0 -  3942
=~covD/DCOSH                       Abs  684272 #000A70F0 -  3943
=~covD/DCROSS                      Abs  614640 #000960F0 -  3944
=~covD/DDER                        Abs  749808 #000B70F0 -  3945
=~covD/DDOT                        Abs  618736 #000970F0 -  3946
=~covD/DEXP                        Abs  688368 #000A80F0 -  3947
=~covD/DIFTE                       Abs  708848 #000AD0F0 -  3948
=~covD/DINTG                       Abs  758000 #000B90F0 -  3949
=~covD/DINV                        Abs  692464 #000A90F0 -  3950
=~covD/DLN                         Abs  696560 #000AA0F0 -  3951
=~covD/DLNP1                       Abs  700656 #000AB0F0 -  3952
=~covD/DLOG                        Abs  704752 #000AC0F0 -  3953
=~covD/DSIN                        Abs  712944 #000AE0F0 -  3954
=~covD/DSINH                       Abs  717040 #000AF0F0 -  3955
=~covD/DSQ                         Abs  721136 #000B00F0 -  3956
=~covD/DSQRT                       Abs  725232 #000B10F0 -  3957
=~covD/DSUM                        Abs  762096 #000BA0F0 -  3958
=~covD/DTAN                        Abs  729328 #000B20F0 -  3959
=~covD/DTANH                       Abs  733424 #000B30F0 -  3960
=~covD/DWHERE                      Abs  753904 #000B80F0 -  3961
=~covD/D^                          Abs  737520 #000B40F0 -  3962
=~covD/D^X                         Abs  741616 #000B50F0 -  3963
=~covD/D^Y                         Abs  745712 #000B60F0 -  3964
=~covD/Dalg=                       Abs  639216 #0009C0F0 -  3965
=~covINV*                          Abs  823536 #000C90F0 -  3966
=~covINV+                          Abs  811248 #000C60F0 -  3967
=~covINV-                          Abs  815344 #000C70F0 -  3968
=~covINV/                          Abs  827632 #000CA0F0 -  3969
=~covINV=                          Abs  819440 #000C80F0 -  3970
=~covINVALOG                       Abs  868592 #000D40F0 -  3971
=~covINVCOS                        Abs  848112 #000CF0F0 -  3972
=~covINVCOSH                       Abs  860400 #000D20F0 -  3973
=~covINVEXP                        Abs  839920 #000CD0F0 -  3974
=~covINVEXPM1                      Abs  872688 #000D50F0 -  3975
=~covINVSIN                        Abs  844016 #000CE0F0 -  3976
=~covINVSINH                       Abs  856304 #000D10F0 -  3977
=~covINVTAN                        Abs  852208 #000D00F0 -  3978
=~covINVTANH                       Abs  864496 #000D30F0 -  3979
=~covINV^                          Abs  831728 #000CB0F0 -  3980
=~covINV^X                         Abs  835824 #000CC0F0 -  3981
=~covLBSTO                         Abs  524528 #000800F0 -  3982
=~covMANATG                        Abs  807152 #000C50F0 -  3983
=~covMANCSIV                       Abs  790768 #000C10F0 -  3984
=~covMANEXP                        Abs  782576 #000BF0F0 -  3985
=~covMANMENU*                      Abs  774384 #000BD0F0 -  3986
=~covMANMENU+                      Abs  770288 #000BC0F0 -  3987
=~covMANMENUC                      Abs  798960 #000C30F0 -  3988
=~covMANMENUE                      Abs  794864 #000C20F0 -  3989
=~covMANMENUL                      Abs  786672 #000C00F0 -  3990
=~covMANMENU^                      Abs  778480 #000BE0F0 -  3991
=~covMANTRG                        Abs  803056 #000C40F0 -  3992
=~covWSPLIT                        Abs  504048 #0007B0F0 -  3993
=~covmanCOL                        Abs  483568 #000760F0 -  3994
=~covmetaLIBS                      Abs  540912 #000840F0 -  3995
=~docmdlist                        Abs   53480 #0000D0E8 -  3996
=~doidseqn                         Abs   16616 #000040E8 -  3997
=~dolatorre                        Abs   61672 #0000F0E8 -  3998
=~dolatorre+                       Abs   69864 #000110E8 -  3999
=~dolatorre2                       Abs   73960 #000120E8 -  4000
=~dolist+                          Abs  102632 #000190E8 -  4001
=~dontuple                         Abs    8424 #000020E8 -  4002
=~dontuple#                        Abs   12520 #000030E8 -  4003
=~dopcoeff                         Abs  381099 #0005D0AB -  4004
=~dopolydiv                        Abs  377003 #0005C0AB -  4005
=~dopolyz                          Abs  372907 #0005B0AB -  4006
=~doptrseqn                        Abs   41192 #0000A0E8 -  4007
=~dopval                           Abs  438443 #0006B0AB -  4008
=~dosecntuple                      Abs    4328 #000010E8 -  4009
=~dosecseqn                        Abs   33000 #000080E8 -  4010
=~doseq                            Abs     232 #000000E8 -  4011
=~doseqn                           Abs   45288 #0000B0E8 -  4012
=~doseqn#                          Abs   49384 #0000C0E8 -  4013
=~dosort                           Abs  106728 #0001A0E8 -  4014
=~elsielists?                      Abs   65768 #000100E8 -  4015
=~etorc                            Abs  192744 #0002F0E8 -  4016
=~idE0                             Abs 1114354 #001100F2 -  4017
=~idE1                             Abs 1077490 #001070F2 -  4018
=~idE2                             Abs 1081586 #001080F2 -  4019
=~idE3                             Abs 1085682 #001090F2 -  4020
=~idE4                             Abs 1089778 #0010A0F2 -  4021
=~idE5                             Abs 1093874 #0010B0F2 -  4022
=~idE6                             Abs 1097970 #0010C0F2 -  4023
=~idE7                             Abs 1102066 #0010D0F2 -  4024
=~idE8                             Abs 1106162 #0010E0F2 -  4025
=~idE9                             Abs 1110258 #0010F0F2 -  4026
=~idF0                             Abs  159986 #000270F2 -  4027
=~idF1                             Abs   86258 #000150F2 -  4028
=~idF2                             Abs   94450 #000170F2 -  4029
=~idF3                             Abs  102642 #000190F2 -  4030
=~idF4                             Abs  110834 #0001B0F2 -  4031
=~idF5                             Abs  119026 #0001D0F2 -  4032
=~idF6                             Abs  127218 #0001F0F2 -  4033
=~idF7                             Abs  135410 #000210F2 -  4034
=~idF8                             Abs  143602 #000230F2 -  4035
=~idF9                             Abs  151794 #000250F2 -  4036
=~idR0                             Abs  405746 #000630F2 -  4037
=~idR1                             Abs  332018 #000510F2 -  4038
=~idR2                             Abs  340210 #000530F2 -  4039
=~idR3                             Abs  348402 #000550F2 -  4040
=~idR4                             Abs  356594 #000570F2 -  4041
=~idR5                             Abs  364786 #000590F2 -  4042
=~idR6                             Abs  372978 #0005B0F2 -  4043
=~idR7                             Abs  381170 #0005D0F2 -  4044
=~idR8                             Abs  389362 #0005F0F2 -  4045
=~idR9                             Abs  397554 #000610F2 -  4046
=~idU0                             Abs   78066 #000130F2 -  4047
=~idU1                             Abs    4338 #000010F2 -  4048
=~idU2                             Abs   12530 #000030F2 -  4049
=~idU3                             Abs   20722 #000050F2 -  4050
=~idU4                             Abs   28914 #000070F2 -  4051
=~idU5                             Abs   37106 #000090F2 -  4052
=~idU6                             Abs   45298 #0000B0F2 -  4053
=~idU7                             Abs   53490 #0000D0F2 -  4054
=~idU8                             Abs   61682 #0000F0F2 -  4055
=~idU9                             Abs   69874 #000110F2 -  4056
=~idX0                             Abs  315634 #0004D0F2 -  4057
=~idX1                             Abs  168178 #000290F2 -  4058
=~idX2                             Abs  184562 #0002D0F2 -  4059
=~idX3                             Abs  200946 #000310F2 -  4060
=~idX4                             Abs  217330 #000350F2 -  4061
=~idX5                             Abs  233714 #000390F2 -  4062
=~idX6                             Abs  250098 #0003D0F2 -  4063
=~idX7                             Abs  266482 #000410F2 -  4064
=~idX8                             Abs  282866 #000450F2 -  4065
=~idX9                             Abs  299250 #000490F2 -  4066
=~idY0                             Abs  323826 #0004F0F2 -  4067
=~idY1                             Abs  176370 #0002B0F2 -  4068
=~idY2                             Abs  192754 #0002F0F2 -  4069
=~idY3                             Abs  209138 #000330F2 -  4070
=~idY4                             Abs  225522 #000370F2 -  4071
=~idY5                             Abs  241906 #0003B0F2 -  4072
=~idY6                             Abs  258290 #0003F0F2 -  4073
=~idY7                             Abs  274674 #000430F2 -  4074
=~idY8                             Abs  291058 #000470F2 -  4075
=~idY9                             Abs  307442 #0004B0F2 -  4076
=~la+COL                           Abs   53443 #0000D0C3 -  4077
=~la+COLs                          Abs   57539 #0000E0C3 -  4078
=~la+ELEM                          Abs   69827 #000110C3 -  4079
=~la+ELEMc                         Abs   65731 #000100C3 -  4080
=~la+ELEMr                         Abs   61635 #0000F0C3 -  4081
=~la+RCsLP                         Abs   49347 #0000C0C3 -  4082
=~la+ROW                           Abs   41155 #0000A0C3 -  4083
=~la+ROWs                          Abs   45251 #0000B0C3 -  4084
=~la-COL                           Abs   37059 #000090C3 -  4085
=~la-ROW                           Abs   28867 #000070C3 -  4086
=~la>COL                           Abs   82115 #000140C3 -  4087
=~la>DIAG                          Abs   94403 #000170C3 -  4088
=~la>ELEM                          Abs   78019 #000130C3 -  4089
=~la>ROW                           Abs   73923 #000120C3 -  4090
=~laBPMUTE                         Abs  131266 #000200C2 -  4091
=~laCOL>                           Abs   90307 #000160C3 -  4092
=~laCOND                           Abs  315586 #0004D0C2 -  4093
=~laCONDdone                       Abs  319682 #0004E0C2 -  4094
=~laCSWP                           Abs   16579 #000040C3 -  4095
=~laDELROW                         Abs  102595 #000190C3 -  4096
=~laDIAG>                          Abs   98499 #000180C3 -  4097
=~laDT                             Abs  331970 #000510C2 -  4098
=~laECQhQAQh                       Abs   28866 #000070C2 -  4099
=~laEGV                            Abs   16578 #000040C2 -  4100
=~laEGVL                           Abs    8386 #000020C2 -  4101
=~laEGVL%%                         Abs   12482 #000030C2 -  4102
=~laEGetTiny                       Abs  385218 #0005E0C2 -  4103
=~laEgCQRI                         Abs  110786 #0001B0C2 -  4104
=~laEgCQRIk1                       Abs  114882 #0001C0C2 -  4105
=~laEgCSchur                       Abs  106690 #0001A0C2 -  4106
=~laEgHF                           Abs   24770 #000060C2 -  4107
=~laEgIsoVal                       Abs   41154 #0000A0C2 -  4108
=~laEgM*G2                         Abs   69826 #000110C2 -  4109
=~laEgM*RG3                        Abs   61634 #0000F0C2 -  4110
=~laEgPrep                         Abs  123074 #0001E0C2 -  4111
=~laEgQRIk0                        Abs   49346 #0000C0C2 -  4112
=~laEgQkHA                         Abs   32962 #000080C2 -  4113
=~laEgRQRI                         Abs   45250 #0000B0C2 -  4114
=~laEgRQRIk1                       Abs   53442 #0000D0C2 -  4115
=~laEgRSchur                       Abs   37058 #000090C2 -  4116
=~laEgRWilk3                       Abs   57538 #0000E0C2 -  4117
=~laEgRotR                         Abs   78018 #000130C2 -  4118
=~laEgSclCls                       Abs  102594 #000190C2 -  4119
=~laEgValr                         Abs   73922 #000120C2 -  4120
=~laEgVcPair                       Abs   98498 #000180C2 -  4121
=~laEgVcSngl                       Abs   90306 #000160C2 -  4122
=~laEgVcUrhs                       Abs   94402 #000170C2 -  4123
=~laEgVecC                         Abs  118978 #0001D0C2 -  4124
=~laEgVecR                         Abs   86210 #000150C2 -  4125
=~laEgWilk2                        Abs   65730 #000100C2 -  4126
=~laFPMUTE                         Abs  127170 #0001F0C2 -  4127
=~laFSCALE                         Abs  135362 #000210C2 -  4128
=~laGPROW                          Abs  110787 #0001B0C3 -  4129
=~laINSROW                         Abs  106691 #0001A0C3 -  4130
=~laIV                             Abs  348354 #000550C2 -  4131
=~laIVF                            Abs  356546 #000570C2 -  4132
=~laIVc                            Abs  352450 #000560C2 -  4133
=~laLSQ                            Abs  139458 #000220C2 -  4134
=~laLsdScale                       Abs  364738 #000590C2 -  4135
=~laQ2hX                           Abs  176322 #0002B0C2 -  4136
=~laQRF                            Abs  155842 #000260C2 -  4137
=~laQRSVecUp                       Abs  188610 #0002E0C2 -  4138
=~laQRmaxSV                        Abs  196802 #000300C2 -  4139
=~laQRminSV                        Abs  192706 #0002F0C2 -  4140
=~laQRrank                         Abs  184514 #0002D0C2 -  4141
=~laQhA                            Abs  159938 #000270C2 -  4142
=~laQhB                            Abs  164034 #000280C2 -  4143
=~laRANK                           Abs  221378 #000360C2 -  4144
=~laRANM                           Abs     195 #000000C3 -  4145
=~laRCI                            Abs   20675 #000050C3 -  4146
=~laRCIJ                           Abs   24771 #000060C3 -  4147
=~laROW>                           Abs   86211 #000150C3 -  4148
=~laRQF                            Abs  172226 #0002A0C2 -  4149
=~laRREF                           Abs  372930 #0005B0C2 -  4150
=~laRSVF                           Abs  180418 #0002C0C2 -  4151
=~laRSWP                           Abs    8387 #000020C3 -  4152
=~laRSWP2                          Abs   12483 #000030C3 -  4153
=~laRanInt                         Abs    4291 #000010C3 -  4154
=~laRedHere?                       Abs  381122 #0005D0C2 -  4155
=~laRedRow                         Abs  377026 #0005C0C2 -  4156
=~laRefineDT                       Abs  336066 #000520C2 -  4157
=~laSCHUR                          Abs   20674 #000050C2 -  4158
=~laSETDIAG                        Abs  168130 #000290C2 -  4159
=~laSNORM                          Abs  213186 #000340C2 -  4160
=~laSNORM%%                        Abs  217282 #000350C2 -  4161
=~laSRAD                           Abs     194 #000000C2 -  4162
=~laSV                             Abs  340162 #000530C2 -  4163
=~laSVD                            Abs  229570 #000380C2 -  4164
=~laSVL                            Abs  225474 #000370C2 -  4165
=~laSVc                            Abs  344258 #000540C2 -  4166
=~laScIntRnd                       Abs  368834 #0005A0C2 -  4167
=~laSchur2                         Abs   82114 #000140C2 -  4168
=~laSvdAPPhV                       Abs  245954 #0003C0C2 -  4169
=~laSvdAPk                         Abs  250050 #0003D0C2 -  4170
=~laSvdBDQR                        Abs  258242 #0003F0C2 -  4171
=~laSvdBDirC                       Abs  270530 #000420C2 -  4172
=~laSvdCROTL                       Abs  299202 #000490C2 -  4173
=~laSvdCROTR                       Abs  295106 #000480C2 -  4174
=~laSvdFDirC                       Abs  266434 #000410C2 -  4175
=~laSvdGPROT                       Abs  254146 #0003E0C2 -  4176
=~laSvdGShft                       Abs  274626 #000430C2 -  4177
=~laSvdLtUBD                       Abs  237762 #0003A0C2 -  4178
=~laSvdPSort                       Abs  303298 #0004A0C2 -  4179
=~laSvdPrep                        Abs  307394 #0004B0C2 -  4180
=~laSvdQR2x2                       Abs  262338 #000400C2 -  4181
=~laSvdQRB                         Abs  291010 #000470C2 -  4182
=~laSvdQRF                         Abs  286914 #000460C2 -  4183
=~laSvdQRSB                        Abs  282818 #000450C2 -  4184
=~laSvdQRSF                        Abs  278722 #000440C2 -  4185
=~laSvdUBD                         Abs  233666 #000390C2 -  4186
=~laSvdUQhQA                       Abs  241858 #0003B0C2 -  4187
=~laTRACE                          Abs  311490 #0004C0C2 -  4188
=~laULHSVF                         Abs  360642 #000580C2 -  4189
=~laUserLQ                         Abs  147650 #000240C2 -  4190
=~laUserLU                         Abs  327874 #000500C2 -  4191
=~laUserQR                         Abs  143554 #000230C2 -  4192
=~laVMAX%%                         Abs    4290 #000010C2 -  4193
=~laVMAXJRP                        Abs  323778 #0004F0C2 -  4194
=~laVec-                           Abs   32963 #000080C3 -  4195
=~lauserQR                         Abs  151746 #000250C2 -  4196
=~lolatorre                        Abs   90344 #000160E8 -  4197
=~lslatorre                        Abs   86248 #000150E8 -  4198
=~m->DEFACOS                       Abs  426224 #000680F0 -  4199
=~m->DEFACOSH                      Abs  450800 #0006E0F0 -  4200
=~m->DEFASIN                       Abs  422128 #000670F0 -  4201
=~m->DEFASINH                      Abs  446704 #0006D0F0 -  4202
=~m->DEFATAN                       Abs  430320 #000690F0 -  4203
=~m->DEFATANH                      Abs  454896 #0006F0F0 -  4204
=~m->DEFCOS                        Abs  413936 #000650F0 -  4205
=~m->DEFCOSH                       Abs  438512 #0006B0F0 -  4206
=~m->DEFSIN                        Abs  409840 #000640F0 -  4207
=~m->DEFSINH                       Abs  434416 #0006A0F0 -  4208
=~m->DEFTAN                        Abs  418032 #000660F0 -  4209
=~m->DEFTANH                       Abs  442608 #0006C0F0 -  4210
=~m->TRG                           Abs  405744 #000630F0 -  4211
=~m->[]<-*/                        Abs  385264 #0005E0F0 -  4212
=~m->[]<-+-                        Abs  381168 #0005D0F0 -  4213
=~m-[]*                            Abs  258288 #0003F0F0 -  4214
=~m-[]+                            Abs  266480 #000410F0 -  4215
=~m-[]-                            Abs  270576 #000420F0 -  4216
=~m-[]/                            Abs  262384 #000400F0 -  4217
=~m-[]L                            Abs  254192 #0003E0F0 -  4218
=~m1/[]*                           Abs  237808 #0003A0F0 -  4219
=~m1/[]/                           Abs  241904 #0003B0F0 -  4220
=~m1/[]E                           Abs  250096 #0003D0F0 -  4221
=~m1/[]^                           Abs  246000 #0003C0F0 -  4222
=~m<->*                            Abs  135408 #000210F0 -  4223
=~m<->+                            Abs  127216 #0001F0F0 -  4224
=~m<->-                            Abs  131312 #000200F0 -  4225
=~m<->/                            Abs  139504 #000220F0 -  4226
=~m<-A-+                           Abs  143600 #000230F0 -  4227
=~m<-A--                           Abs  147696 #000240F0 -  4228
=~m<-A/*                           Abs  151792 #000250F0 -  4229
=~m<-A//                           Abs  155888 #000260F0 -  4230
=~m<-A^*                           Abs  159984 #000270F0 -  4231
=~m<-M*E                           Abs  327920 #000500F0 -  4232
=~m<-M*^                           Abs  319728 #0004E0F0 -  4233
=~m<-M+*                           Abs  299248 #000490F0 -  4234
=~m<-M+L                           Abs  336112 #000520F0 -  4235
=~m<-M-*                           Abs  303344 #0004A0F0 -  4236
=~m<-M-L                           Abs  340208 #000530F0 -  4237
=~m<-M/E                           Abs  332016 #000510F0 -  4238
=~m<-M/^                           Abs  323824 #0004F0F0 -  4239
=~m<-T*/                           Abs  360688 #000580F0 -  4240
=~m<-T+-                           Abs  356592 #000570F0 -  4241
=~m<-T=                            Abs  110832 #0001B0F0 -  4242
=~m<-[*/                           Abs  368880 #0005A0F0 -  4243
=~m<-[+-                           Abs  364784 #000590F0 -  4244
=~m<T>*                            Abs  352496 #000560F0 -  4245
=~m<T>+                            Abs  348400 #000550F0 -  4246
=~mA->*/                           Abs  172272 #0002A0F0 -  4247
=~mA->+-                           Abs  164080 #000280F0 -  4248
=~mA->--                           Abs  168176 #000290F0 -  4249
=~mA->//                           Abs  176368 #0002B0F0 -  4250
=~mA->^^                           Abs  180464 #0002C0F0 -  4251
=~mAFlq                            Abs  114928 #0001C0F0 -  4252
=~mAFqq                            Abs  119024 #0001D0F0 -  4253
=~mAFrq                            Abs  123120 #0001E0F0 -  4254
=~mCONJ[]                          Abs  389360 #0005F0F0 -  4255
=~mCOS+                            Abs  463088 #000710F0 -  4256
=~mCOSH+                           Abs  475376 #000740F0 -  4257
=~mD->/+                           Abs  184560 #0002D0F0 -  4258
=~mD->/-                           Abs  188656 #0002E0F0 -  4259
=~mD->E+                           Abs  200944 #000310F0 -  4260
=~mD->E-                           Abs  205040 #000320F0 -  4261
=~mD->L*                           Abs  209136 #000330F0 -  4262
=~mD->L/                           Abs  213232 #000340F0 -  4263
=~mD->^+                           Abs  192752 #0002F0F0 -  4264
=~mD->^-                           Abs  196848 #000300F0 -  4265
=~mE[]^                            Abs  282864 #000450F0 -  4266
=~mE^*                             Abs  274672 #000430F0 -  4267
=~mE^/                             Abs  278768 #000440F0 -  4268
=~mIM[]                            Abs  397552 #000610F0 -  4269
=~mL*^                             Abs  286960 #000460F0 -  4270
=~mL[]*                            Abs  291056 #000470F0 -  4271
=~mL[]/                            Abs  295152 #000480F0 -  4272
=~mM->op                           Abs  344304 #000540F0 -  4273
=~mRE[]                            Abs  393456 #000600F0 -  4274
=~mSIN+                            Abs  458992 #000700F0 -  4275
=~mSINH+                           Abs  471280 #000730F0 -  4276
=~mT->=                            Abs  106736 #0001A0F0 -  4277
=~mTAN+                            Abs  467184 #000720F0 -  4278
=~mTANH+                           Abs  479472 #000750F0 -  4279
=~m[]CHS*                          Abs  217328 #000350F0 -  4280
=~m[]CHS/                          Abs  221424 #000360F0 -  4281
=~m[]CHSL                          Abs  225520 #000370F0 -  4282
=~m[]INVE                          Abs  233712 #000390F0 -  4283
=~m[]INV^                          Abs  229616 #000380F0 -  4284
=~m]->*/                           Abs  377072 #0005C0F0 -  4285
=~m]->+-                           Abs  372976 #0005B0F0 -  4286
=~metapolyz                        Abs  385195 #0005E0AB -  4287
=~morerepl                         Abs  147688 #000240E8 -  4288
=~moresub                          Abs  143592 #000230E8 -  4289
=~mrepll                           Abs  155880 #000260E8 -  4290
=~mrepll+                          Abs  159976 #000270E8 -  4291
=~mrepln                           Abs  151784 #000250E8 -  4292
=~msubll                           Abs  172264 #0002A0E8 -  4293
=~msubll+                          Abs  176360 #0002B0E8 -  4294
=~msubln                           Abs  164072 #000280E8 -  4295
=~msubnl                           Abs  168168 #000290E8 -  4296
=~msubnn                           Abs  180456 #0002C0E8 -  4297
=~nBOXWHISKER                      Abs   28913 #000070F1 -  4298
=~nFUNCTION                        Abs     241 #000000F1 -  4299
=~nFUNCTOPIC                       Abs   61681 #0000F0F1 -  4300
=~nHISTOGRAM                       Abs   20721 #000050F1 -  4301
=~nPARAMETRIC                      Abs   12529 #000030F1 -  4302
=~nPARAMTOPIC                      Abs   69873 #000110F1 -  4303
=~nPOLAR                           Abs    8433 #000020F1 -  4304
=~nPOLARTOPIC                      Abs   65777 #000100F1 -  4305
=~nPTYPE>PINF                      Abs  139505 #000220F1 -  4306
=~nSCATTER                         Abs   16625 #000040F1 -  4307
=~nSEQTOPIC                        Abs   73969 #000120F1 -  4308
=~nSEQUENCE                        Abs   24817 #000060F1 -  4309
=~nSOLVE                           Abs    4337 #000010F1 -  4310
=~nSOLVETOPIC                      Abs   82161 #000140F1 -  4311
=~nSTATTOPIC                       Abs   78065 #000130F1 -  4312
=~ns*spec                          Abs  417963 #000660AB -  4313
=~ollatorre                        Abs   94440 #000170E8 -  4314
=~ollatorre+                       Abs   98536 #000180E8 -  4315
=~pcoef                            Abs   16576 #000040C0 -  4316
=~pcoefacc1                        Abs   20672 #000050C0 -  4317
=~pcoefacc2                        Abs   24768 #000060C0 -  4318
=~pdiv                             Abs  442539 #0006C0AB -  4319
=~peval                            Abs   12480 #000030C0 -  4320
=~poly*                            Abs  401579 #000620AB -  4321
=~poly+                            Abs  393387 #000600AB -  4322
=~poly/                            Abs  450731 #0006E0AB -  4323
=~poly^                            Abs  426155 #000680AB -  4324
=~poly^#                           Abs  434347 #0006A0AB -  4325
=~polyneg                          Abs  397483 #000610AB -  4326
=~polyprep                         Abs  389291 #0005F0AB -  4327
=~preFACT                          Abs  172034 #0002A002 -  4328
=~proot                            Abs    4288 #000010C0 -  4329
=~proot_c                          Abs     192 #000000C0 -  4330
=~proot_r                          Abs    8384 #000020C0 -  4331
=~ptrargs                          Abs   28904 #000070E8 -  4332
=~rMAKEPCOPY                       Abs  200898 #000310C2 -  4333
=~rPACKARRYD                       Abs  204994 #000320C2 -  4334
=~resymb                           Abs  446635 #0006D0AB -  4335
=~rpnAPPLY                         Abs  528386 #00081002 -  4336
=~rpnDER                           Abs  516098 #0007E002 -  4337
=~rpnINTG                          Abs  520194 #0007F002 -  4338
=~rpnWHERE                         Abs  524290 #00080002 -  4339
=~rpnXROOT                         Abs  483330 #00076002 -  4340
=~runalias?                        Abs  172273 #0002A0F1 -  4341
=~seqid                            Abs   20712 #000050E8 -  4342
=~seqnargs                         Abs   57576 #0000E0E8 -  4343
=~sllatorre                        Abs   82152 #000140E8 -  4344
=~sn*spec                          Abs  413867 #000650AB -  4345
=~ss*spec                          Abs  422059 #000670AB -  4346
=~topic_CAPLE                      Abs  241905 #0003B0F1 -  4347
=~topic_CAPLET                     Abs  241905 #0003B0F1 -  5071  6033
=~topic_NONE                       Abs  213233 #000340F1 -  4348
=~udfargs                          Abs   37096 #000090E8 -  4349
=~view01_CAPL                      Abs  221425 #000360F1 -  4350
=~view01_CAPLET                    Abs  221425 #000360F1 -  5072  6035
=~view23_CAPL                      Abs  225521 #000370F1 -  4351
=~view23_CAPLET                    Abs  225521 #000370F1 -  5073  6037
=~view45_CAPL                      Abs  229617 #000380F1 -  4352
=~view45_CAPLET                    Abs  229617 #000380F1 -  5074  6039
=~view6_CAPLE                      Abs  233713 #000390F1 -  4353
=~view6_CAPLET                     Abs  233713 #000390F1 -  5075
=~view7_CAPLE                      Abs  237809 #0003A0F1 -  4354
=~view7_CAPLET                     Abs  237809 #0003A0F1 -  5076
=~view_NONE                        Abs  217329 #000350F1 -  4355
=~x#?                              Abs  401410 #00062002 -  4356
=~x%                               Abs  258050 #0003F002 -  4357
=~x%CH                             Abs  266242 #00041002 -  4358
=~x%T                              Abs  262146 #00040002 -  4359
=~x'                               Abs   59136 #0000E700 -  4360
=~x*                               Abs   53250 #0000D002 -  4361
=~x+                               Abs   40962 #0000A002 -  4362
=~x-                               Abs   49154 #0000C002 -  4363
=~x->Q                             Abs  544770 #00085002 -  4364
=~x->QPI                           Abs  548866 #00086002 -  4365
=~x->TAG                           Abs  565252 #0008A004 -  4366
=~x/                               Abs   57346 #0000E002 -  4367
=~x<                               Abs  282626 #00045002 -  4368
=~x<<                              Abs   50944 #0000C700 -  4369
=~x<=?                             Abs  405506 #00063002 -  4370
=~x=                               Abs    4098 #00001002 -  4371
=~x==                              Abs  290818 #00047002 -  4372
=~x>                               Abs  286722 #00046002 -  4373
=~x>=?                             Abs  409602 #00064002 -  4374
=~x>>                              Abs   55040 #0000D700 -  4375
=~x>ARRY                           Abs  241668 #0003B004 -  4376
=~x>COL                            Abs  258219 #0003F0AB -  4377
=~x>DIAG                           Abs  266411 #000410AB -  4378
=~x>DISPLAY                        Abs  397316 #00061004 -  4379
=~x>GROB                           Abs  413700 #00065004 -  4380
=~x>HMS                            Abs  229378 #00038002 -  4381
=~x>LIST                           Abs  184324 #0002D004 -  4382
=~x>NUM                            Abs  458754 #00070002 -  4383
=~x>PLOT                           Abs  405508 #00063004 -  4384
=~x>ROW                            Abs  250027 #0003D0AB -  4385
=~x>STR                            Abs  208900 #00033004 -  4386
=~x>UNIT                           Abs   94212 #00017004 -  4387
=~x>V2                             Abs  278532 #00044004 -  4388
=~x>V3                             Abs  282628 #00045004 -  4389
=~xABS                             Abs   12290 #00003002 -  4390
=~xACOS                            Abs  122882 #0001E002 -  4391
=~xACOSH                           Abs  135170 #00021002 -  4392
=~xACOT                            Abs  217259 #000350AB -  4393
=~xACSC                            Abs  221355 #000360AB -  4394
=~xALG->                           Abs   18176 #00004700 -  4395
=~xALOG                            Abs  155650 #00026002 -  4396
=~xAND                             Abs  385026 #0005E002 -  4397
=~xAPPLY                           Abs  339970 #00053002 -  4398
=~xARC                             Abs  417796 #00066004 -  4399
=~xARG                             Abs   77826 #00013002 -  4400
=~xARRY>                           Abs  245764 #0003C004 -  4401
=~xASEC                            Abs  225451 #000370AB -  4402
=~xASIN                            Abs  118786 #0001D002 -  4403
=~xASINH                           Abs  131074 #00020002 -  4404
=~xASN                             Abs  548868 #00086004 -  4405
=~xASR                             Abs   40964 #0000A004 -  4406
=~xATAN                            Abs  126978 #0001F002 -  4407
=~xATANH                           Abs  139266 #00022002 -  4408
=~xAUTO                            Abs  307204 #0004B004 -  4409
=~xAngle                           Abs  934130 #000E40F2 -  4410
=~xAns                             Abs  897266 #000DB0F2 -  4411
=~xArea                            Abs 1130738 #001140F2 -  4412
=~xAxes                            Abs  938226 #000E50F2 -  4413
=~xB>R                             Abs   81924 #00014004 -  4414
=~xBEEP                            Abs  454658 #0006F002 -  4415
=~xBLANK                           Abs  376836 #0005C004 -  4416
=~xBLANKGROB                       Abs  409604 #00064004 -  4417
=~xBOX                             Abs  372740 #0005B004 -  4418
=~xBOXW                            Abs  151723 #000250AB -  4419
=~xBYTES                           Abs  147460 #00024004 -  4420
=~xC>PX                            Abs  335876 #00052004 -  4421
=~xC>R                             Abs  204804 #00032004 -  4422
=~xCASE                            Abs   75520 #00012700 -  4423
=~xCEIL                            Abs  188418 #0002E002 -  4424
=~xCENTR                           Abs  294916 #00048004 -  4425
=~xCF                              Abs  155652 #00026004 -  4426
=~xCHECK                           Abs  251649 #0003D701 -  4427
=~xCHOOSE                          Abs  319659 #0004E0AB -  4428
=~xCHR                             Abs  221188 #00036004 -  4429
=~xCLEAR                           Abs  487428 #00077004 -  4430
=~xCLKADJ                          Abs  126980 #0001F004 -  4431
=~xCLLCD                           Abs  471042 #00073002 -  4432
=~xCNRM                            Abs  241666 #0003B002 -  4433
=~xCOBWEB                          Abs  143531 #000230AB -  4434
=~xCOL+                            Abs  286891 #000460AB -  4435
=~xCOL-                            Abs  282795 #000450AB -  4436
=~xCOL>                            Abs  262315 #000400AB -  4437
=~xCOLCT                           Abs  565250 #0008A002 -  4438
=~xCOMB                            Abs  274434 #00043002 -  4439
=~xCON                             Abs  253956 #0003E004 -  4440
=~xCONCAT                          Abs   94379 #000170AB -  4441
=~xCOND                            Abs    4267 #000010AB -  4442
=~xCONJ                            Abs   16386 #00004002 -  4443
=~xCONSTANTe                       Abs   32770 #00008002 -  4444
=~xCONT                            Abs  479234 #00075002 -  4445
=~xCONVERT                         Abs   86020 #00015004 -  4446
=~xCORR                            Abs  721138 #000B00F2 -  4447
=~xCOS                             Abs   98306 #00018002 -  4448
=~xCOSH                            Abs  110594 #0001B002 -  4449
=~xCOT                             Abs  204971 #000320AB -  4450
=~xCOV                             Abs  725234 #000B10F2 -  4451
=~xCROSS                           Abs  253954 #0003E002 -  4452
=~xCSC                             Abs  213163 #000340AB -  4453
=~xCSWP                            Abs  295083 #000480AB -  4454
=~xCUBICFIT                        Abs  176299 #0002B0AB -  4455
=~xConnect                         Abs  946418 #000E70F2 -  4456
=~xCoord                           Abs  975090 #000EE0F2 -  4457
=~xD0                              Abs  446706 #0006D0F2 -  4458
=~xD1                              Abs  409842 #000640F2 -  4459
=~xD2                              Abs  413938 #000650F2 -  4460
=~xD3                              Abs  418034 #000660F2 -  4461
=~xD4                              Abs  422130 #000670F2 -  4462
=~xD5                              Abs  426226 #000680F2 -  4463
=~xD6                              Abs  430322 #000690F2 -  4464
=~xD7                              Abs  434418 #0006A0F2 -  4465
=~xD8                              Abs  438514 #0006B0F2 -  4466
=~xD9                              Abs  442610 #0006C0F2 -  4467
=~xD>R                             Abs  221186 #00036002 -  4468
=~xDATE                            Abs  110596 #0001B004 -  4469
=~xDATE+                           Abs  139268 #00022004 -  4470
=~xDDAYS                           Abs  135172 #00021004 -  4471
=~xDECR                            Abs  524292 #00080004 -  4472
=~xDELKEYS                         Abs  557060 #00088004 -  4473
=~xDEPTH                           Abs  462852 #00071004 -  4474
=~xDER                             Abs  315394 #0004D002 -  4475
=~xDET                             Abs  245762 #0003C002 -  4476
=~xDFLTNOTE                        Abs  205041 #000320F1 -  4477
=~xDFLTPICT                        Abs  209137 #000330F1 -  4478
=~xDIAG>                           Abs  270507 #000420AB -  4479
=~xDIR                             Abs   83712 #00014700 -  4480
=~xDISP                            Abs  450562 #0006E002 -  4481
=~xDISPLAY>                        Abs  393220 #00060004 -  4482
=~xDO                              Abs   30464 #00007700 -  4483
=~xDOERR                           Abs  421890 #00067002 -  4484
=~xDOLIST                          Abs  364715 #000590AB -  4485
=~xDOSUBS                          Abs  344235 #000540AB -  4486
=~xDOT                             Abs  249858 #0003D002 -  4487
=~xDRAX                            Abs  311300 #0004C004 -  4488
=~xDROP                            Abs  446468 #0006D004 -  4489
=~xDROP2                           Abs  450564 #0006E004 -  4490
=~xDROPN                           Abs  466948 #00072004 -  4491
=~xDTAG                            Abs  569348 #0008B004 -  4492
=~xDUP                             Abs  434180 #0006A004 -  4493
=~xDUP2                            Abs  438276 #0006B004 -  4494
=~xDUPN                            Abs  471044 #00073004 -  4495
=~xDate                            Abs  930034 #000E30F2 -  4496
=~xDigits                          Abs 1061106 #001030F2 -  4497
=~xE                               Abs  549106 #000860F2 -  4498
=~xEGV                             Abs   28843 #000070AB -  4499
=~xEGVL                            Abs   32939 #000080AB -  4500
=~xELSE                            Abs    9984 #00002700 -  4501
=~xENDDO                           Abs   67328 #00010700 -  4502
=~xENDSUB                          Abs  352427 #000560AB -  4503
=~xENDTIC                          Abs  104192 #00019700 -  4504
=~xENG                             Abs  131243 #000200AB -  4505
=~xEQ>                             Abs  233476 #00039004 -  4506
=~xERASE                           Abs  323588 #0004F004 -  4507
=~xERASEA                          Abs  327684 #00050004 -  4508
=~xERR0                            Abs  425986 #00068002 -  4509
=~xERRM                            Abs  434178 #0006A002 -  4510
=~xERRN                            Abs  430082 #00069002 -  4511
=~xERRTHEN                         Abs   71424 #00011700 -  4512
=~xEVAL                            Abs  438274 #0006B002 -  4513
=~xEXP                             Abs  143362 #00023002 -  4514
=~xEXPAN                           Abs  569346 #0008B002 -  4515
=~xEXPFIT                          Abs  164011 #000280AB -  4516
=~xEXPM                            Abs  163842 #00028002 -  4517
=~xExtremum                        Abs 1126642 #001130F2 -  4518
=~xF0                              Abs  155890 #000260F2 -  4519
=~xF1                              Abs   82162 #000140F2 -  4520
=~xF2                              Abs   90354 #000160F2 -  4521
=~xF3                              Abs   98546 #000180F2 -  4522
=~xF4                              Abs  106738 #0001A0F2 -  4523
=~xF5                              Abs  114930 #0001C0F2 -  4524
=~xF6                              Abs  123122 #0001E0F2 -  4525
=~xF7                              Abs  131314 #000200F2 -  4526
=~xF8                              Abs  139506 #000220F2 -  4527
=~xF9                              Abs  147698 #000240F2 -  4528
=~xFACT                            Abs  167938 #00029002 -  4529
=~xFC?                             Abs  163844 #00028004 -  4530
=~xFC?C                            Abs  172036 #0002A004 -  4531
=~xFCNAPPLY                        Abs  532482 #00082002 -  4532
=~xFIT                             Abs  901362 #000DC0F2 -  4533
=~xFIX                             Abs  123051 #0001E0AB -  4534
=~xFLOOR                           Abs  184322 #0002D002 -  4535
=~xFORMUNIT                        Abs  561154 #00089002 -  4536
=~xFP                              Abs  180226 #0002C002 -  4537
=~xFRACTION                        Abs  135339 #000210AB -  4538
=~xFS?                             Abs  159748 #00027004 -  4539
=~xFS?C                            Abs  167940 #00029004 -  4540
=~xFUNCSYMB                        Abs  176369 #0002B0F1 -  4541
=~xFUNCTAB                         Abs   33009 #000080F1 -  4542
=~xFUNCTION                        Abs  585730 #0008F002 -  4543
=~xFmList                          Abs  360450 #00058002 -  4544
=~xFmMat                           Abs  364546 #00059002 -  4545
=~xFormat                          Abs 1057010 #001020F2 -  4546
=~xGET                             Abs  266244 #00041004 -  4547
=~xGETI                            Abs  270340 #00042004 -  4548
=~xGOR                             Abs  385028 #0005E004 -  4549
=~xGRAPH                           Abs  339972 #00053004 -  4550
=~xGXOR                            Abs  389124 #0005F004 -  4551
=~xGrid                            Abs  942322 #000E60F2 -  4552
=~xH1                              Abs  450802 #0006E0F2 -  4553
=~xH2                              Abs  454898 #0006F0F2 -  4554
=~xH3                              Abs  458994 #000700F2 -  4555
=~xH4                              Abs  463090 #000710F2 -  4556
=~xH5                              Abs  467186 #000720F2 -  4557
=~xHAngle                          Abs  905458 #000DD0F2 -  4558
=~xHDigits                         Abs  913650 #000DF0F2 -  4559
=~xHEAD                            Abs  336043 #000520AB -  4560
=~xHELP                            Abs  280321 #00044701 -  4561
=~xHFormat                         Abs  909554 #000DE0F2 -  4562
=~xHIST                            Abs  147627 #000240AB -  4563
=~xHMS+                            Abs  487426 #00077002 -  4564
=~xHMS-                            Abs  491522 #00078002 -  4565
=~xHMS>                            Abs  233474 #00039002 -  4566
=~xHOME                            Abs  143364 #00023004 -  4567
=~xHTick                           Abs 1007858 #000F60F2 -  4568
=~xHighRes                         Abs  950514 #000E80F2 -  4569
=~xHisWidth                        Abs 1183986 #001210F2 -  4570
=~xHmax                            Abs 1192178 #001230F2 -  4571
=~xHmin                            Abs 1188082 #001220F2 -  4572
=~xHpgccABOUT                      Abs    8467 #00002113 -  6006  6746
=~xHzoom                           Abs 1016050 #000F80F2 -  4573
=~xI                               Abs  565490 #0008A0F2 -  4574
=~xIDN                             Abs    8196 #00002004 -  4575
=~xIF                              Abs    1792 #00000700 -  4576
=~xIFEND                           Abs   14080 #00003700 -  4577
=~xIFERR                           Abs   46848 #0000B700 -  4578
=~xIFT                             Abs  442370 #0006C002 -  4579
=~xIFTE                            Abs       2 #00000002 -  4580
=~xIM                              Abs  307202 #0004B002 -  4581
=~xINCR                            Abs  520196 #0007F004 -  4582
=~xINPUT                           Abs  544772 #00085004 -  4583
=~xINTEGRAL                        Abs  323586 #0004F002 -  4584
=~xINV                             Abs   73730 #00012002 -  4585
=~xIP                              Abs  176130 #0002B002 -  4586
=~xISOL                            Abs  368642 #0005A002 -  4587
=~xIerr                            Abs  921842 #000E10F2 -  4588
=~xIndep                           Abs  995570 #000F30F2 -  4589
=~xInvCursor                       Abs  962802 #000EB0F2 -  4590
=~xIsect                           Abs 1122546 #001120F2 -  4591
=~xKEY                             Abs  475138 #00074002 -  4592
=~xKILL                            Abs  413698 #00065002 -  4593
=~xLABEL                           Abs  344068 #00054004 -  4594
=~xLAST                            Abs  462850 #00071002 -  4595
=~xLINE                            Abs  364548 #00059004 -  4596
=~xLINFIT                          Abs  155819 #000260AB -  4597
=~xLININ                           Abs     171 #000000AB -  4598
=~xLIST>                           Abs  200708 #00031004 -  4599
=~xLN                              Abs  147458 #00024002 -  4600
=~xLNP1                            Abs  159746 #00027002 -  4601
=~xLOG                             Abs  151554 #00025002 -  4602
=~xLOGFIT                          Abs  159915 #000270AB -  4603
=~xLOGISFIT                        Abs  180395 #0002C0AB -  4604
=~xLQ                              Abs   53419 #0000D0AB -  4605
=~xLSQ                             Abs   24747 #000060AB -  4606
=~xLU                              Abs   45227 #0000B0AB -  4607
=~xLabels                          Abs  966898 #000EC0F2 -  4608
=~xMANT                            Abs  217090 #00035002 -  4609
=~xMATCHDN                         Abs  557058 #00088002 -  4610
=~xMATCHUP                         Abs  552962 #00087002 -  4611
=~xMAX                             Abs  196610 #00030002 -  4612
=~xMAXR                            Abs   24578 #00006002 -  4613
=~xMAXS                            Abs  676082 #000A50F2 -  4614
=~xMEANS                           Abs  643314 #0009D0F2 -  4615
=~xMEANX                           Abs  692466 #000A90F2 -  4616
=~xMEANY                           Abs  704754 #000AC0F2 -  4617
=~xMEDIAN                          Abs  680178 #000A60F2 -  4618
=~xMEM                             Abs  540676 #00084004 -  4619
=~xMIN                             Abs  200706 #00031002 -  4620
=~xMINR                            Abs   28674 #00007002 -  4621
=~xMINS                            Abs  671986 #000A40F2 -  4622
=~xMKMAT                           Abs  200875 #000310AB -  4623
=~xMOD                             Abs  212994 #00034002 -  4624
=~xMSGBOX                          Abs  323755 #0004F0AB -  4625
=~xNEG                             Abs    8194 #00002002 -  4626
=~xNEGNEG                          Abs   45058 #0000B002 -  4627
=~xNEXT                            Abs   91904 #00016700 -  4628
=~xNOT                             Abs  393218 #00060002 -  4629
=~xNS                              Abs  667890 #000A30F2 -  4630
=~xNSUB                            Abs  348331 #000550AB -  4631
=~xNUM                             Abs  217092 #00035004 -  4632
=~xNmax                            Abs 1167602 #0011D0F2 -  4633
=~xNmin                            Abs 1163506 #0011C0F2 -  4634
=~xNoteText                        Abs 1065202 #001040F2 -  4635
=~xNumCol                          Abs 1048818 #001000F2 -  4636
=~xNumFont                         Abs 1052914 #001010F2 -  4637
=~xNumIndep                        Abs 1036530 #000FD0F2 -  4638
=~xNumRow                          Abs 1044722 #000FF0F2 -  4639
=~xNumStart                        Abs 1024242 #000FA0F2 -  4640
=~xNumStep                         Abs 1028338 #000FB0F2 -  4641
=~xNumType                         Abs 1032434 #000FC0F2 -  4642
=~xNumZoom                         Abs 1040626 #000FE0F2 -  4643
=~xOBJ>                            Abs  237572 #0003A004 -  4644
=~xOFF                             Abs  417794 #00066002 -  4645
=~xOR                              Abs  389122 #0005F002 -  4646
=~xOVER                            Abs  458756 #00070004 -  4647
=~xPARAMETRIC                      Abs  593922 #00091002 -  4648
=~xPARAMSYMB                       Abs  184561 #0002D0F1 -  4649
=~xPARAMTAB                        Abs   41201 #0000A0F1 -  4650
=~xPCOEF                           Abs   69803 #000110AB -  4651
=~xPDIM                            Abs  319492 #0004E004 -  4652
=~xPERM                            Abs  278530 #00044002 -  4653
=~xPEVAL                           Abs   73899 #000120AB -  4654
=~xPI                              Abs   20482 #00005002 -  4655
=~xPICK                            Abs  475140 #00074004 -  4656
=~xPICT                            Abs  380932 #0005D004 -  4657
=~xPINIT                           Abs  259841 #0003F701 -  4658
=~xPIX?                            Abs  360452 #00058004 -  4659
=~xPIXOFF                          Abs  356356 #00057004 -  4660
=~xPIXON                           Abs  352260 #00056004 -  4661
=~xPLOT>                           Abs  401412 #00062004 -  4662
=~xPMAX                            Abs  290820 #00047004 -  4663
=~xPMIN                            Abs  286724 #00046004 -  4664
=~xPOLAR                           Abs  589826 #00090002 -  4665
=~xPOLARSYMB                       Abs  180465 #0002C0F1 -  4666
=~xPOLARTAB                        Abs   37105 #000090F1 -  4667
=~xPOLYFORM                        Abs  233643 #000390AB -  4668
=~xPOWERFIT                        Abs  168107 #000290AB -  4669
=~xPREDIV                          Abs  356354 #00057002 -  4670
=~xPREDX                           Abs   20484 #00005004 -  4671
=~xPREDY                           Abs   16388 #00004004 -  4672
=~xPROOT                           Abs   65707 #000100AB -  4673
=~xPSDEV                           Abs  663794 #000A20F2 -  4674
=~xPURGE                           Abs  536580 #00083004 -  4675
=~xPUT                             Abs  258052 #0003F004 -  4676
=~xPUTI                            Abs  262148 #00040004 -  4677
=~xPVARS                           Abs  655602 #000A00F2 -  4678
=~xPVIEW                           Abs  348164 #00055004 -  4679
=~xPX>C                            Abs  331780 #00051004 -  4680
=~xPage                            Abs 1069298 #001050F2 -  4681
=~xPageNum                         Abs 1073394 #001060F2 -  4682
=~xPoly                            Abs  368811 #0005A0AB -  4683
=~xPrRUN                           Abs     275 #00000113 -  6002  6688
=~xQ1                              Abs  684274 #000A70F2 -  4684
=~xQ3                              Abs  688370 #000A80F2 -  4685
=~xQR                              Abs   49323 #0000C0AB -  4686
=~xQUAD                            Abs  372738 #0005B002 -  4687
=~xQUADFIT                         Abs  172203 #0002A0AB -  4688
=~xQUOTE                           Abs  335874 #00052002 -  4689
=~xR0                              Abs  401650 #000620F2 -  4690
=~xR1                              Abs  327922 #000500F2 -  4691
=~xR2                              Abs  336114 #000520F2 -  4692
=~xR3                              Abs  344306 #000540F2 -  4693
=~xR4                              Abs  352498 #000560F2 -  4694
=~xR5                              Abs  360690 #000580F2 -  4695
=~xR6                              Abs  368882 #0005A0F2 -  4696
=~xR7                              Abs  377074 #0005C0F2 -  4697
=~xR8                              Abs  385266 #0005E0F2 -  4698
=~xR9                              Abs  393458 #000600F2 -  4699
=~xR>B                             Abs   77828 #00013004 -  4700
=~xR>C                             Abs  188420 #0002E004 -  4701
=~xR>D                             Abs  225282 #00037002 -  4702
=~xRAND                            Abs  270338 #00042002 -  4703
=~xRANK                            Abs   20651 #000050AB -  4704
=~xRANM                            Abs  245931 #0003C0AB -  4705
=~xRCI                             Abs  299179 #000490AB -  4706
=~xRCIJ                            Abs  303275 #0004A0AB -  4707
=~xRCL                             Abs  528388 #00081004 -  4708
=~xRCLF                            Abs  176132 #0002B004 -  4709
=~xRCLKEYS                         Abs  561156 #00089004 -  4710
=~xRDM                             Abs  249860 #0003D004 -  4711
=~xRDZ                             Abs  499714 #0007A002 -  4712
=~xRE                              Abs  303106 #0004A002 -  4713
=~xREADNOTE                        Abs  246001 #0003C0F1 -  4714  6041
=~xREADPICT                        Abs  250097 #0003D0F1 -  4715  6043
=~xRECURSE                         Abs  229547 #000380AB -  4716
=~xRELERR                          Abs  729330 #000B20F2 -  4717
=~xREPEAT                          Abs   26368 #00006700 -  4718
=~xREPL                            Abs  196612 #00030004 -  4719
=~xREVLIST                         Abs   98475 #000180AB -  4720
=~xRL                              Abs   45060 #0000B004 -  4721
=~xRLB                             Abs   49156 #0000C004 -  4722
=~xRND                             Abs  204802 #00032002 -  4723
=~xRNRM                            Abs  237570 #0003A002 -  4724
=~xROLL                            Abs  479236 #00075004 -  4725
=~xROLLD                           Abs  483332 #00076004 -  4726
=~xROOT                            Abs  319490 #0004E002 -  4727
=~xROT                             Abs  454660 #0006F004 -  4728
=~xROW+                            Abs  278699 #000440AB -  4729
=~xROW-                            Abs  274603 #000430AB -  4730
=~xROW>                            Abs  254123 #0003E0AB -  4731
=~xRPN->                           Abs  100096 #00018700 -  4732
=~xRR                              Abs   53252 #0000D004 -  4733
=~xRRB                             Abs   57348 #0000E004 -  4734
=~xRREF                            Abs   61611 #0000F0AB -  4735
=~xRSD                             Abs  495618 #00079002 -  4736
=~xRSWP                            Abs  290987 #000470AB -  4737
=~xRULES                           Abs  573442 #0008C002 -  4738
=~xRadixMark                       Abs  917746 #000E00F2 -  4739
=~xRecenter                        Abs  958706 #000EA0F2 -  4740
=~xRoot                            Abs 1118450 #001110F2 -  4741
=~xS1                              Abs  471282 #000730F2 -  4742
=~xS1fit                           Abs 1216754 #001290F2 -  4743
=~xS1mark                          Abs 1196274 #001240F2 -  4744
=~xS2                              Abs  475378 #000740F2 -  4745
=~xS2fit                           Abs 1220850 #0012A0F2 -  4746
=~xS2mark                          Abs 1200370 #001250F2 -  4747
=~xS3                              Abs  479474 #000750F2 -  4748
=~xS3fit                           Abs 1224946 #0012B0F2 -  4749
=~xS3mark                          Abs 1204466 #001260F2 -  4750
=~xS4                              Abs  483570 #000760F2 -  4751
=~xS4fit                           Abs 1229042 #0012C0F2 -  4752
=~xS4mark                          Abs 1208562 #001270F2 -  4753
=~xS5                              Abs  487666 #000770F2 -  4754
=~xS5fit                           Abs 1233138 #0012D0F2 -  4755
=~xS5mark                          Abs 1212658 #001280F2 -  4756
=~xSAME                            Abs  380930 #0005D002 -  4757
=~xSCALE                           Abs  315396 #0004D004 -  4758
=~xSCHUR                           Abs   57515 #0000E0AB -  4759
=~xSCI                             Abs  127147 #0001F0AB -  4760
=~xSCONJ                           Abs  499716 #0007A004 -  4761
=~xSEC                             Abs  209067 #000330AB -  4762
=~xSEQ                             Abs   77995 #000130AB -  4763
=~xSEQSYMB                         Abs  188657 #0002E0F1 -  4764
=~xSEQTAB                          Abs   45297 #0000B0F1 -  4765
=~xSETDATE                         Abs  118788 #0001D004 -  4766
=~xSETTIME                         Abs  122884 #0001E004 -  4767
=~xSF                              Abs  151556 #00025004 -  4768
=~xSHOW                            Abs  581634 #0008E002 -  4769
=~xSIGN                            Abs   81922 #00014002 -  4770
=~xSILENT'                         Abs   96000 #00017700 -  4771
=~xSIN                             Abs   94210 #00017002 -  4772
=~xSINH                            Abs  106498 #0001A002 -  4773
=~xSINV                            Abs  491524 #00078004 -  4774
=~xSL                              Abs   61444 #0000F004 -  4775
=~xSLB                             Abs   65540 #00010004 -  4776
=~xSNEG                            Abs  495620 #00079004 -  4777
=~xSNRM                            Abs   16555 #000040AB -  4778
=~xSOLVESYMB                       Abs  200945 #000310F1 -  4779
=~xSOLVETAB                        Abs   57585 #0000E0F1 -  4780
=~xSORT                            Abs  102571 #000190AB -  4781
=~xSQ                              Abs   90114 #00016002 -  4782
=~xSQRT                            Abs   86018 #00015002 -  4783
=~xSR                              Abs   69636 #00011004 -  4784
=~xSRAD                            Abs   12459 #000030AB -  4785
=~xSRB                             Abs   73732 #00012004 -  4786
=~xSSDEV                           Abs  659698 #000A10F2 -  4787
=~xSTAIRSTEP                       Abs  139435 #000220AB -  4788
=~xSTART                           Abs   87808 #00015700 -  4789
=~xSTARTVAR                        Abs   38656 #00009700 -  4790
=~xSTAT2SYMB                       Abs  196849 #000300F1 -  4791
=~xSTAT2TAB                        Abs   53489 #0000D0F1 -  4792
=~xSTATSYMB                        Abs  192753 #0002F0F1 -  4793
=~xSTATTAB                         Abs   49393 #0000C0F1 -  4794
=~xSTD                             Abs  118955 #0001D0AB -  4795
=~xSTEP                            Abs   42752 #0000A700 -  4796
=~xSTO                             Abs  532484 #00082004 -  4797
=~xSTO*                            Abs  516100 #0007E004 -  4798
=~xSTO+                            Abs  503812 #0007B004 -  4799
=~xSTO-                            Abs  507908 #0007C004 -  4800
=~xSTO/                            Abs  512004 #0007D004 -  4801
=~xSTOF                            Abs  180228 #0002C004 -  4802
=~xSTOKEYS                         Abs  552964 #00087004 -  4803
=~xSTR>                            Abs  212996 #00034004 -  4804
=~xSTREAM                          Abs  356523 #000570AB -  4805
=~xSUB                             Abs  192516 #0002F004 -  4806
=~xSUM                             Abs  327682 #00050002 -  4807
=~xSVARS                           Abs  651506 #0009F0F2 -  4808
=~xSVD                             Abs   37035 #000090AB -  4809
=~xSVL                             Abs   41131 #0000A0AB -  4810
=~xSWAP                            Abs  442372 #0006C004 -  4811
=~xSX                              Abs  696562 #000AA0F2 -  4812
=~xSX2                             Abs  700658 #000AB0F2 -  4813
=~xSXY                             Abs  717042 #000AF0F2 -  4814
=~xSY                              Abs  708850 #000AD0F2 -  4815
=~xSY2                             Abs  712946 #000AE0F2 -  4816
=~xSYSEVAL                         Abs  446466 #0006D002 -  4817
=~xSeqPlot                         Abs 1171698 #0011E0F2 -  4818
=~xShSPLASH                        Abs    4371 #00001113 -  6004  6539  6612
=~xSimult                          Abs  954610 #000E90F2 -  4819
=~xSlope                           Abs 1134834 #001150F2 -  4820
=~xStat1Var                        Abs  188587 #0002E0AB -  4821
=~xStat2Var                        Abs  192683 #0002F0AB -  4822
=~xStatMode                        Abs 1175794 #0011F0F2 -  4823
=~xStatPlot                        Abs 1179890 #001200F2 -  4824
=~xTAIL                            Abs  340139 #000530AB -  4825
=~xTAN                             Abs  102402 #00019002 -  4826
=~xTANH                            Abs  114690 #0001C002 -  4827
=~xTAYLR                           Abs  376834 #0005C002 -  4828
=~xTEXT                            Abs  421892 #00067004 -  4829
=~xTHEN                            Abs    5888 #00001700 -  4830
=~xTHENCASE                        Abs   79616 #00013700 -  4831
=~xTIME                            Abs  106500 #0001A004 -  4832
=~xTLINE                           Abs  368644 #0005A004 -  4833
=~xTOTS                            Abs  647410 #0009E0F2 -  4834
=~xTRACE                           Abs    8363 #000020AB -  4835
=~xTRN                             Abs   12292 #00003004 -  4836
=~xTRNC                            Abs  208898 #00033002 -  4837
=~xTSTR                            Abs  131076 #00020004 -  4838
=~xTStep                           Abs 1147122 #001180F2 -  4839
=~xTYPE                            Abs  225284 #00037004 -  4840
=~xThetaMax                        Abs 1155314 #0011A0F2 -  4841
=~xThetaMin                        Abs 1151218 #001190F2 -  4842
=~xThetaStep                       Abs 1159410 #0011B0F2 -  4843
=~xTime                            Abs  925938 #000E20F2 -  4844
=~xTmax                            Abs 1143026 #001170F2 -  4845
=~xTmin                            Abs 1138930 #001160F2 -  4846
=~xTracing                         Abs  970994 #000ED0F2 -  4847
=~xU0                              Abs   73970 #000120F2 -  4848
=~xU1                              Abs     242 #000000F2 -  4849
=~xU2                              Abs    8434 #000020F2 -  4850
=~xU3                              Abs   16626 #000040F2 -  4851
=~xU4                              Abs   24818 #000060F2 -  4852
=~xU5                              Abs   33010 #000080F2 -  4853
=~xU6                              Abs   41202 #0000A0F2 -  4854
=~xU7                              Abs   49394 #0000C0F2 -  4855
=~xU8                              Abs   57586 #0000E0F2 -  4856
=~xU9                              Abs   65778 #000100F2 -  4857
=~xUBASE                           Abs   98308 #00018004 -  4858
=~xUFACT                           Abs  102404 #00019004 -  4859
=~xUNCHECK                         Abs  255745 #0003E701 -  4860
=~xUNTIL                           Abs   34560 #00008700 -  4861
=~xUSERFIT                         Abs  184491 #0002D0AB -  4862
=~xUTPC                            Abs   24580 #00006004 -  4863
=~xUTPF                            Abs   32772 #00008004 -  4864
=~xUTPN                            Abs   28676 #00007004 -  4865
=~xUTPT                            Abs   36868 #00009004 -  4866
=~xUVAL                            Abs   90116 #00016004 -  4867
=~xUndefined                       Abs  123121 #0001E0F1 -  4868
=~xV>                              Abs  274436 #00043004 -  4869
=~xVERSION                         Abs  237739 #0003A0AB -  4870
=~xVTYPE                           Abs  229380 #00038004 -  4871
=~xVTick                           Abs 1011954 #000F70F2 -  4872
=~xVzoom                           Abs 1020146 #000F90F2 -  4873
=~xWAIT                            Abs  466946 #00072002 -  4874
=~xWHERE                           Abs  331778 #00051002 -  4875
=~xWHILE                           Abs   22272 #00005700 -  4876
=~xWHILEEND                        Abs   63232 #0000F700 -  4877
=~xWSLOG                           Abs  114692 #0001C004 -  4878
=~xX0                              Abs  311538 #0004C0F2 -  4879
=~xX1                              Abs  164082 #000280F2 -  4880
=~xX2                              Abs  180466 #0002C0F2 -  4881
=~xX3                              Abs  196850 #000300F2 -  4882
=~xX4                              Abs  213234 #000340F2 -  4883
=~xX5                              Abs  229618 #000380F2 -  4884
=~xX6                              Abs  246002 #0003C0F2 -  4885
=~xX7                              Abs  262386 #000400F2 -  4886
=~xX8                              Abs  278770 #000440F2 -  4887
=~xX9                              Abs  295154 #000480F2 -  4888
=~xXOR                             Abs  397314 #00061002 -  4889
=~xXPON                            Abs  192514 #0002F002 -  4890
=~xXRECV                           Abs  331947 #000510AB -  4891
=~xXRNG                            Abs  425988 #00068004 -  4892
=~xXROOT                           Abs   65538 #00010002 -  4893
=~xXSEND                           Abs  327851 #000500AB -  4894
=~xXcross                          Abs  999666 #000F40F2 -  4895
=~xXmax                            Abs  983282 #000F00F2 -  4896
=~xXmin                            Abs  979186 #000EF0F2 -  4897
=~xY0                              Abs  319730 #0004E0F2 -  4898
=~xY1                              Abs  172274 #0002A0F2 -  4899
=~xY2                              Abs  188658 #0002E0F2 -  4900
=~xY3                              Abs  205042 #000320F2 -  4901
=~xY4                              Abs  221426 #000360F2 -  4902
=~xY5                              Abs  237810 #0003A0F2 -  4903
=~xY6                              Abs  254194 #0003E0F2 -  4904
=~xY7                              Abs  270578 #000420F2 -  4905
=~xY8                              Abs  286962 #000460F2 -  4906
=~xY9                              Abs  303346 #0004A0F2 -  4907
=~xYRNG                            Abs  430084 #00069004 -  4908
=~xYcross                          Abs 1003762 #000F50F2 -  4909
=~xYmax                            Abs  991474 #000F20F2 -  4910
=~xYmin                            Abs  987378 #000F10F2 -  4911
=~x\85LIST                         Abs   86187 #000150AB -  4912
=~x\9BLIST                         Abs   82091 #000140AB -  4913
=~x\9CLIST                         Abs   90283 #000160AB -  4914
=~x^                               Abs   61442 #0000F002 -  4915
=~xa                               Abs  532722 #000820F2 -  4916
=~xb                               Abs  536818 #000830F2 -  4917
=~xc                               Abs  540914 #000840F2 -  4918
=~xd                               Abs  545010 #000850F2 -  4919
=~xf                               Abs  553202 #000870F2 -  4920
=~xg                               Abs  557298 #000880F2 -  4921
=~xg0                              Abs  856306 #000D10F2 -  4922
=~xg1                              Abs  860402 #000D20F2 -  4923
=~xg2                              Abs  864498 #000D30F2 -  4924
=~xg3                              Abs  868594 #000D40F2 -  4925
=~xg4                              Abs  872690 #000D50F2 -  4926
=~xg5                              Abs  876786 #000D60F2 -  4927
=~xg6                              Abs  880882 #000D70F2 -  4928
=~xg7                              Abs  884978 #000D80F2 -  4929
=~xg8                              Abs  889074 #000D90F2 -  4930
=~xg9                              Abs  893170 #000DA0F2 -  4931
=~xh                               Abs  561394 #000890F2 -  4932
=~xi                               Abs   36866 #00009002 -  4933
=~xj                               Abs  569586 #0008B0F2 -  4934
=~xk                               Abs  573682 #0008C0F2 -  4935
=~xl                               Abs  577778 #0008D0F2 -  4936
=~xl0                              Abs  815346 #000C70F2 -  4937
=~xl1                              Abs  819442 #000C80F2 -  4938
=~xl2                              Abs  823538 #000C90F2 -  4939
=~xl3                              Abs  827634 #000CA0F2 -  4940
=~xl4                              Abs  831730 #000CB0F2 -  4941
=~xl5                              Abs  835826 #000CC0F2 -  4942
=~xl6                              Abs  839922 #000CD0F2 -  4943
=~xl7                              Abs  844018 #000CE0F2 -  4944
=~xl8                              Abs  848114 #000CF0F2 -  4945
=~xl9                              Abs  852210 #000D00F2 -  4946
=~xm                               Abs  581874 #0008E0F2 -  4947
=~xm0                              Abs  774386 #000BD0F2 -  4948
=~xm1                              Abs  778482 #000BE0F2 -  4949
=~xm2                              Abs  782578 #000BF0F2 -  4950
=~xm3                              Abs  786674 #000C00F2 -  4951
=~xm4                              Abs  790770 #000C10F2 -  4952
=~xm5                              Abs  794866 #000C20F2 -  4953
=~xm6                              Abs  798962 #000C30F2 -  4954
=~xm7                              Abs  803058 #000C40F2 -  4955
=~xm8                              Abs  807154 #000C50F2 -  4956
=~xm9                              Abs  811250 #000C60F2 -  4957
=~xn                               Abs  585970 #0008F0F2 -  4958
=~xn1                              Abs  512242 #0007D0F2 -  4959
=~xn2                              Abs  516338 #0007E0F2 -  4960
=~xn3                              Abs  520434 #0007F0F2 -  4961
=~xn4                              Abs  524530 #000800F2 -  4962
=~xn5                              Abs  528626 #000810F2 -  4963
=~xo                               Abs  590066 #000900F2 -  4964
=~xp                               Abs  594162 #000910F2 -  4965
=~xq                               Abs  598258 #000920F2 -  4966
=~xr                               Abs  602354 #000930F2 -  4967
=~xs                               Abs  606450 #000940F2 -  4968
=~xs1                              Abs  491762 #000780F2 -  4969
=~xs2                              Abs  495858 #000790F2 -  4970
=~xs3                              Abs  499954 #0007A0F2 -  4971
=~xs4                              Abs  504050 #0007B0F2 -  4972
=~xs5                              Abs  508146 #0007C0F2 -  4973
=~xt                               Abs  610546 #000950F2 -  4974
=~xtheta                           Abs  639218 #0009C0F2 -  4975
=~xu                               Abs  614642 #000960F2 -  4976
=~xv                               Abs  618738 #000970F2 -  4977
=~xw                               Abs  622834 #000980F2 -  4978
=~xx                               Abs  626930 #000990F2 -  4979
=~xx>DISPLAY                       Abs   83713 #00014701 -  4980
=~xx>GROB                          Abs   96001 #00017701 -  4981
=~xx>PLOT                          Abs   91905 #00016701 -  4982
=~xxARC                            Abs  100097 #00018701 -  4983
=~xxBEEP                           Abs   14081 #00003701 -  4984
=~xxBOX                            Abs   63233 #0000F701 -  4985
=~xxBREAK                          Abs  120577 #0001D701 -  4986
=~xxCHOOSE                         Abs  268033 #00041701 -  4987
=~xxCOL+                           Abs  145153 #00023701 -  4988
=~xxCOL-                           Abs  141057 #00022701 -  4989
=~xxCSWP                           Abs  153345 #00025701 -  4990
=~xxDEG                            Abs  106667 #0001A0AB -  4991
=~xxDEMO                           Abs  231169 #00038701 -  4992
=~xxDISP                           Abs    9985 #00002701 -  4993
=~xxDISPLAY>                       Abs   79617 #00013701 -  4994
=~xxDO1VSTATS                      Abs  202497 #00031701 -  4995
=~xxDO2VSTATS                      Abs  214785 #00034701 -  4996
=~xxERASE                          Abs   38657 #00009701 -  4997
=~xxERASEPLOT                      Abs   42753 #0000A701 -  4998
=~xxFREEZE                         Abs  128769 #0001F701 -  4999
=~xxGETKEY                         Abs  272129 #00042701 -  5000
=~xxGOR                            Abs   67329 #00010701 -  5001
=~xxGRAD                           Abs  114859 #0001C0AB -  5002
=~xxGROBNOT                        Abs   75521 #00012701 -  5003
=~xxGXOR                           Abs   71425 #00011701 -  5004
=~xxHELP                           Abs  276225 #00043701 -  5005
=~xxINPUT                          Abs  116481 #0001C701 -  5006
=~xxITERATE                        Abs  196779 #000300AB -  5007
=~xxLIBEVAL                        Abs  186113 #0002D701 -  5008
=~xxLINE                           Abs   55041 #0000D701 -  5009
=~xxMATEDIT                        Abs  173825 #0002A701 -  5010
=~xxMEM                            Abs  235265 #00039701 -  5011
=~xxMKGROB                         Abs  177921 #0002B701 -  5012
=~xxMSGBOX                         Abs  263937 #00040701 -  5013
=~xxPIXOFF                         Abs   50945 #0000C701 -  5014
=~xxPIXON                          Abs   46849 #0000B701 -  5015
=~xxPLOT>                          Abs   87809 #00015701 -  5016
=~xxPOS                            Abs    4100 #00001004 -  5017
=~xxPRDISPLAY                      Abs  112385 #0001B701 -  5018
=~xxPRSTC                          Abs  104193 #00019701 -  5019
=~xxPRVAR                          Abs  108289 #0001A701 -  5020
=~xxRAD                            Abs  110763 #0001B0AB -  5021
=~xxRANM                           Abs  222977 #00036701 -  5022
=~xxRCI                            Abs  157441 #00026701 -  5023
=~xxRCIJ                           Abs  161537 #00027701 -  5024
=~xxRDM                            Abs   34561 #00008701 -  5025
=~xxRDZ                            Abs   22273 #00005701 -  5026
=~xxREPL                           Abs   30465 #00007701 -  5027
=~xxROW+                           Abs  136961 #00021701 -  5028
=~xxROW-                           Abs  132865 #00020701 -  5029
=~xxRSWP                           Abs  149249 #00024701 -  5030
=~xxRULES                          Abs  239361 #0003A701 -  5031
=~xxRUNPGM                         Abs  169729 #00029701 -  5032
=~xxSELECT                         Abs  218881 #00035701 -  5033
=~xxSETDEPEND                      Abs  210689 #00033701 -  5034
=~xxSETFREQ                        Abs  198401 #00030701 -  5035
=~xxSETINDEP                       Abs  206593 #00032701 -  5036
=~xxSETSAMPLE                      Abs  194305 #0002F701 -  5037
=~xxSETVIEWS                       Abs  247553 #0003C701 -  5038
=~xxSIZE                           Abs       4 #00000004 -  5039
=~xxSTOP                           Abs  124673 #0001E701 -  5040
=~xxSUB                            Abs   26369 #00006701 -  5041
=~xxSYSEVAL                        Abs  190209 #0002E701 -  5042
=~xxTLINE                          Abs   59137 #0000E701 -  5043
=~xxTO                             Abs  165633 #00028701 -  5044
=~xxTSTR                           Abs    5889 #00001701 -  5045
=~xxVERSION                        Abs  227073 #00037701 -  5046
=~xxWAIT                           Abs   18177 #00004701 -  5047
=~xxWSLOG                          Abs    1793 #00000701 -  5048
=~xxZEROGROB                       Abs  182017 #0002C701 -  5049
=~xy                               Abs  631026 #0009A0F2 -  5050
=~xz                               Abs  635122 #0009B0F2 -  5051
=~xz0                              Abs  733426 #000B30F2 -  5052
=~xz1                              Abs  737522 #000B40F2 -  5053
=~xz2                              Abs  741618 #000B50F2 -  5054
=~xz3                              Abs  745714 #000B60F2 -  5055
=~xz4                              Abs  749810 #000B70F2 -  5056
=~xz5                              Abs  753906 #000B80F2 -  5057
=~xz6                              Abs  758002 #000B90F2 -  5058
=~xz7                              Abs  762098 #000BA0F2 -  5059
=~xz8                              Abs  766194 #000BB0F2 -  5060
=~xz9                              Abs  770290 #000BC0F2 -  5061
=~{$}>{id}                         Abs  119016 #0001D0E8 -  5062
=~{$}>{lam}                        Abs  123112 #0001E0E8 -  5063
=~{id}>{$}                         Abs  110824 #0001B0E8 -  5064
=~{lam}>{$}                        Abs  114920 #0001C0E8 -  5065
Saturn Assembler    HPGCC Aplet Template               Mon Jun 27 16:00:01 2022
V3.0.8 (12/06/2002)   Statistics                         hpgccaplet.c   Page    3

Input Parameters

  Source file name is hpgccaplet.c

  Listing file name is hpgccaplet.l

  Object file name is hpgccaplet.o

  Flags set on command line
    None

Warnings:

  None

Errors:

  None
