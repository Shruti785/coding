# Generated by Django 5.1.5 on 2025-02-20 17:00

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('vidyapath_project', '0007_alter_company_logo'),
    ]

    operations = [
        migrations.AlterField(
            model_name='company',
            name='logo',
            field=models.ImageField(upload_to='company_logos/'),
        ),
    ]
