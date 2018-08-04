<?
  //This reverses and then swaps every other char
  function SwapOrder($in){
      $Split = str_split(strrev($in));
      $x='';
      for ($i = 0; $i < count($Split); $i+=2) {
          $x .= $Split[$i+1].$Split[$i];
      }
      return $x;
  }

  //makes the littleEndian
  function littleEndian($value){
      return implode (unpack('H*',pack("V*",$value)));
  }

  $version = littleEndian(2);
  $prevBlockHash = SwapOrder('000009f7e55e9e3b4781e22bd87a7cfa4acada9e4340d43ca738bf4e9fb8f5ce');
  $rootHash = SwapOrder('c550d56b453afd0a2f534658b06481a009372f263a9c7df2b306f232da7cf15d');
  $time = littleEndian(1415404959);
  $bits = littleEndian(507510783);
  $nonce = littleEndian(6645); 

  //concat it all
  $header_hex = $version . $prevBlockHash . $rootHash . $time . $bits . $nonce;

  //convert from hex to binary
  $header_bin  = hex2bin($header_hex);
  //hash it then convert from hex to binary
  $pass1 = hex2bin(  hash('sha256', $header_bin )  );
  //Hash it for the seconded time
  $pass2 = hash('sha256', $pass1);
  //fix the order
  $FinalHash = SwapOrder($pass2);

  echo   $FinalHash;
  echo   $header_hex;
?>

php >   echo   $FinalHash;
162f959ae175700fcbd14f736cbd29b4a722e67979ad44acfab788e1c892f448
php >   echo   $header_hex;
02000000cef5b89f4ebf38a73cd440439edaca4afa7c7ad82be281473b9e5ee5f70900005df17cda32f206b3f27d9c3a262f3709a08164b05846532f0afd3a456bd550c59f5d5d54ffff3f1ef5190000
