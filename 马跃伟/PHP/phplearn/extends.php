<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/20
 * Time: 15:45
 */
class Employee{
    private $name;

    function setName($name){
        if($name == "")echo "Name cannot be blanck";
        else $this->name= $name;
    }
    function getName(){
        return "My name is ".$this->name."<br/>";
    }
}

class Executive extends Employee{
    function  pillageCompany(){
        echo "I'm selling company assets to funance my yacht!";
    }
}

$exec = new Executive();
$exec->setName("Richard");
echo $exec->getName();
$exec->pillageCompany();