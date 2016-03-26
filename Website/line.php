<?php
	$str = file_get_contents("input.txt");
  $arr = explode("\r\n",$str);  //không chạy thì đổi \n thành \r\n
  $N = count($arr);
  //$N = rand(0 , $N - 1);
	$line = $arr[$N - 2];
   echo $line;
?>