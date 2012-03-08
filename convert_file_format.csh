#!/bin/bash
cd FVC2002/Dbs/Db1_a/
#if [ "$t" != "" ]
#then
#   echo "There are no *.tif file in $(pwd) directory"
#   exit 1
#fi
#for i in `find -type f -iname "*.wsq"`
pwd
for i in `ls *.tif`
  do
    pgm_file=`echo $i | sed 's/.tif$//'`
  convert $i temp.raw
     echo $pgm_file
     cwsq 2.25 wsq temp.raw -r 388,374,8
     mindtct -b  -m1 temp.wsq $pgm_file
#   wc -l $i
 done

mv *.xyt ../../minutia
rm  *.brw *.dm *.hcm *.lcm *.lfm *.min *.qm *.wsq *.raw
cd ../../../


#for f in *.flac
#   do
#      OUTF=$(echo "$f" | sed s/\.flac$/.mp3/g)
#      ARTIST=$(${METAFLAC} "$f" --show-tag=ARTIST | sed s/.*=//g)
#      TITLE=$(${METAFLAC} "$f" --show-tag=TITLE | sed s/.*=//g)
#      ALBUM=$(${METAFLAC} "$f" --show-tag=ALBUM | sed s/.*=//g)
#      GENRE=$(${METAFLAC} "$f" --show-tag=GENRE | sed s/.*=//g)
#      TRACKNUMBER=$(${METAFLAC} "$f" --show-tag=TRACKNUMBER | sed s/.*=//g)
#      DATE=$(${METAFLAC} "$f" --show-tag=DATE | sed s/.*=//g)
#      $FLAC -c -d "$f" | $LAME -m j -q 0 --vbr-new -V 0 -s 44.1 - "$OUTF"
#      $ID3 -t "$TITLE" -T "${TRACKNUMBER:-0}" -a "$ARTIST" -A "$ALBUM" -y "$DATE" -g "${GENRE:-12}" "$OUTF"
#   done
