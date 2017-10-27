<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/22
 * Time: 11:08
 */
$path = '/var/www/data/users.txt';
printf("Filename:%s<br />",basename($path));
printf("Filename sans extension:%s<br/>",basename($path,".txt"));
//$pathinfo = pathinfo($path);
//foreach ($pathinfo as $v) {
//    echo $v;
//    echo "<br/>";
//}

//$bytes = filesize($path);
//$kilobyets = round($bytes/1024,2);
//printf("File %s is $bytes bytes, or %.2f kiobyets",basename($path),$kilobyets);

//$drive = '/usr';
//printf("Remaining MB on %s: % .2f",$drive,round((disk_free_space($drive)/1048576),2));


// $users = file('/var/www/data/users.txt');
//  foreach ($users as $user){
//      list($name,$email) = explode(' ',$user);
//      $email = tirm($email);
//      echo "<a href = \"mailto:$email\">$name</a>><br/> ";
//  }



//$fh = fopen($path,'r');
//while (!feof($fh))
//    echo fgets($sh);
//fclose($fh);

//$subscriberInfo = 'Jason Gilmore|jason@example.com';
//
//$fh = fopen('/var/www/data/subscribers.txt','a');
//
//fwrite($fh,$subscriberInfo);
//fclose($fh);

$dh = opendir('/var/www/html/');
while ($file = readdir($dh))
    echo "$file <br />";
closedir($dh);

