<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/18
 * Time: 12:27
 */
$link = mysqli_connect('localhost','root','')
    or die("Counld not connect : ".mysql_error());
$db_selected = mysqli_select_db("text",$link);

?>
