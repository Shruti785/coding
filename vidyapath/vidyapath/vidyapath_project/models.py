from django.db import models
from datetime import datetime
from django.db import models
# Create your models here.

class Registration(models.Model):
    name = models.CharField(max_length=100)
    batch = models.CharField(max_length=50)
    rollNo = models.CharField(max_length=20, unique=True)
    smartCardId = models.CharField(max_length=20, unique=True)
    email = models.EmailField(unique=True)
    password = models.CharField(max_length=100)

    def __str__(self):
        return self.name
    
class Notice(models.Model):
    description = models.TextField()  # Stores the notice content
    created_at=models.DateTimeField(default=datetime.now,blank=True)
    #created_at = models.DateTimeField(auto_now_add=True)  # Stores the time & date when the notice is created

    def __str__(self):
       # return f"Notice {self.id} - {self.created_at.strftime('%d-%m-%Y %H:%M')}"
       return self.description
    

class Company(models.Model):
    name = models.CharField(max_length=255)
    logo = models.ImageField(upload_to='company_logos/')  # Ensure MEDIA settings are correct

    def __str__(self):
        return self.name


class Placement(models.Model):
    student_name = models.CharField(max_length=255)
    company_name = models.CharField(max_length=255)
    year = models.IntegerField()
    package = models.DecimalField(max_digits=10, decimal_places=2)
    logo = models.ImageField(upload_to='company_logos/', blank=True, null=True)  # Store company logo images

    def __str__(self):
        return f"{self.student_name} - {self.company_name}"