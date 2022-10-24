 :START ADDRESS: $0400
 LDA #$62	; FIX AUTOSTART HACK
 STA $0218
 LDA #$E7
 STA $0219
 LDA #$08	; SET ASCII
 STA $0202
 LDA #$09
 STA $0203
JSR :CLS:

:TEXT: LDA #%12 ; PRINT CHR$(12)
 JSR $E762
 LDX #$00 ; PRINT HELLO
 LDA :DATA100:,X
:PRINT1: JSR $E762
 INX
 LDA :DATA100:,X
 CMP #$00
 BNE :PRINT1:
 LDX #$00 ; PRINT EAGLE
 JMP :MENU:
:DATA100:
 %10 ; NEXT LINE
 "O"
 "R"
 "A"
 "O"
 " "
 "T"
 "E"
 "R"
 "M"
 "I"
 "N"
 "A"
 "L"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "O"
 "D"
 "A"
 "B"
 "E"
 "R"
 "I"
 " "
 "M"
 "O"
 "D"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "1"
 "."
 " "
 "W"
 "I"
 "F"
 "I"
 " "
 "M"
 "O"
 "D"
 "E"
 "M"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "2"
 "."
 " "
 "R"
 "S"
 "2"
 "3"
 "2"
 $00 ; END CHECK VALUE
:END DATA100:

:MENU: LDA #$00
	STA $FA ; Clear button press
	JSR $E5B0
BEQ :MENU:
JSR :1CHECK:

:1CHECK: CMP #$31 ; check if button pressed 1
	BEQ :1: ; if button pressed is 1, go to 1
	JMP :2CHECK: ; if button pressed is not 1, go to 2CHECK
:2CHECK: CMP #$32 ; check if button pressed 2
	BEQ :2: ; if button pressed is 2, go to 2
	JMP :MENU: ; if button pressed is not 2, go to MENU

:1: JSR :CLS:
 LDA #%12 ; PRINT CHR$(12)
 JSR $E762
 LDX #$00 ; PRINT HELLO
 LDA :DATA101:,X
:PRINT2: JSR $E762
 INX
 LDA :DATA101:,X
 CMP #$00
 BNE :PRINT2:
 LDX #$00 ; PRINT EAGLE
 JSR :4800:
 JMP :LOOP:
:DATA101:
 %10 ; NEXT LINE
 "W"
 "I"
 "F"
 "I"
 " "
 "M"
 "O"
 "D"
 "E"
 "M"
 " "
 "M"
 "O"
 "D"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "P"
 "R"
 "I"
 "T"
 "I"
 "S"
 "N"
 "I"
 " "
 %59
 " "
 "Z"
 "A"
 " "
 "B"
 "R"
 "I"
 "S"
 "A"
 "N"
 "J"
 "E"
 " " 
 "E"
 "K" 
 "R"
 "A"
 "N"
 "A"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN 
 $00 ; END CHECK VALUE
:END DATA101:

:2: JSR :CLS:
 LDA #%12 ; PRINT CHR$(12)
 JSR $E762
 LDX #$00 ; PRINT HELLO
 LDA :DATA102:,X
:PRINT3: JSR $E762
 INX
 LDA :DATA102:,X
 CMP #$00
 BNE :PRINT3:
 LDX #$00 ; PRINT EAGLE
 JMP :MENU2:
:DATA102:
 %10 ; NEXT LINE
 "R"
 "S"
 "2"
 "3"
 "2"
 " "
 "M"
 "O"
 "D"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "O"
 "D"
 "A"
 "B"
 "E"
 "R"
 "I"
 " "
 "B"
 "R"
 "Z"
 "I"
 "N"
 "U"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "1"
 "."
 " "
 "3"
 "0"
 "0"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "2"
 "."
 " "
 "2"
 "4"
 "0"
 "0"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "3"
 "."
 " "
 "4"
 "8"
 "0"
 "0"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 $00 ; END CHECK VALUE
:END DATA102:
JMP :MENU:

:MENU2: LDA #$00
	STA $FA ; Clear button press
	JSR $E5B0
BEQ :MENU2:
JSR :1ACHECK:

:1ACHECK: CMP #$31 ; check if button pressed 1
	BEQ :1A: ; if button pressed is 1, go to 1a
	JMP :2ACHECK: ; if button pressed is not 1, go to 2ACHECK

:1A: JSR :CLS:
 LDA #%12 ; PRINT CHR$(12)
 JSR $E762
 LDX #$00 ; PRINT HELLO
 LDA :DATA101A:,X
:PRINT1A: JSR $E762
 INX
 LDA :DATA101A:,X
 CMP #$00
 BNE :PRINT1A:
 LDX #$00 ; PRINT EAGLE
 JSR :300:
 JMP :LOOP:
:DATA101A:
 %10 ; NEXT LINE
 "R"
 "S"
 "2"
 "3"
 "2"
 " "
 "M"
 "O"
 "D"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "B"
 "R"
 "Z"
 "I"
 "N"
 "A"
 " "
 "3"
 "0"
 "0"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "P"
 "R"
 "I"
 "T"
 "I"
 "S"
 "N"
 "I"
 " "
 %59
 " "
 "Z"
 "A"
 " "
 "B"
 "R"
 "I"
 "S"
 "A"
 "N"
 "J"
 "E"
 " " 
 "E"
 "K" 
 "R"
 "A"
 "N"
 "A"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN 
 $00 ; END CHECK VALUE
:END DATA101A:

:2ACHECK: CMP #$32 ; check if button pressed 2
	BEQ :2A: ; if button pressed is 2, go to 2a
	JMP :3ACHECK: ; if button pressed is not 2, go to 3ACHECK

:2A: JSR :CLS:
 LDA #%12 ; PRINT CHR$(12)
 JSR $E762
 LDX #$00 ; PRINT HELLO
 LDA :DATA102A:,X
:PRINT2A: JSR $E762
 INX
 LDA :DATA102A:,X
 CMP #$00
 BNE :PRINT2A:
 LDX #$00 ; PRINT EAGLE
 JSR :2400:
 JMP :LOOP:
:DATA102A:
 %10 ; NEXT LINE
 "R"
 "S"
 "2"
 "3"
 "2"
 " "
 "M"
 "O"
 "D"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "B"
 "R"
 "Z"
 "I"
 "N"
 "A"
 " "
 "2"
 "4"
 "0"
 "0"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "P"
 "R"
 "I"
 "T"
 "I"
 "S"
 "N"
 "I"
 " "
 %59
 " "
 "Z"
 "A"
 " "
 "B"
 "R"
 "I"
 "S"
 "A"
 "N"
 "J"
 "E"
 " " 
 "E"
 "K" 
 "R"
 "A"
 "N"
 "A"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN 
 $00 ; END CHECK VALUE
:END DATA102A:

:3ACHECK: CMP #$33 ; check if button pressed 2
	BEQ :3A: ; if button pressed is 3, go to 3a
	JMP :MENU2: ; if button pressed is not 2, go to MENU2

:3A: JSR :CLS:
 LDA #%12 ; PRINT CHR$(12)
 JSR $E762
 LDX #$00 ; PRINT HELLO
 LDA :DATA103A:,X
:PRINT3A: JSR $E762
 INX
 LDA :DATA103A:,X
 CMP #$00
 BNE :PRINT3A:
 LDX #$00 ; PRINT EAGLE
 JSR :4800:
 JMP :LOOP:
:DATA103A:
 %10 ; NEXT LINE
 "R"
 "S"
 "2"
 "3"
 "2"
 " "
 "M"
 "O"
 "D"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "B"
 "R"
 "Z"
 "I"
 "N"
 "A"
 " "
 "4"
 "8"
 "0"
 "0"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN
 "P"
 "R"
 "I"
 "T"
 "I"
 "S"
 "N"
 "I"
 " "
 %59
 " "
 "Z"
 "A"
 " "
 "B"
 "R"
 "I"
 "S"
 "A"
 "N"
 "J"
 "E"
 " " 
 "E"
 "K" 
 "R"
 "A"
 "N"
 "A"
 %10 ; NEXT LINE
 %13 ; CARRIAGE RETURN 
 $00 ; END CHECK VALUE
:END DATA103A:

:LOOP:  JSR $E5B0 ; This is the main loop checking for text input. If button is not pressed, then the receive loop is active
	BEQ :REDIRECT: ; If button press is not detected, go to redirect which then goes to RECEIVE2 loop
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR $E7B7
	JSR :LOOP3: ; If button is pressed, go to LOOP3
:REDIRECT: JSR :RECEIVE2:
	LDA #$00
	STA $FA ; Clear button press
	LDA $E8
	CMP #$1F ; Check if ";" is pressed. If yes, go to REDIRECT2
	BEQ :REDIRECT2:
	JMP :LOOP: ; Go back to start of the main loop
:REDIRECT2:	JSR :LOOP6: ; go to LOOP6
:LOOP8:	LDA #$00
	LDA #$0C
	JSR $E762
	LDA #$00
	STA $FA
	LDA #$0B 
	STA $B000
	JMP :LOOP:
:LOOP6: JSR $E5B0
	CMP #$0D
	BNE :LOOP7:
	JMP :LOOP8:
:LOOP7:	LDA #$0A
	STA $B000
	JMP :LOOP6:
:LOOP3: CMP #$3B ; check if button pressed is enter
	BEQ :LOOP8: ; if button pressed is enter, go to LOOP8
	JSR :LOOP9: ; if button pressed is not enter, g to LOOP9
	RTS
:LOOP9: PHA
	LDA #$10
:LOOP10:BIT $A800 ; this is the typing and TX loop
	BEQ :LOOP10:
	PLA
	STA $A000
	JSR :DATA:
	RTS
:DATA:$5A ; This is the 65c51 bug hack
	$DA ;
:END DATA:
	LDY #$C0
:LOOP13:LDX #$68
:LOOP12:DEX
	BNE :LOOP12:
	DEY
	BNE :LOOP13:
:DATA1:
	$FA
	$7A
:END DATA1:
	RTS
:TYPING:JSR $E71C
	LDA #$FC
	BEQ :TYPING:
	JSR :LOOP9:
	JMP :TYPING:
:READ:  LDA #$08
:READ2:	BIT $A800
	BEQ :READ2:
	LDA $A000
	RTS
:RECEIVE:JSR :READ:
	JSR $FFF1
	JMP :RECEIVE:
:RECEIVE2:LDA #$08
	BIT $A800
	BNE :RECEIVE3:
	RTS
:RECEIVE3:LDA $A000
	JSR $FFF1
	RTS
:300:	PHA
	LDA #$00
	STA $A800
	LDA #$16
	STA $B800
	LDA #$0B
	STA $B000
	PLA
	RTS
:2400:	PHA
	LDA #$00
	STA $A800
	LDA #$1A
	STA $B800
	LDA #$0B
	STA $B000
	PLA
	RTS
:4800:	PHA
	LDA #$00
	STA $A800
	LDA #$1C
	STA $B800
	LDA #$0B
	STA $B000
	PLA
	RTS
:CLS: LDA #%0		; CLEAR SCREEN
LDA #%12 	
JSR $E762
RTS

:START ADDRESS: $0800
:DATA2:
$38
$44
$74
$54
$74
$04
$78
$00
$38
$44
$44
$7C
$44
$44
$44
$00
$3C
$48
$48
$38
$48
$48
$3C
$00
$38
$44
$04
$04
$04
$44
$38
$00
$3C
$48
$48
$48
$48
$48
$3C
$00
$7C
$04
$04
$1C
$04
$04
$7C
$00
$7C
$04
$04
$1C
$04
$04
$04
$00
$38
$44
$04
$04
$74
$44
$78
$00
$44
$44
$44
$7C
$44
$44
$44
$00
$38
$10
$10
$10
$10
$10
$38
$00
$70
$20
$20
$20
$20
$24
$18
$00
$44
$24
$14
$0C
$14
$24
$44
$00
$04
$04
$04
$04
$04
$04
$7C
$00
$44
$6C
$54
$54
$44
$44
$44
$00
$44
$44
$4C
$54
$64
$44
$44
$00
$38
$44
$44
$44
$44
$44
$38
$00
$3C
$44
$44
$3C
$04
$04
$04
$00
$38
$44
$44
$44
$54
$24
$58
$00
$3C
$44
$44
$3C
$14
$24
$44
$00
$38
$44
$08
$10
$20
$44
$38
$00
$7C
$10
$10
$10
$10
$10
$10
$00
$44
$44
$44
$44
$44
$44
$38
$00
$44
$44
$44
$44
$44
$28
$10
$00
$44
$44
$44
$54
$54
$54
$28
$00
$44
$44
$28
$10
$28
$44
$44
$00
$44
$44
$44
$28
$10
$10
$10
$00
$7C
$40
$20
$10
$08
$04
$7C
$00
$06
$02
$02
$02
$02
$02
$02
$06
$00
$02
$04
$08
$10
$20
$40
$00
$60
$40
$40
$40
$40
$40
$40
$60
$10
$28
$44
$00
$00
$00
$00
$00
$38
$44
$74
$54
$74
$04
$78
$00
$06
$02
$02
$02
$02
$02
$02
$06
$00
$18
$20
$38
$24
$38
$00
$00
$04
$04
$1C
$24
$24
$1C
$00
$00
$00
$38
$04
$04
$04
$38
$00
$00
$20
$20
$38
$24
$24
$38
$00
$00
$00
$18
$24
$1C
$04
$18
$00
$00
$10
$28
$08
$1C
$08
$08
$08
$00
$00
$38
$24
$24
$38
$20
$18
$00
$04
$04
$1C
$24
$24
$24
$00
$00
$10
$00
$18
$10
$10
$38
$00
$00
$10
$00
$18
$10
$10
$14
$08
$00
$04
$04
$14
$0C
$14
$24
$00
$00
$18
$10
$10
$10
$10
$38
$00
$00
$00
$2C
$54
$54
$54
$54
$00
$00
$00
$1C
$24
$24
$24
$24
$00
$00
$00
$18
$24
$24
$24
$18
$00
$00
$00
$1C
$24
$24
$1C
$04
$04
$00
$00
$1C
$12
$12
$1C
$10
$78
$00
$00
$34
$0C
$04
$04
$04
$00
$00
$00
$38
$04
$18
$20
$1C
$00
$00
$10
$38
$10
$10
$10
$20
$00
$00
$00
$24
$24
$24
$24
$38
$00
$00
$00
$44
$44
$44
$28
$10
$00
$00
$00
$44
$44
$54
$54
$28
$00
$00
$00
$44
$28
$10
$28
$44
$00
$00
$00
$24
$24
$24
$38
$20
$18
$00
$00
$3C
$20
$10
$08
$3C
$00
$00
$10
$08
$08
$04
$08
$08
$10
$00
$08
$08
$08
$08
$08
$08
$08
$00
$08
$10
$10
$20
$10
$10
$08
$00
$00
$00
$24
$1A
$00
$00
$00
$00
$00
$00
$00
$00
$00
$00
$00
$00
:END DATA2:
