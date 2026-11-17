
#include "Spielfeld.h"
#include "Spieler.h"
#include "Eingabe.h"
#include <cassert>
#include <iostream>
int main() {
 Spielfeld b;
 assert(b.getReihen()==6 && b.getSpalten()==7);
 assert(!b.einwerfen(-1,'X') && !b.einwerfen(7,'X'));
 for(int i=0;i<6;i++) assert(b.einwerfen(0,i%2?'O':'X'));
 assert(!b.einwerfen(0,'O'));
 b.leeren(); for(int i=0;i<4;i++) b.einwerfen(i,'X'); assert(b.gewonnen('X'));
 { int r[4], sp[4]; assert(b.gewinnPositionen('X',r,sp));
   for(int i=0;i<4;i++) assert(r[i]==5 && sp[i]==i); }
 b.leeren(); for(int i=0;i<4;i++) b.einwerfen(6,'O'); assert(b.gewonnen('O'));
 for(int spiegel=0;spiegel<2;spiegel++) {
  b.leeren();
  for(int i=0;i<4;i++) { int s=spiegel?6-i:i;
   for(int j=0;j<i;j++) { b.einwerfen(s,'O'); } b.einwerfen(s,'X'); }
  assert(b.gewonnen('X'));
 }
 b.leeren(); b.einwerfen(0,'X'); b.einwerfen(1,'X'); b.einwerfen(3,'X'); b.einwerfen(4,'X');
 assert(!b.gewonnen('X')); assert(!b.gewonnen('.')); assert(!b.voll());
 b.leeren();
 for(int r=0;r<6;r++) for(int s=0;s<7;s++) b.einwerfen(s, ((s/2+r)%2)?'X':'O');
 assert(b.voll() && !b.gewonnen('X') && !b.gewonnen('O'));
 assert(!nameGueltig("") && !nameGueltig("   ") && !nameGueltig(" Daniel") && nameGueltig("Daniel Mustermann"));
 Spieler p; p.setzen("Test",'O'); assert(p.getSymbol()=='O');
 b.leeren(3); assert(b.getReihen()==8 && b.getSpalten()==9); b.leeren(4); assert(b.getReihen()==10 && b.getSpalten()==11);
 std::cout << "Board-, Namen- und Spielertests bestanden.\n";
}
